#include "WorldView.h"
using namespace std;


inline qreal round(qreal val, int step) {
   int tmp = int(val) + step /2;
   tmp -= tmp % step;
   return qreal(tmp);
}


WorldView::WorldView(World *world, QWidget *parent) :
    QGraphicsView(parent)
{
    m_dScale = 32.0;
    m_iScheduledScalings = 0;
    for(unsigned int i = 0; i < 1; ++i)
        m_GrassImage.push_back(QPixmap("texture/grass" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 1; ++i)
        m_TreeImage.push_back(QPixmap("texture/tree" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 1; ++i)
        m_GoldImage.push_back(QPixmap("texture/gold" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 1; ++i)
        m_FoodImage.push_back(QPixmap("texture/food" + QString::number(i) + ".png"));

    this->m_World = world;
    this->m_WorldScene = new QGraphicsScene(this);
    this->setScene(m_WorldScene);

    setRenderHint(QPainter::Antialiasing, true);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setResizeAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
}


void WorldView::update(void)
{
    // Reset objects
    m_WorldScene->clear();

	Graph * map = m_World->getGraph();

    list<Node *> nodes = map->nodes();
    for(auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        Node *node = *it;
        double x = node->x();
        double y = node->y();
		m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10);
    }

	list<Edge *> edges = map->edges();
	for(auto it = edges.begin(); it != edges.end(); ++it)
    {
        Edge	* edge = *it;
		Node	* from = edge->from(),
				*	to = edge->to();

        double	x1 = from->x(),
				y1 = from->y(),
				x2 = to->x(),
				y2 = to->y();

		m_WorldScene->addLine(x1 * m_dScale, y1 * m_dScale, x2 * m_dScale, y2 * m_dScale);
    }
}


//void WorldView::update(void)
//{
//    // Reset objects
//    m_WorldScene->clear();
//
//    list<Node *> nodes = m_World->nodes();
//    for(auto it = nodes.begin(); it != nodes.end(); ++it)
//    {
//        Node *node = *it;
//        double x = node->x();
//        double y = node->y();
//        QGraphicsPixmapItem *item = m_WorldScene->addPixmap(randomTexture(m_GrassImage));
//        item->setPos(x*m_dScale,y*m_dScale);
//    }
//
//    list<PassiveEntity *> passiveEntities = m_World->passiveEntities();
//    for(auto it = passiveEntities.begin(); it != passiveEntities.end(); ++it)
//    {
//        PassiveEntity *entity = *it;
//        double x = entity->x();
//        double y = entity->y();
//        QGraphicsPixmapItem *item;
//        switch(entity->type())
//        {
//        case PassiveEntityType::ressource:
//            switch(((Ressource *) entity)->ressourceType())
//            {
//            case RessourceType::wood:
//                item = m_WorldScene->addPixmap(this->randomTexture(m_TreeImage));
//                item->setPos(x*m_dScale,y*m_dScale);
//                break;
//            case RessourceType::gold:
//                item = m_WorldScene->addPixmap(this->randomTexture(m_GoldImage));
//                item->setPos(x*m_dScale,y*m_dScale);
//                break;
//            case RessourceType::food:
//                item = m_WorldScene->addPixmap(this->randomTexture(m_FoodImage));
//                item->setPos(x*m_dScale,y*m_dScale);
//                break;
//            default:
//                break;
//            }
//            break;
//        default:
//            break;
//        }
//    }
//
//    //list<PassiveEntity *> activeEntities = m_World->activeEntities(void);
//}


QPixmap WorldView::randomTexture(std::vector<QPixmap> textures)
{
    return textures[rand() % textures.size()];
}

void WorldView::wheelEvent(QWheelEvent* event)
{
    int speed = 8;
    int numDegrees = event->delta() / speed;
    int numSteps = numDegrees / 15;
    m_iScheduledScalings += numSteps;
    if (m_iScheduledScalings * numSteps < 0)
       m_iScheduledScalings = numSteps;

    QTimeLine *anim = new QTimeLine(350, this);
    anim->setUpdateInterval(20);

    connect(anim, SIGNAL(valueChanged(qreal)), SLOT(scalingTime(qreal)));
    connect(anim, SIGNAL(finished()), SLOT(animFinished()));
    anim->start();
}
void WorldView::scalingTime(qreal) {
    qreal factor = 1.0 + qreal(m_iScheduledScalings) / 200.0;
    scale(factor, factor);
}
void WorldView::animFinished() {
    if (m_iScheduledScalings > 0)
        m_iScheduledScalings--;
    else
        m_iScheduledScalings++;
    sender()->~QObject();
}


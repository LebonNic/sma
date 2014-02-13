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

	m_BuildingImage.push_back(QPixmap("texture/building" + QString::number(0) + ".png"));
	m_UnitImage.push_back(QPixmap("texture/unit" + QString::number(0) + ".png"));

    this->m_World = world;
    this->m_WorldScene = new QGraphicsScene(this);
    this->setScene(m_WorldScene);

    setRenderHint(QPainter::Antialiasing, true);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setResizeAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
}


//void WorldView::update(void)
//{
//    // Reset objects
//	std::vector<std::vector<Node *>> nodes;
//	std::list<Node *> path;
//	std::vector<Score *>	openSet,
//							closedSet;
//
//	QBrush	path_brush(QColor(255, 0, 0), Qt::SolidPattern),
//			closedSet_brush(QColor(0, 255, 0), Qt::SolidPattern),
//			openSet_brush(QColor(0, 0, 255), Qt::SolidPattern);
//
//    m_WorldScene->clear();
//
//	Graph map = m_World->getMap();
//
//    nodes = map.nodes();
//
//	/*for(int i=10; i<20; ++i)
//		(*map)(5, i)->setReachable(false);
//
//	for(int i=10; i<20; ++i)
//		(*map)(20, i)->setReachable(false);
//
//	for(int i=5; i<21; ++i)
//		(*map)(i, 20)->setReachable(false);*/
//
//	for(unsigned int i = 0; i < map.size(); ++i)
//	{
//		for(unsigned int j = 0; j < map.size(); ++j)
//		{
//			Node *node = nodes[i][j];
//			double x = node->x();
//			double y = node->y();
//			if(node->isReachable())
//				m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10);
//			else
//				m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10, Qt::SolidLine, Qt::SolidPattern);
//		}
//	}
//
//	Node	* startingNode = (map)(30,30),
//			* goal = (map)(35, 35);
//
//	path = map.findPathFromTo(startingNode, goal);
//	closedSet = map.getPathFinder().getClosedSet();
//	openSet = map.getPathFinder().getOpenSet();
//
//	/*for(auto ite = openSet.begin(); ite != openSet.end(); ++ite)
//	{
//		double x = (*ite)->m_N->x();
//		double y = (*ite)->m_N->y();
//		m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10, Qt::SolidLine, openSet_brush);
//	}*/
//	
//	for(auto ite = closedSet.begin(); ite != closedSet.end(); ++ite)
//	{
//		double x = (*ite)->m_N->x();
//		double y = (*ite)->m_N->y();
//		m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10, Qt::SolidLine, closedSet_brush);
//	}
//
//	for(auto ite = path.begin(); ite != path.end(); ++ite)
//	{
//		double x = (*ite)->x();
//		double y = (*ite)->y();
//		m_WorldScene->addEllipse(x * m_dScale - 5, y * m_dScale - 5,10,10,Qt::SolidLine, path_brush);
//	}
//
//	m_WorldScene->addEllipse(startingNode->x() * m_dScale - 5, startingNode->y() * m_dScale - 5,10,10,Qt::SolidLine, path_brush);
//	m_WorldScene->addEllipse(goal->x() * m_dScale - 5, goal->y() * m_dScale - 5,10,10,Qt::SolidLine, path_brush);
//
//	/*list<Edge *> edges = map->edges();
//	for(auto it = edges.begin(); it != edges.end(); ++it)
//    {
//        Edge	* edge = *it;
//		Node	* from = edge->from(),
//				*	to = edge->to();
//
//        double	x1 = from->x(),
//				y1 = from->y(),
//				x2 = to->x(),
//				y2 = to->y();
//
//		m_WorldScene->addLine(x1 * m_dScale, y1 * m_dScale, x2 * m_dScale, y2 * m_dScale);
//    }*/
//}


void WorldView::update(void)
{
    // Reset objects
    m_WorldScene->clear();

	std::vector<std::vector<Node *>> nodes = m_World->getMap().nodes();
    for(auto vec = nodes.begin(); vec != nodes.end(); ++vec)
    {
		for(auto node = (*vec).begin(); node !=(*vec).end(); ++node)
		{
			double x = (*node)->x();
			double y = (*node)->y();
			QGraphicsPixmapItem *item = m_WorldScene->addPixmap(randomTexture(m_GrassImage));
			item->setPos(x*m_dScale,y*m_dScale);
		}
    }

	std::vector<std::vector<Ressource *>> ressources = m_World->getRessourcesMap();
    for(auto vec = ressources.begin(); vec != ressources.end(); ++vec)
    {
		for(auto ress = (*vec).begin(); ress != (*vec).end(); ++ress)
		{
			if((*ress))
			{
				double x = (*ress)->x();
				double y = (*ress)->y();
				QGraphicsPixmapItem *item;
				switch((*ress)->ressourceType())
				{
				case RessourceType::wood:
					item = m_WorldScene->addPixmap(this->randomTexture(m_TreeImage));
					item->setPos(x*m_dScale,y*m_dScale);
					break;

				case RessourceType::gold:
					item = m_WorldScene->addPixmap(this->randomTexture(m_GoldImage));
					item->setPos(x*m_dScale,y*m_dScale);
					break;

				case RessourceType::food:
					item = m_WorldScene->addPixmap(this->randomTexture(m_FoodImage));
					item->setPos(x*m_dScale,y*m_dScale);
					break;

				default:
					break;
				}
			}
		}
	}

	std::list<Civilization *> civilizations = m_World->getCivilizations();
	for(auto civi = civilizations.begin(); civi != civilizations.end(); ++civi)
	{
		std::list<Unit *> units = (*civi)->getUnits();
		std::list<Building *> buildings = (*civi)->getBuildings();

		for(auto uni = units.begin(); uni != units.end(); ++uni)
		{
			double x = (*uni)->x();
			double y = (*uni)->y();
			QGraphicsPixmapItem * item = m_WorldScene->addPixmap(m_UnitImage.front());
			item->setPos(x*m_dScale, y*m_dScale);
		}

		for(auto bui = buildings.begin(); bui != buildings.end(); ++bui)
		{
			double x = (*bui)->x();
			double y = (*bui)->y();
			QGraphicsPixmapItem * item = m_WorldScene->addPixmap(m_BuildingImage.front());
			item->setPos(x*m_dScale, y*m_dScale);
		}
	}
}


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


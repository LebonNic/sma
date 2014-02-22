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
    m_dScale = 64.0;
    m_iScheduledScalings = 0;

    // Load textures
    for(unsigned int i = 0; i < 1; ++i)
        m_GrassImage.push_back(QPixmap("texture/grass" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 6; ++i)
        m_TreeImage.push_back(QPixmap("texture/tree" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 3; ++i)
        m_GoldImage.push_back(QPixmap("texture/rock" + QString::number(i) + ".png"));
    for(unsigned int i = 0; i < 4; ++i)
        m_FoodImage.push_back(QPixmap("texture/food" + QString::number(i) + ".png"));

    m_TiledGrassImage.push_back(QPixmap("texture/tilledGrass" + QString::number(0) + ".png"));
	m_BuildingImage.push_back(QPixmap("texture/building" + QString::number(0) + ".png"));
    for(unsigned int i = 0; i < 12; ++i)
        m_UnitImage.push_back(QPixmap("texture/unit" + QString::number(i) + ".png"));
	

    this->m_World = world;
    this->m_WorldScene = new QGraphicsScene(this);
    this->setScene(m_WorldScene);

    setRenderHint(QPainter::Antialiasing, true);
    setDragMode(ScrollHandDrag);
}

void WorldView::update(void)
{
    // Reset objects
    m_WorldScene->clear();
    unsigned int worldSize = m_World->getSize();

    for(unsigned int i = 0; i < worldSize; ++i)
    {
		for(unsigned int j = 0; j < worldSize; ++j)
        {
            QGraphicsPixmapItem * item = m_WorldScene->addPixmap(this->randomTexture(m_GrassImage, i * worldSize + j));
			item->setPos(i*m_dScale,j*m_dScale);
        }
    }

	std::list<Civilization *> civilizations = m_World->getCivilizations();
	for(auto civi = civilizations.begin(); civi != civilizations.end(); ++civi)
	{
		std::list<Unit *> units = (*civi)->getUnits();
		std::list<Building *> buildings = (*civi)->getBuildings();
		const Memory & mem = (*civi)->getMemory();
		const std::vector<std::vector<bool>> & foodMap = mem.getFoodMap();
		const std::vector<std::vector<bool>> & woodMap = mem.getWoodMap();
		const std::vector<std::vector<bool>> & goldMap = mem.getGoldMap();

        #pragma region Tree
        for(unsigned int i = 0; i < worldSize; ++i)
		{
            for(unsigned int j = 0; j < worldSize; ++j)
			{
                if (woodMap[i][j])
                {
                    bool north = false;
                    bool south = false;
                    bool west = false;
                    bool east = false;

                    if (j == 0)
                        north = true;
                    else if (woodMap[i][j-1])
                        north = true;

                    if (j == worldSize - 1)
                        south = true;
                    else if (woodMap[i][j+1])
                        south = true;

                    if (i == 0)
                        west = true;
                    else if (woodMap[i-1][j])
                        west = true;

                    if (i == worldSize - 1)
                        east = true;
                    else if (woodMap[i+1][j])
                        east = true;

                    QGraphicsPixmapItem *item = NULL;
                    if (north && south && east && west)
                    {
                        item = m_WorldScene->addPixmap(m_TreeImage[0]);
                        item->setPos((i) * m_dScale, (j) * m_dScale);
                    }
                    else
                    {
                        if (north)
                        {
                            item = m_WorldScene->addPixmap(m_TreeImage[2]);
                            item->setPos((i) * m_dScale, (j) * m_dScale);
                        }
                        if (west)
                        {
                            item = m_WorldScene->addPixmap(m_TreeImage[4]);
                            item->setPos((i) * m_dScale, (j) * m_dScale);
                        }

                        if (south)
                        {
                            item = m_WorldScene->addPixmap(m_TreeImage[5]);
                            item->setPos((i) * m_dScale, (j) * m_dScale);
                        }
                        if (east)
                        {
                            item = m_WorldScene->addPixmap(m_TreeImage[3]);
                            item->setPos((i) * m_dScale, (j) * m_dScale);
                        }
                    }
                }
			}
		}
        #pragma endregion

        #pragma region Gold
        for(unsigned int i = 0; i < worldSize; ++i)
		{
            for(unsigned int j = 0; j < worldSize; ++j)
			{
                if (goldMap[i][j])
                {
                    QGraphicsPixmapItem *item = m_WorldScene->addPixmap(this->randomTexture(m_GoldImage, i * worldSize + j));
					item->setPos((i) * m_dScale, (j) * m_dScale);
                }
			}
		}
        #pragma endregion

        #pragma region Food
		for(unsigned int i = 0; i < worldSize; ++i)
		{
            for(unsigned int j = 0; j < worldSize; ++j)
			{
                if (foodMap[i][j])
                {
                    MersenneTwister ms(j + i * worldSize);
                    double dx = (double) ms.genrand_real1() / 2.0;
                    double dy = (double) ms.genrand_real1() / 2.0;
                    QGraphicsPixmapItem *item = m_WorldScene->addPixmap(this->randomTexture(m_FoodImage, i * worldSize + j));
					item->setPos((i + dx) * m_dScale, (j + dy) * m_dScale);
                }
			}
		}
        #pragma endregion

		for(auto uni = units.begin(); uni != units.end(); ++uni)
		{
            Unit *unit = *uni;
			double x = unit->x();
			double y = unit->y();
            QGraphicsPixmapItem *item = NULL;
            Orientation orientation = unit->getOrientation();
            switch (orientation)
            {
            case NORTH:
                item = m_WorldScene->addPixmap(m_UnitImage[10]);
                break;
            case SOUTH:
                item = m_WorldScene->addPixmap(m_UnitImage[1]);
                break;
            case WEST:
                item = m_WorldScene->addPixmap(m_UnitImage[4]);
                break;
            case EAST:
                item = m_WorldScene->addPixmap(m_UnitImage[7]);
                break;
            default:
                item = m_WorldScene->addPixmap(m_UnitImage[1]);
                break;
            }
			 
            
			item->setPos((x+0.25)*m_dScale, (y+0.25)*m_dScale);
		}

		for(auto bui = buildings.begin(); bui != buildings.end(); ++bui)
		{
			double x = (*bui)->x();
			double y = (*bui)->y();
			QGraphicsPixmapItem *item = m_WorldScene->addPixmap(m_BuildingImage.front());
			item->setPos(x*m_dScale, y*m_dScale);
		}
	}

	QString info = civilizationsInfoToString();
	m_WorldScene->addSimpleText(info);
}


QPixmap WorldView::randomTexture(const std::vector<QPixmap> &textures, unsigned int index)
{
    srand(index);
    return textures[rand() % textures.size()];
}

QString WorldView::civilizationsInfoToString() const
{
	QString info;
	for(auto civi = m_World->getCivilizations().begin(); civi != m_World->getCivilizations().end(); ++civi)
	{
		info.append("Civilization[");
		info.append(QString::number((*civi)->id()));
		info.append("]\n");

		info.append("Food : ");
		info.append(QString::number((*civi)->getFoodStock(), 'g', 6));
		info.append("\n");

		info.append("Wood : ");
		info.append(QString::number((*civi)->getWoodStock(), 'g', 6));
		info.append("\n");

		info.append("Gold : ");
		info.append(QString::number((*civi)->getGoldStock(), 'g', 6));
		info.append("\n");

		info.append("Total units count : ");
		info.append(QString::number((*civi)->getUnits().size(), 'g', 6));
		info.append("\n");

		info.append("Free units count : ");
		info.append(QString::number((*civi)->getFreeUnitsList().size(), 'g', 6));
		info.append("\n");

		info.append("Food gatherer units count : ");
		info.append(QString::number((*civi)->getFoodGatherersList().size(), 'g', 6));
		info.append("\n");

		info.append("Gold gatherer units count : ");
		info.append(QString::number((*civi)->getMinersList().size(), 'g', 6));
		info.append("\n");

		info.append("Wood gatherer units count : ");
		info.append(QString::number((*civi)->getLumberjacksList().size(), 'g', 6));
		info.append("\n");

		info.append("Builder units count : ");
		info.append(QString::number((*civi)->getBuildersList().size(), 'g', 6));
		info.append("\n");
	}

	return info;
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


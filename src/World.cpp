#include "World.h"
using namespace std;


World::World(unsigned int size, double scale, unsigned int seed)
	: ActiveEntity(Location(0, 0, 0), new WorldBehaviour(this))
{
	m_uSize = size;
	m_Map = new Graph();
	m_Map->generateRandomPerlin(size, scale, seed);

	m_RessourcesMap = std::vector<vector<Ressource * >>(size);
	for(auto vec = m_RessourcesMap.begin(); vec != m_RessourcesMap.end(); ++vec)
	{
		(*vec) = std::vector<Ressource * >(size);
		std::fill((*vec).begin(), (*vec).end(), (Ressource *)(NULL));
	}

	m_UnitsMap = std::vector<vector<Unit * >>(size);
	for(auto vec = m_UnitsMap.begin(); vec != m_UnitsMap.end(); ++vec)
	{
		(*vec) = std::vector<Unit * >(size);
		std::fill((*vec).begin(), (*vec).end(), (Unit *)(NULL));
	}

	m_BuildingsMap = std::vector<vector<Building * >>(size);
	for(auto vec = m_BuildingsMap.begin(); vec != m_BuildingsMap.end(); ++vec)
	{
		(*vec) = std::vector<Building * >(size);
		std::fill((*vec).begin(), (*vec).end(), (Building *)(NULL));
	}
}

World::~World(void)
{
	delete m_Map;
	for(auto it = m_Civilization.begin(); it != m_Civilization.end(); ++it)
	{
		delete (*it);
	}

	for(unsigned int i = 0; i < m_RessourcesMap.size(); ++i)
		for(unsigned int j = 0; j < m_RessourcesMap[i].size(); ++j)
			delete m_RessourcesMap[i][j];
}

void World::populateMap(double goldDensity, double woodDensity, double foodDensity)
{
	std::vector<std::vector<Node *>> nodes = m_Map->nodes();
	PerlinNoise woodNoise(rand());
	PerlinNoise goldNoise(rand());
	PerlinNoise foodNoise(rand());

	for(unsigned int i = 0; i < m_Map->size(); ++ i)
	{
		for(unsigned int j = 0; j < m_Map->size(); ++j)
		{
			double x = nodes[i][j]->x();
			double y = nodes[i][j]->y();
			double goldScale = 0.05;
			double woodScale = 0.05;
			double foodScale = 0.05;
			double ng = goldNoise.noise(x*goldScale, y*goldScale, 0.5);
			double nw = woodNoise.noise(x*woodScale, y*woodScale, 0.5);
			double nf = foodNoise.noise(x*foodScale, y*foodScale, 0.5);

			if (ng >= 0.5 && ng < 0.5 + goldDensity)
			{
				Ressource *ressource = new Ressource(RessourceType::gold, x, y, nodes[i][j]->z(), 500, this);
				m_RessourcesMap[x][y] = ressource;
			}
			if (nw >= 0.5 && nw < 0.5 + woodDensity)
			{
				Ressource *ressource = new Ressource(RessourceType::wood, x, y, nodes[i][j]->z(), 500, this);
				m_Map->addObstacle(x,y);
				m_RessourcesMap[x][y] = ressource;
			}
			if (nf >= 0.5 && nf < 0.5 + foodDensity)
			{
				Ressource *ressource = new Ressource(RessourceType::food, x, y, nodes[i][j]->z(), 500, this);
				m_RessourcesMap[x][y] = ressource;
			}
		}
	}
}

void World::run()
{
	ActiveEntity::run();
}

const std::vector<std::vector<Ressource *>> & World::getRessourcesMap(void) const
{
	return m_RessourcesMap;
}

const Graph & World::getMap(void) const
{
	return (*m_Map);
}

Graph & World::getMap(void)
{
	return (*m_Map);
}

const int & World::getSize() const
{
	return m_uSize;
}

//void World::refresh(void)
//{
//	Ressource *ressource = (Ressource *) m_PassiveEntities.front();
//	m_PassiveEntities.erase(m_PassiveEntities.begin());
//	ressource->consume(100.0);
//	this->display();
//}

void World::display(void)
{

}

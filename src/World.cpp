#include "World.h"
using namespace std;


World::World(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed)
{
	m_Map = new Graph();
	setWaterLevel(0.25);
	m_Map->generateRandomPerlin(xSize, ySize, scale, seed);
}
World::~World(void)
{
	delete m_Map;
	for(auto it = m_ActiveEntities.begin(); it != m_ActiveEntities.end(); ++it)
	{
		delete (*it);
	}
	for(auto it = m_PassiveEntities.begin(); it != m_PassiveEntities.end(); ++it)
	{
		delete (*it);
	}
}


void World::setWaterLevel(double waterLevel)
{
	m_dWaterLevel = waterLevel;
}


void World::addPassiveEntity(PassiveEntity *entity)
{
	m_PassiveEntities.push_back(entity);
}
void World::addActiveEntity(ActiveEntity *entity)
{
	m_ActiveEntities.push_back(entity);
}


list<Node *> World::nodes(void)
{
    return m_Map->nodes();
}
list<PassiveEntity *> World::passiveEntities(void)
{
    return m_PassiveEntities;
}


void World::populateMap(double goldDensity, double woodDensity, double foodDensity)
{
	list<Node *> nodes = m_Map->nodes();
	PerlinNoise woodNoise(rand());
	PerlinNoise goldNoise(rand());
	PerlinNoise foodNoise(rand());

	for (auto it = nodes.begin(); it != nodes.end(); ++it)
	{
		double x = (*it)->x();
		double y = (*it)->y();
        double goldScale = 0.05;
		double woodScale = 0.05;
        double foodScale = 0.05;
		double ng = goldNoise.noise(x*goldScale, y*goldScale, 0.5);
		double nw = woodNoise.noise(x*woodScale, y*woodScale, 0.5);
		double nf = foodNoise.noise(x*foodScale, y*foodScale, 0.5);
		if (ng >= 0.5 && ng < 0.5 + goldDensity)
		{
			Ressource *ressource = new Ressource(RessourceType::gold, x, y, (*it)->z());
			this->addPassiveEntity(ressource);
		}
		if (nw >= 0.5 && nw < 0.5 + woodDensity)
		{
			Ressource *ressource = new Ressource(RessourceType::wood, x, y, (*it)->z());
			this->addPassiveEntity(ressource);
		}
		if (nf >= 0.5 && nf < 0.5 + foodDensity)
		{
			Ressource *ressource = new Ressource(RessourceType::food, x, y, (*it)->z());
			this->addPassiveEntity(ressource);
		}
	}
}


void World::refresh(void)
{
	Ressource *ressource = (Ressource *) m_PassiveEntities.front();
	m_PassiveEntities.erase(m_PassiveEntities.begin());
	ressource->consume(100.0);
	this->display();
}
void World::display(void)
{

}

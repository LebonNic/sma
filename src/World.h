#pragma once

#include <vector>
#include "ActiveEntity.h"
#include "PassiveEntity.h"
#include "Ressource.h"
#include "Graph.h"

class World
{
private:
    std::list<ActiveEntity *> m_ActiveEntities;
    std::list<PassiveEntity *> m_PassiveEntities;
	Graph *m_Map;
	double m_dWaterLevel;

	
	void setWaterLevel(double waterLevel);
public:
	World(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed);
	~World(void);


	void addPassiveEntity(PassiveEntity *entity);
	void addActiveEntity(ActiveEntity *entity);


    std::list<Node *> nodes(void);
    std::list<PassiveEntity *> World::passiveEntities(void);
	Graph * getGraph(void);

	void populateMap(double goldDensity, double woodDensity, double foodDensity);

	void refresh(void);
	void display(void);
};


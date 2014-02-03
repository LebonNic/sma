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
	World(unsigned int size, double scale, unsigned int seed);
	~World(void);


	void addPassiveEntity(PassiveEntity *entity);
	void addActiveEntity(ActiveEntity *entity);


    std::vector<std::vector<Node *>> nodes(void);
    std::list<PassiveEntity *> passiveEntities(void);
	Graph * getGraph(void);

	void populateMap(double goldDensity, double woodDensity, double foodDensity);

	Graph * getMap(void);

	void refresh(void);
	void display(void);
};


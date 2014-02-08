#pragma once

#include <vector>
#include "ActiveEntity.h"
#include "PassiveEntity.h"
#include "Ressource.h"
#include "Graph.h"
#include "WorldBehaviour.h"

class World : public ActiveEntity
{
private:
    std::list<ActiveEntity *> m_ActiveEntities;
    std::list<PassiveEntity *> m_PassiveEntities;
	Graph * m_Map;

public:
	World(unsigned int size, double scale, unsigned int seed);
	~World(void);


	void addPassiveEntity(PassiveEntity *entity);
	void addActiveEntity(ActiveEntity *entity);


    std::vector<std::vector<Node *>> nodes(void);
    std::list<PassiveEntity *> passiveEntities(void);
	Graph * getGraph(void);

	void populateMap(double goldDensity, double woodDensity, double foodDensity);
	void run();

	Graph * getMap(void);

	void refresh(void);
	void display(void);
};


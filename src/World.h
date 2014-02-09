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
	std::vector<std::vector<Ressource *>> m_RessourcesMap;
	Graph * m_Map;

public:
	World(unsigned int size, double scale, unsigned int seed);
	~World(void);
	
	void addActiveEntity(ActiveEntity *entity);
	void populateMap(double goldDensity, double woodDensity, double foodDensity);
	void run();

	const std::vector<std::vector<Ressource *>> & getRessourcesMap(void) const;
	Graph * getMap(void) const;
	/*void refresh(void);*/
	void display(void);
};


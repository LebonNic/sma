#pragma once

#include <vector>
#include "ActiveEntity.h"
#include "PassiveEntity.h"
#include "Graph.h"

enum EntityDisplayChar
{
	empty = ' ',
	activeEntity = 'A',
	passiveEntity = 'P',
	bothEntities = '#'
};

class World :
	public ActiveEntity
{
private:
	std::vector<ActiveEntity *> m_ActiveEntities;
	std::vector<PassiveEntity *> m_PassiveEntities;
	Graph *m_Map;

public:
	World(double xSize, double ySize, double scale, unsigned int seed);
	~World(void);


	void addPassiveEntity(PassiveEntity *entity);
	void addActiveEntity(ActiveEntity *entity);


	std::vector<std::vector<EntityDisplayChar>> World::entityMap(void);
	void display(void);
};


#pragma once

#include <vector>
#include "ActiveEntity.h"
#include "PassiveEntity.h"
#include "Ressource.h"
#include "Graph.h"

enum EntityDisplayChar
{
	empty = ' ',
	activeEntity = 'A',
	passiveEntity = 'P',
	ressourceWood = 'W',
	ressourceGold = 'G',
	ressourceFood = 'F',
	multipleEntities = '#'
};

class World :
	public ActiveEntity
{
private:
	std::vector<ActiveEntity *> m_ActiveEntities;
	std::vector<PassiveEntity *> m_PassiveEntities;
	Graph *m_Map;

public:
	World(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed);
	~World(void);


	void addPassiveEntity(PassiveEntity *entity);
	void addActiveEntity(ActiveEntity *entity);


	void populateMap(double goldDensity, double woodDensity, double foodDensity);


	std::vector<std::vector<EntityDisplayChar>> World::entityMap(void);
	void display(void);
};


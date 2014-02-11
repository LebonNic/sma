#pragma once

#include <vector>

#include "ActiveEntity.h"
#include "Ressource.h"
#include "Graph.h"
#include "WorldBehaviour.h"
#include "Civilization.h"
#include "Unit.h"
#include "Building.h"

class Civilization;
class Ressource;
class Building;
class Unit;

class World : public ActiveEntity
{
private:
    std::list<Civilization *> m_Civilization;
	std::vector<std::vector<Ressource *>> m_RessourcesMap;
	std::vector<std::vector<Unit *>> m_UnitsMap;
	std::vector<std::vector<Building *>> m_BuildingsMap;
	Graph * m_Map;

public:
	World(unsigned int size, double scale, unsigned int seed);
	~World(void);
	
	
	void populateMap(double goldDensity, double woodDensity, double foodDensity);
	void run();

	const std::vector<std::vector<Ressource *>> & getRessourcesMap(void) const;

	Graph & getMap(void);
	const Graph & getMap(void) const;

	void display(void);
};


#ifndef CIVILIZATION_H
#define CIVILIZATION_H

#include <list>

#include "ActiveEntity.h"
#include "World.h"
#include "Memory.h"
#include "Behaviour.h"
#include "Unit.h"
#include "CivilizationBehaviour.h"

class World;
class Unit;
class Building;

class Civilization : public ActiveEntity
{
private:


	Memory * m_Memory;
	World * m_World;

	std::list<Unit *> m_Units;
	std::list<Unit *> m_FreeUnits;
	std::list<Unit *> m_Lumberjacks; 
	std::list<Unit *> m_FoodGatherers;
	std::list<Unit *> m_Miners;
	std::list<Unit *> m_Builders;
	std::list<Building *> m_Buildings;
	
	double m_dWoodStock;
	double m_dFoodStock;
	double m_dGoldStock;

public:
	Civilization(double x, double y, double z, World * world);
	virtual ~Civilization();

	static const double m_dBuildingWoodCost;
	static const double m_dBuildingFoodCost;
	static const double m_dBuildingGoldCost;

	const Memory & getMemory() const;
	void run();

	double getGoldStock(void);
	double getFoodStock(void);
	double getWoodStock(void);
	const std::list<Unit *> & getUnits(void) const;
	const std::list<Building *> & getBuildings(void) const;

	const World & getWorld() const;
	World & getWorld();

	//Interfaces used by the units
	void locateFood(const Location & l);
	void locateGold(const Location & l);
	void locateWood(const Location & l);
	void locateEmptinessSpace(const Location & l);
	void locateDiscoveredArea(const Location & l);

	void increaseFoodStockFromRessource(const Location & ressourceLocation, double quantity);
	void increaseGoldStockFromRessource(const Location & ressourceLocation, double quantity);
	void increaseWoodStockFromRessource(const Location & ressourceLocation, double quantity);

	void createBuilding(const Location & emplacement);

	//Interfaces used by the civilization's behaviours
	const std::list<Unit *> & getFreeUnitsList() const;
	std::list<Unit *> & getFreeUnitsList();

	const std::list<Unit *> & getLumberjacksList() const;
	std::list<Unit *> & getLumberjacksList();

	const std::list<Unit *> & getBuildersList() const;
	std::list<Unit *> & getBuildersList();

	const std::list<Unit *> & getFoodGatherersList() const;
	std::list<Unit *> & getFoodGatherersList();

	const std::list<Unit *> & getMinersList() const;
	std::list<Unit *> & getMinersList();

	std::list<Unit *> & getRichestList();

	void consumeRessource(RessourceType ressourceType, double quantity);
};

#endif
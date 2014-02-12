#ifndef CIVILIZATION_H
#define CIVILIZATION_H

#include <list>

#include "ActiveEntity.h"
#include "World.h"
#include "Memory.h"
#include "Behaviour.h"
#include "Unit.h"

class World;
class Unit;
class Building;

class Civilization : public ActiveEntity
{
private:
	Memory * m_Memory;
	World * m_World;

	std::list<Unit *> m_FreeUnits;
	std::list<Unit *> m_Lumberjacks; 
	std::list<Unit *> m_Gatherers;
	std::list<Unit *> m_Miners;
	std::list<Unit *> m_Soldiers;
	std::list<Unit *> m_Buildings;
	
	double m_dWoodStock;
	double m_dFoodStock;
	double m_dGoldStock;

public:
	Civilization(double x, double y, double z, Behaviour * behaviour, World * world);
	virtual ~Civilization();

	const Memory & getMemory() const;
	void run();

	double getGoldStock(void);
	double getFoodStock(void);
	double getWoodStock(void);

	const World & getWorld() const;

	void locateFood(const Location & l);
	void locateGold(const Location & l);
	void locateWood(const Location & l);
	void locateEmptinessSpace(const Location & l);
};

#endif
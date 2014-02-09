#ifndef CIVILIZATION_H
#define CIVILIZATION_H

#include <list>

#include "ActiveEntity.h"
#include "World.h"
#include "Memory.h"
#include "Behaviour.h"
#include "Agent.h"

class World;
class Agent;

class Civilization : public ActiveEntity
{
private:
	Memory * m_Memory;
	World * m_World;

	std::list<Agent *> m_FreeUnits;		//De type "Agent" car problème d'inclusion croisée si je passe en "Unit"
	std::list<Agent *> m_Lumberjacks; 
	std::list<Agent *> m_Gatherers;
	std::list<Agent *> m_Miners;
	std::list<Agent *> m_Soldiers;
	std::list<Agent *> m_Buildings;	//De type "Agent" car problème d'inclusion croisée si je passe en "Building"
	
	double m_dWoodStock;
	double m_dFoodStock;
	double m_dGoldStock;

public:
	Civilization(double x, double y, double z, Behaviour * behaviour, World * world);
	virtual ~Civilization();

	const Memory & getMemory();
	void run();

	double getGoldStock(void);
	double getFoodStock(void);
	double getWoodStock(void);
};

#endif
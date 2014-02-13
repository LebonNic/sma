#ifndef UNIT_H
#define UNIT_H

#include "Behaviour.h"
#include "Agent.h"
#include "Civilization.h"
#include "Location.h"
#include "Node.h"
#include "Ressource.h"

enum UnitState{
	building,
	harvesting,
	nop
};

class Civilization;

class Unit : public Agent
{
private:
	std::list<Node *> m_Path;
	Civilization * m_Civilization;
	UnitState m_State;
	unsigned int m_uRange;

	void updateCivilizationMaps();

public:
	Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Unit();
	virtual void run();

	void advanceOnPath();
	void findPathTo(const Location & goal);
};

#endif


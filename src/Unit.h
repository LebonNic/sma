#ifndef UNIT_H
#define UNIT_H



#include <limits>
#include "Agent.h"
#include "Civilization.h"
#include "Location.h"
#include "Node.h"
#include "NopBehaviour.h"

enum UnitStates{
	working,	//harvesting, building, mining...
	moving,		//moving on a path
	nop			//no operation
};

class Civilization;

class Unit : public Agent
{
private:
	static const unsigned int m_uDefaultRange;
	static const double m_dGatheringCapacity;
	std::list<Node *> m_Path;
	UnitStates m_State;
	unsigned int m_uRange;

	Location m_TargetLocation;

	void updateCivilizationMaps();

public:
	Unit(double x, double y, double z, Civilization * civilization);
	virtual ~Unit();

	const UnitStates & getUnitState() const;
	void setUnitState(const UnitStates & j);

	const Location & getUnitTargetLocation(void) const;
	void setUnitTargetLocation(const Location & targetLocation);

	virtual void run();

	void advanceOnPath();
	bool findPathTo(const Location & goal);
	bool findPathArroundTarget(const Location & emplacement);

	const Civilization & getCivilization(void) const;
	Civilization & getCivilization(void);
	static double getGatheringCapacity(void);

};

#endif


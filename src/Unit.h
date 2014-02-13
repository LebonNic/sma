#ifndef UNIT_H
#define UNIT_H

#include "Behaviour.h"
#include "Agent.h"
#include "Civilization.h"
#include "Location.h"
#include "Node.h"
#include "Ressource.h"

enum UnitJob{
	builder,	//build buildings
	lumberjack,	//collect wood
	miner,		//collect gold
	gatherer,	//collect food
	nop			//no operation == no job
};

class Civilization;

class Unit : public Agent
{
private:
	std::list<Node *> m_Path;
	Civilization * m_Civilization;
	UnitJob m_Job;
	unsigned int m_uRange;

	void updateCivilizationMaps();

public:
	Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Unit();

	const UnitJob & getJob() const;
	void setJob(const UnitJob & j);

	virtual void run();

	void advanceOnPath();
	void findPathTo(const Location & goal);
};

#endif


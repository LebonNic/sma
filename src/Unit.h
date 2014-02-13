#ifndef UNIT_H
#define UNIT_H

#include "Agent.h"
#include "Civilization.h"
#include "Location.h"
#include "Node.h"
#include "Ressource.h"
#include "NopBehaviour.h"

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
	UnitJob m_Job;
	unsigned int m_uRange;

	void updateCivilizationMaps();

public:
	Unit(double x, double y, double z, Civilization * civilization);
	virtual ~Unit();

	const UnitJob & getJob() const;
	void setJob(const UnitJob & j);

	virtual void run();

	void advanceOnPath();
	void findPathTo(const Location & goal);
};

#endif


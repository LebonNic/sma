#ifndef UNIT_H
#define UNIT_H

#include "Behaviour.h"
#include "Agent.h"

class Unit : public Agent
{
private:
public:
	Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Unit();

	virtual void run();
	virtual void attack();
	virtual void harvest();
	virtual void build();
	virtual void move();
};

#endif


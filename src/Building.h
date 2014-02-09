#pragma once
#include "Agent.h"
#include "Behaviour.h"

class Building : public Agent
{
public:
	Building(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Building(void);

	virtual void run();
	virtual void attack();
	virtual void harvest();
	virtual void build();
};


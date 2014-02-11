#pragma once
#include "Agent.h"
#include "Behaviour.h"
#include "Civilization.h"

class Civilization;

class Building : public Agent
{
private:
	Civilization * m_Civilization;
public:
	Building(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Building(void);

	virtual void run();
};


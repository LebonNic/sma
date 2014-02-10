#ifndef AGENT_H
#define AGENT_H

#include "ActiveEntity.h"
#include "Behaviour.h"
#include "Civilization.h"

class Civilization;

class Agent : public ActiveEntity
{
private:
	Civilization * m_Civilization;

	double m_dHealthPoint;

public:
	Agent(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Agent();
	virtual void run() = 0;
};

#endif
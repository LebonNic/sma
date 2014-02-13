#ifndef AGENT_H
#define AGENT_H

#include "ActiveEntity.h"
#include "Behaviour.h"

class Civilization;

class Agent : public ActiveEntity
{
protected:
	Civilization * m_Civilization;

public:
	Agent(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Agent();
	virtual void run() = 0;

};

#endif
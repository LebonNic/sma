#ifndef AGENT_H
#define AGENT_H

#include "ActiveEntity.h"
#include "Behaviour.h"

class Agent : public ActiveEntity
{
private:

public:
	Agent(double x, double y, double z, Behaviour * behaviour);
	virtual ~Agent();
	virtual void run() = 0;

};

#endif
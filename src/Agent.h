#pragma once

#include "ActiveEntity.h"

class Agent : public ActiveEntity
{
private:

public:
	Agent(double x, double y, double z, Behaviour * behaviour);
	virtual ~Agent();
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual void harvest() = 0;
	virtual void move()/* = 0*/;
};
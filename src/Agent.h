#pragma once

#include "ActiveEntity.h"

enum AgentType
{
	unit,
	building,
	group
};

class Agent : public ActiveEntity
{
private:
	AgentType m_uType;
public:
	Agent(double x, double y, double z, Graph *map,/* Owner owner,*/ Behaviour * behaviour, AgentType type);
	virtual ~Agent();
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual void harvest() = 0;
	virtual void move() = 0;
};
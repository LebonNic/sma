#include "Agent.h"

Agent::Agent(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour, AgentType type)
	: ActiveEntity(Location(x,y,z), map, owner, behaviour)
{
	m_uType = type;
}

Agent::~Agent()
{
}

void Agent::run()
{
	ActiveEntity::run();
}

void Agent::attack()
{
}

void Agent::harvest()
{
}

void Agent::move()
{
}
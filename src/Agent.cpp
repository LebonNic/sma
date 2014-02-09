#include "Agent.h"

Agent::Agent(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: ActiveEntity(Location(x,y,z),behaviour)
{
	m_Civilization = civilization;
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
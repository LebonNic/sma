#include "Agent.h"

Agent::Agent(double x, double y, double z, Behaviour * behaviour)
	: ActiveEntity(Location(x,y,z),behaviour)
{
}

Agent::~Agent()
{
}

void Agent::run()
{
	ActiveEntity::run();
}

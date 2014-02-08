#include "Building.h"


Building::Building(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour)
	: Agent(x,y,z,map,owner, behaviour, AgentType::building)
{
}


Building::~Building(void)
{
}

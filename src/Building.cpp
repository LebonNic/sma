#include "Building.h"


Building::Building(double x, double y, double z, Graph *map, Behaviour * behaviour)
	: Agent(x,y,z,map, behaviour, AgentType::building)
{
}


Building::~Building(void)
{
}

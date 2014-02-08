#include "Group.h"


Group::Group(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour)
	: Agent(x,y,z,map,owner, behaviour, AgentType::group)
{
}


Group::~Group(void)
{
}

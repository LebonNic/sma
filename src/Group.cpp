#include "Group.h"


Group::Group(double x, double y, double z, Graph *map, Behaviour * behaviour)
	: Agent(x,y,z,map, behaviour, AgentType::group)
{
}


Group::~Group(void)
{
}

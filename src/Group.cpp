#include "Group.h"


Group::Group(double x, double y, double z, Behaviour * behaviour)
	: ActiveEntity(x,y,z, behaviour)
{
}


Group::~Group(void)
{
}

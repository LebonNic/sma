#include "Group.h"


Group::Group(double x, double y, double z, Graph *map, Owner owner)
	: ActiveEntity(x,y,z,map,owner)
{
}


Group::~Group(void)
{
}

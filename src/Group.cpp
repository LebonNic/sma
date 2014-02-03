#include "Group.h"


Group::Group(double x, double y, double z, Graph *map, Owner owner)
	: ActiveEntity(x,y,z,map,owner, ActiveEntityType::group)
{
}


Group::~Group(void)
{
}

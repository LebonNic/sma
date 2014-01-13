#include "Group.h"


Group::Group(double x, double y, double z, Owner owner, double maxHitPoints)
	: ActiveEntity(x,y,z,owner,maxHitPoints)
{
}


Group::~Group(void)
{
}

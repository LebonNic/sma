#include "Building.h"


Building::Building(double x, double y, double z, Owner owner, double maxHitPoints)
	: ActiveEntity(x,y,z,owner,maxHitPoints)
{
}


Building::~Building(void)
{
}

#include "Building.h"


Building::Building(double x, double y, double z, Graph *map, Owner owner)
	: ActiveEntity(x,y,z,map,owner)
{
}


Building::~Building(void)
{
}

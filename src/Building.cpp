#include "Building.h"


Building::Building(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x,y,z, behaviour, civilization)
{
}


Building::~Building(void)
{
}

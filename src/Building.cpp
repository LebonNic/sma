#include "Building.h"


Building::Building(double x, double y, double z, Civilization * civilization)
	: Agent(x,y,z, new BuildingBehaviour(this), civilization)
{
}


Building::~Building(void)
{
}

void Building::run()
{
	Agent::run();
}
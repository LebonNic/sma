#include "Building.h"


Building::Building(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x,y,z, behaviour)
{
	m_Civilization = civilization;
}


Building::~Building(void)
{
}

void Building::run()
{
	Agent::run();
}
#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour)
	: ActiveEntity(x, y, z, map, owner, behaviour)
{
}

Civilization::~Civilization()
{
}

void Civilization::run()
{
	ActiveEntity::run();
}

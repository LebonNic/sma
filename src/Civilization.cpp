#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, Graph *map, /*Owner owner,*/ Behaviour * behaviour)
	: ActiveEntity(x, y, z, map, behaviour)
{
}

Civilization::~Civilization()
{
}

const Memory & Civilization::getMemory()
{
	return m_Memory;
}

void Civilization::run()
{
	ActiveEntity::run();
}

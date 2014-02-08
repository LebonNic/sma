#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, Behaviour * behaviour)
	: ActiveEntity(x, y, z, behaviour)
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

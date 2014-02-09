#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, Behaviour * behaviour, World * world)
	: ActiveEntity(x, y, z, behaviour)
{
	if(world)
		m_World = world;
	else
		throw std::invalid_argument("Le pointeur sur le monde passe en parametre du constructeur de Civilization ne peut pas etre NULL.");

	m_Memory = new Memory(m_World->getMap()->size());
}

Civilization::~Civilization()
{
	delete m_Memory;
}

const Memory & Civilization::getMemory()
{
	return (*m_Memory);
}

void Civilization::run()
{
	ActiveEntity::run();
}

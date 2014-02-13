#include "ActiveEntity.h"

ActiveEntity::ActiveEntity(double x, double y, double z, Behaviour * behaviour)
    : Entity(x,y,z)
{
	m_Behaviour = behaviour;
}

ActiveEntity::ActiveEntity(const Location & location, Behaviour * behaviour)
	: Entity(location)
{
	m_Behaviour = behaviour;
}

ActiveEntity::~ActiveEntity()
{
	delete m_Behaviour;
}

void ActiveEntity::run()
{
	m_Behaviour->execute();
}

void ActiveEntity::setBehaviour(Behaviour * behaviour)
{
	delete m_Behaviour;
	m_Behaviour = behaviour;
}

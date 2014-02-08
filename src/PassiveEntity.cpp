#include "PassiveEntity.h"
#include "Entity.h"


PassiveEntity::PassiveEntity(PassiveEntityType type, double x, double y, double z, Graph * map)
	: Entity(x,y,z, map)
{
	
	setType(type);
}
PassiveEntity::~PassiveEntity(void)
{
}


void PassiveEntity::setType(PassiveEntityType type)
{
	m_Type = type;
}


PassiveEntityType PassiveEntity::type(void)
{
	return m_Type;
}

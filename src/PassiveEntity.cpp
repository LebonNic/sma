#include "PassiveEntity.h"
#include "Entity.h"


PassiveEntity::PassiveEntity(PassiveEntityType type, double x, double y, double z, Graph * map, Owner owner)
	: Entity(x,y,z, map, owner)
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

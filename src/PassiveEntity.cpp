#include "PassiveEntity.h"
#include "Entity.h"


PassiveEntity::PassiveEntity(PassiveEntityType type, double x, double y, double z)
	: Entity(x,y,z)
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


PassiveEntityType PassiveEntity::type(void) const
{
	return m_Type;
}

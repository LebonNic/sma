#include "PassiveEntity.h"
#include "Entity.h"


PassiveEntity::PassiveEntity(PassiveEntityType type, double x, double y, double z, Owner owner, double quantity)
	: Entity(x,y,z,owner,quantity)
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
double PassiveEntity::quantity(void)
{
	return m_dHitPoints;
}

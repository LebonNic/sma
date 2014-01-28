#include "ActiveEntity.h"

ActiveEntity::ActiveEntity(double x, double y, double z, Graph *map, Owner owner, ActiveEntityType type)
    : Entity(x,y,z,map,owner)
{
	this->setType(type);
}

void ActiveEntity::setType(ActiveEntityType type)
{
    this->m_Type = type;
}

ActiveEntityType ActiveEntity::type(void)
{
    return m_Type;
}

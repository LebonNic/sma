#include "ActiveEntity.h"

ActiveEntity::ActiveEntity(double x, double y, double z, Owner owner, double maxHitPoints)
    : Entity(x,y,z,owner,maxHitPoints)
{
}
ActiveEntity::~ActiveEntity(void)
{
}


void ActiveEntity::setType(ActiveEntityType type)
{
    this->m_Type = type;
}


ActiveEntityType ActiveEntity::type(void)
{
    return m_Type;
}

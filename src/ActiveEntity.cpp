#include "ActiveEntity.h"

ActiveEntity::ActiveEntity(double x, double y, double z, Graph *map, /*Owner owner,*/ Behaviour * behaviour)
    : Entity(x,y,z,map)
{
	m_Behaviour = behaviour;
}

ActiveEntity::ActiveEntity(const Location & location, Graph *map, /*Owner owner,*/ Behaviour * behaviour)
	: Entity(location, map)
{
	m_Behaviour = behaviour;
}

ActiveEntity::ActiveEntity()
	:Entity(0, 0, 0, NULL)
{

}

ActiveEntity::~ActiveEntity()
{
	if(m_Behaviour)
		delete m_Behaviour;
}

void ActiveEntity::run()
{
	m_Behaviour->execute();
}

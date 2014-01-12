#include "Entity.h"


Entity::Entity(void) 
{
}
Entity::~Entity(void) 
{
}


double Entity::x()
{
	return m_Location->x();
}
double Entity::y()
{
	return m_Location->y();
}
double Entity::z()
{
	return m_Location->z();
}

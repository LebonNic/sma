#include "Entity.h"


Entity::Entity(double x, double y, double z, Owner owner, double maxHitPoints)
{
	setLocation(new Location(x,y,z));
	setOwner(owner);
	setMaxHitPoints(maxHitPoints);
	setHitPoints(maxHitPoints);
}
Entity::Entity(Location *location, Owner owner, double maxHitPoints)
{
	setLocation(location);
	setOwner(owner);
	setMaxHitPoints(maxHitPoints);
	setHitPoints(maxHitPoints);
}
Entity::~Entity(void) 
{
	delete m_Location;
}


void Entity::setLocation(Location *location)
{
	m_Location = location;
}
void Entity::setOwner(Owner owner)
{
	m_Owner = owner;
}
void Entity::setMaxHitPoints(double maxHitPoints)
{
	m_dMaxHitPoints = maxHitPoints;
}
void Entity::setHitPoints(double hitPoints)
{
	m_dHitPoints = hitPoints;
}


double Entity::hitPoints(void)
{
	return m_dHitPoints;
}
double Entity::maxHitPoints(void)
{
	return m_dMaxHitPoints;
}
Owner Entity::owner(void)
{
	return m_Owner;
}
Location *Entity::location(void)
{
	return m_Location;
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

#include "Entity.h"

unsigned int Entity::m_uCurrentId = 0;

Entity::Entity(double x, double y, double z)
{
	setLocation(Location(x,y,z));
	setId(Entity::m_uCurrentId);
	Entity::m_uCurrentId++;
}

Entity::Entity(const Location & location)
{
	setLocation(location);
	setId(Entity::m_uCurrentId);
	Entity::m_uCurrentId++;
}

Entity::~Entity(void)
{
}

void Entity::setId(unsigned int id)
{
	m_uId = id;
}

void Entity::setLocation(const Location & location)
{
	m_Location = location;
}


Location Entity::location(void) const
{
	return m_Location;
}

unsigned int Entity::id() const
{
	return m_uId;
}

double Entity::x()
{
	return m_Location.x();
}
double Entity::y()
{
	return m_Location.y();
}
double Entity::z()
{
	return m_Location.z();
}

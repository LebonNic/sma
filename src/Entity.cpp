#include "Entity.h"


Entity::Entity(double x, double y, double z, Graph *map, Owner owner)
{
	setLocation(new Location(x,y,z));
	setMap(map);
	setOwner(owner);
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
void Entity::setMap(Graph *map)
{
	m_Map = map;
}


Owner Entity::owner(void)
{
	return m_Owner;
}
Location *Entity::location(void)
{
	return m_Location;
}
Graph *Entity::map(void)
{
	return m_Map;
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

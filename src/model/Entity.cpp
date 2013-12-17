#include "Entity.h"

Entity::Entity(void) {
	m_Position.setCoordinates(0,0);
}

Entity::Entity(const Point & position) {
	m_Position.setCoordinates(position);
}

Entity::Entity(const Entity & entity) {
	m_Position = entity.getPosition();
}

Entity & Entity::operator= (const Entity & entity) {
	if (&entity != this)
		setPosition(entity.getPosition());
}

void Entity::setPosition(const Point & position) {
	m_Position.setCoordinates(position);
}

void Entity::setPosition(double x, double y) {
	m_Position.setCoordinates(x,y);
}

Point Entity::getPosition(void) const {
	return m_Position;
}
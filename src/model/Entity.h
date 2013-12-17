#pragma once
#include "Point.h"

class Entity
{
private:
	Point m_Position;
public:
	Entity(void);
	Entity(const Point & position);
	Entity(const Entity & entity);
	Entity & operator= (const Entity & entity);
	~Entity(void);
	void setPosition(const Point & position);
	void setPosition(double x, double y);
	Point getPosition(void) const;
};


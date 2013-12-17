#include "Point.h"

Point::Point(void) {
	setX(0);
	setY(0);
}

Point::Point(double x, double y)
{
	setX(x);
	setY(y);
}

Point::Point(const Point & point)
{
	setX(point.getX());
	setY(point.getY());
}

Point::~Point(void)
{
}

Point & Point::operator=(const Point & point) 
{
	if (&point != this)
	{
		setX(point.getX());
		setY(point.getY());
	}
}

double Point::getX(void) const
{
	return m_dX;
}

double Point::getY(void) const
{
	return m_dY;
}

void Point::setX(double x) 
{
	m_dX = x;
}

void Point::setY(double y)
{
	m_dY = y;
}

void Point::setCoordinates(double x, double y)
{
	setX(x);
	setY(y);
}

void Point::setCoordinates(const Point & point)
{
	setX(point.getX());
	setY(point.getY());
}
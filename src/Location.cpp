#include "Location.h"


Location::Location()
{
	setX(0.0);
	setY(0.0);
	setZ(0.0);
}
Location::Location(double x, double y, double z)
{
	setX(x);
	setY(y);
	setZ(z);
}
Location::~Location(void)
{

}

	
double Location::x() const
{
	return m_dX;
}
double Location::y() const
{
	return m_dY;
}
double Location::z() const
{
	return m_dZ;
}


void Location::setX(double x)
{
	this->m_dX = x;
}
void Location::setY(double y)
{
	this->m_dY = y;
}
void Location::setZ(double z)
{
	this->m_dZ = z;
}

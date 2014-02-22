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

Location::Location(const Location & l)
{
	m_dX = l.m_dX;
	m_dY = l.m_dY;
	m_dZ = l.m_dZ;
}

Location & Location::operator=(const Location & l)
{
	if(this != &l)
	{
		m_dX = l.m_dX;
		m_dY = l.m_dY;
		m_dZ = l.m_dZ;
	}
	return *this;
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

void Location::setX(unsigned int x)
{
	this->m_dX = (double)x;
}

void Location::setY(unsigned int y)
{
	this->m_dY = (double)y;
}

void Location::setZ(unsigned int z)
{
	this->m_dZ = (double)z;
}


#pragma once
#include "Location.h"

class Entity
{
private:
	static unsigned int m_uCurrentId;
	Location m_Location;
	unsigned int m_uId;
	void setId(unsigned int id);

public:

	Entity(double x, double y, double z);
	Entity(const Location & location);
	~Entity(void);

	void setLocation(const Location & location);

	Location location(void) const;
	unsigned int id() const;
	double x(void);
	double y(void);
	double z(void);
};


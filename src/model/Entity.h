#pragma once
#include "Location.h"

typedef unsigned Owner;

class Entity
{
protected:
	double m_dHitPoints;
	double m_dMaxHitPoints;
	Location *m_Location;
	Owner m_Owner;

	void setLocation(Location *location);
	void setOwner(Owner owner);
	void setMaxHitPoints(double maxHitPoints);
	void setHitPoints(double hitPoints);
public:
	static const Owner NATURE_OWNER = 0;

	Entity(double x = 0.0, double y = 0.0, double z = 0.0, Owner owner = NATURE_OWNER, double hitPoints = 100.0);
	Entity(Location *location, Owner owner = NATURE_OWNER, double hitPoints = 100.0);
	~Entity(void);

	double hitPoints(void);
	double maxHitPoints(void);
	Owner owner(void);
	Location *location(void);
	double x(void);
	double y(void);
	double z(void);
};


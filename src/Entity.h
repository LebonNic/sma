#pragma once
#include "Location.h"
#include "Graph.h"

typedef unsigned Owner;

class Entity
{
protected:
	Location *m_Location;
	Owner m_Owner;
	Graph *m_Map;

	void setLocation(Location *location);
	void setOwner(Owner owner);
	void setMap(Graph *map);
public:
	static const Owner NATURE_OWNER = 0;

	Entity(double x, double y, double z, Graph *map, Owner owner = NATURE_OWNER);
	~Entity(void);

	Owner owner(void);
	Location *location(void);
	Graph *map(void);
	double x(void);
	double y(void);
	double z(void);
};


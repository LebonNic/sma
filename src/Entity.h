#pragma once
#include "Location.h"
#include "Graph.h"

typedef unsigned Owner;

class Entity
{
private:

	static unsigned int m_uCurrentId;
	Location m_Location;
	Owner m_Owner;
	Graph *m_Map;
	unsigned int m_uId;
	
	void setOwner(Owner owner);
	void setMap(Graph *map);
	void setId(unsigned int id);
public:
	static const Owner NATURE_OWNER = 0;

	Entity(double x, double y, double z, Graph *map, Owner owner = NATURE_OWNER);
	Entity(const Location & location, Graph *map, Owner owner = NATURE_OWNER);
	~Entity(void);

	void setLocation(const Location & location);
	Owner owner(void);
	Location location(void);
	Graph *map(void);
	unsigned int id();

	double x(void);
	double y(void);
	double z(void);
};


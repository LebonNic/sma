#pragma once
#include <list>
#include "ActiveEntity.h"
#include "Unit.h"
class Unit;


class Group : 
	public ActiveEntity
{
private:
	std::list<Unit *> m_Units;
public:
	Group(double x, double y, double z, Graph *map, Owner owner);
	~Group(void);
};


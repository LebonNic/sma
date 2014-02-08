#pragma once
#include <list>
#include "Agent.h"
#include "Unit.h"
class Unit;


class Group : public Agent
{
private:
	std::list<Unit *> m_Units;
public:
	Group(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour);
	~Group(void);
};


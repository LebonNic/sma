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
	Group(void);
	~Group(void);
};


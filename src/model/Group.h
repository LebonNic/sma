#pragma once
#include "Unit.h"
#include "ActiveEntity.h"
#include <vector>

class Group : 
	public ActiveEntity
{
private:
	std::vector<Unit *> m_Units;
public:
	Group(void);
	~Group(void);
};


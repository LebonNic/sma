#pragma once
#include "Unit.h"
#include <vector>

class Group :
	public Agent
{
private:
	std::vector<Unit *> m_Units;
public:
	Group(void);
	~Group(void);
};


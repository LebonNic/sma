#pragma once
#include "agent.h"
#include <vector>


class Group :
	public Agent
{
private:
	std::vector<Agent *> m_Agents;
public:
	Group(void);
	~Group(void);
};


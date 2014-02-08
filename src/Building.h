#pragma once
#include "Agent.h"

class Building : public Agent
{
public:
    Building(double x, double y, double z, Graph *map, Behaviour * behaviour);
	~Building(void);
};


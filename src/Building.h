#pragma once
#include "Agent.h"

class Building : public Agent
{
public:
    Building(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	~Building(void);
};


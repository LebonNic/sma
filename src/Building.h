#pragma once
#include "ActiveEntity.h"

class Building
	: public ActiveEntity
{
public:
	Building(double x, double y, double z, Owner owner, double maxHitPoints);
	~Building(void);
};


#pragma once

#include "ActiveEntity.h"

class Civilization : public ActiveEntity
{
private:

public:
	Civilization(double x, double y, double z, Graph *map, Owner owner, Behaviour * behaviour);
	virtual ~Civilization();
	void run();
};
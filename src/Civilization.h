#pragma once

#include "ActiveEntity.h"
#include "Memory.h"

class Civilization : public ActiveEntity
{
private:
	Memory m_Memory;

public:
	Civilization(double x, double y, double z, Graph *map, /*Owner owner,*/ Behaviour * behaviour);
	virtual ~Civilization();

	const Memory & getMemory();
	void run();
};
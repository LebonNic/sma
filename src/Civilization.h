#pragma once

#include "ActiveEntity.h"
#include "World.h"
#include "Memory.h"

class Civilization : public ActiveEntity
{
private:
	Memory * m_Memory;
	World * m_World;

public:
	Civilization(double x, double y, double z, Behaviour * behaviour, World * world);
	virtual ~Civilization();

	const Memory & getMemory();
	void run();
};
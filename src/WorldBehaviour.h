#pragma once
#include "Behaviour.h"
#include "World.h"

class World;

class WorldBehaviour : public Behaviour
{

private:
	World * m_World;

public:
	WorldBehaviour(World * world);
	virtual ~WorldBehaviour();
	virtual void execute();
};
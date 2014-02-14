#pragma once
#include "Behaviour.h"
#include "World.h"

#define WORLD_RUN_MESSAGE "> [INFO] World [" << m_World->id() <<"] is running."

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
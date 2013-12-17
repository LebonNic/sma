#pragma once

#include <list>
#include "Entity.h"
#include "ActiveEntity.h"
#include "Map.h"

class World :
	public ActiveEntity
{
private:
	std::list<Entity *> m_Entities;
	Map * m_Map;

public:
	World(void);
	~World(void);
};


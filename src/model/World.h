#pragma once

#include <vector>
#include "ActiveEntity.h"
#include "PassiveEntity.h"
#include "Map.h"

class World :
	public ActiveEntity
{
private:
	std::vector<ActiveEntity *> m_ActiveEntities;
	std::vector<PassiveEntity *> m_PassiveEntities;
	Map * m_Map;

public:
	World(void);
	~World(void);
};


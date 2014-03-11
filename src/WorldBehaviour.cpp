#include "WorldBehaviour.h"


WorldBehaviour::WorldBehaviour(World * world)
	:m_World(world)
{
}

WorldBehaviour::~WorldBehaviour()
{
}

void WorldBehaviour::execute()
{
	/*qDebug() << WORLD_RUN_MESSAGE;*/
	const std::list<Civilization *> & civilizations = m_World->getCivilizations();
	for(auto civi = civilizations.begin(); civi != civilizations.end(); ++civi)
		(*civi)->run();
}


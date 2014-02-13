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
	qDebug() << "> [INFO] Run du World d'ID : " << m_World->id();
	std::list<Civilization *> civilizations = m_World->getCivilizations();
	for(auto civi = civilizations.begin(); civi != civilizations.end(); ++civi)
		(*civi)->run();
}


#include "CivilizationBehaviour.h"


CivilizationBehaviour::CivilizationBehaviour(Civilization * civilization)
	:m_Civilization(civilization)
{
	
}


CivilizationBehaviour::~CivilizationBehaviour(void)
{
}

void CivilizationBehaviour::execute()
{
	//TODO implement the logic of the civilization here.
	//The following peace of code is just a test.

	qDebug() << CIVILIZATION_RUN_MESSAGE;

	//std::list<Unit *> units = m_Civilization->getUnits();
	for(auto uni = units.begin(); uni != units.end(); ++uni)
		(*uni)->run();

	std::list<Building *> buildings = m_Civilization->getBuildings();
	for(auto bui = buildings.begin(); bui != buildings.end(); ++bui)
		(*bui)->run();
}

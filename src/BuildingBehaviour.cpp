#include "BuildingBehaviour.h"


BuildingBehaviour::BuildingBehaviour(Building * building)
	:m_Building(building)
{
}


BuildingBehaviour::~BuildingBehaviour(void)
{
}

void BuildingBehaviour::execute()
{
	qDebug() << BUILDING_RUN_MESSAGE;
}

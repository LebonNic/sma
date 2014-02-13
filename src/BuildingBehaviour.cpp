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
	qDebug() << ">		[INFO] Run du building d'ID : " << m_Building->id();
}

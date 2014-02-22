#include "CivilizationBehaviour.h"


CivilizationBehaviour::CivilizationBehaviour(Civilization * civilization)
	:m_Civilization(civilization)
{
	
}

CivilizationBehaviour::~CivilizationBehaviour(void)
{
}

void CivilizationBehaviour::affectUnitsToBuildingTasks()
{
	std::list<Unit *>	& freeUnits = m_Civilization->getFreeUnitsList(),
						& builders = m_Civilization->getBuildersList();

	//If the civilization has enough ressources to build a new building
	if(m_Civilization->getWoodStock() >= Civilization::m_dBuildingWoodCost && 
		m_Civilization->getGoldStock() >= Civilization::m_dBuildingGoldCost &&
		m_Civilization->getFoodStock() >= Civilization::m_dBuildingFoodCost)
	{
		Unit * uni = NULL;
		//Check if there are no free units available
		if(!(freeUnits.empty()))
		{
			uni = freeUnits.front();
			uni->setBehaviour(new BuilderBehaviour(uni));
			builders.push_back(uni);
			freeUnits.remove(uni);
		}

		//Select an unit among the richest list available
		else
		{
			std::list<Unit *> & richestList = m_Civilization->getRichestList();
			if(richestList.size() > 0)
			{
				uni = richestList.front();
				uni->setBehaviour(new BuilderBehaviour(uni));
				uni->setUnitState(UnitStates::nop);
				builders.push_back(uni);
				richestList.remove(uni);
			}
		}
		m_Civilization->consumeRessource(RessourceType::food, Civilization::m_dBuildingFoodCost);
		m_Civilization->consumeRessource(RessourceType::gold, Civilization::m_dBuildingGoldCost);
		m_Civilization->consumeRessource(RessourceType::wood, Civilization::m_dBuildingWoodCost);	
	}
}

void CivilizationBehaviour::affectFreeUnitsToGatheringTasks()
{
	std::list<Unit *>	& freeUnits = m_Civilization->getFreeUnitsList();

	unsigned int i = 0;

	while(!freeUnits.empty())
	{
		Unit * uni = freeUnits.front();

		switch( i % RESSOURCE_TYPES_COUNT )
		{
		case RessourceType::wood:
			uni->setBehaviour(new GathererBehaviour(uni, RessourceType::wood));
			m_Civilization->getLumberjacksList().push_back(uni);
		break;

		case RessourceType::gold:
			uni->setBehaviour(new GathererBehaviour(uni, RessourceType::gold));
			m_Civilization->getMinersList().push_back(uni);
		break;

		case RessourceType::food:
			uni->setBehaviour(new GathererBehaviour(uni, RessourceType::food));
			m_Civilization->getFoodGatherersList().push_back(uni);
		break;

		}
		freeUnits.remove(uni);
		++i;
	}
}

void CivilizationBehaviour::execute()
{
	qDebug() << CIVILIZATION_RUN_MESSAGE;
	qDebug() << "Food : " << m_Civilization->getFoodStock();
	qDebug() << "Gold : " << m_Civilization->getGoldStock();
	qDebug() << "Wood : " << m_Civilization->getWoodStock();

	affectUnitsToBuildingTasks();
	affectFreeUnitsToGatheringTasks();

	std::list<Unit *> units = m_Civilization->getUnits();
	for(auto uni = units.begin(); uni != units.end(); ++uni)
		(*uni)->run();

	std::list<Building *> buildings = m_Civilization->getBuildings();
	for(auto bui = buildings.begin(); bui != buildings.end(); ++bui)
		(*bui)->run();
}

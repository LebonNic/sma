#include "Civilization.h"

const double Civilization::m_dBuildingWoodCost = 5000.0;
const double Civilization::m_dBuildingFoodCost = 5000.0;
const double Civilization::m_dBuildingGoldCost = 5000.0;

Civilization::Civilization(double x, double y, double z, World * world)
	: ActiveEntity(x, y, z, new CivilizationBehaviour(this))
{
	if(world)
		m_World = world;
	else
		throw std::invalid_argument("Le pointeur sur le monde passe en parametre du constructeur de Civilization ne peut pas etre NULL.");

	//Each civilization begins with one building
	createBuilding(Location(x, y));

	//Instantiates the civilization's memory
	m_Memory = new Memory((m_World->getMap()).size());

	m_dFoodStock = 0;
	m_dGoldStock = 0;
	m_dWoodStock = 0;
}

Civilization::~Civilization()
{
	delete m_Memory;

	for(auto unit = m_Units.begin(); unit != m_Units.end(); ++unit)
		delete (*unit);
}

const Memory & Civilization::getMemory() const
{
	return (*m_Memory);
}

void Civilization::run()
{
	ActiveEntity::run();
}

double Civilization::getGoldStock(void)
{
	return m_dGoldStock;
}

double Civilization::getFoodStock(void)
{
	return m_dFoodStock;
}

double Civilization::getWoodStock(void)
{
	return m_dWoodStock;
}

const World & Civilization::getWorld() const
{
	return (*m_World);
}


World & Civilization::getWorld()
{
	return (*m_World);
}

const std::list<Unit *> & Civilization::getUnits(void) const
{
	return m_Units;
}

const std::list<Building *> & Civilization::getBuildings(void) const
{
	return m_Buildings;
}

void Civilization::locateFood(const Location & l)
{
	m_Memory->setFoodMap(l, true);
}

void Civilization::locateGold(const Location & l)
{
	m_Memory->setGoldMap(l, true);
}

void Civilization::locateWood(const Location & l)
{
	m_Memory->setWoodMap(l, true);
}

void Civilization::locateEmptinessSpace(const Location & l)
{
	m_Memory->setFoodMap(l, false);
	m_Memory->setGoldMap(l, false);
	m_Memory->setWoodMap(l, false);
}

void Civilization::increaseFoodStockFromRessource(const Location & ressourceLocation, double quantity)
{
	m_dFoodStock += m_World->consumeRessource(ressourceLocation, quantity);
}

void Civilization::increaseGoldStockFromRessource(const Location & ressourceLocation, double quantity)
{
	m_dGoldStock += m_World->consumeRessource(ressourceLocation, quantity);
}

void Civilization::increaseWoodStockFromRessource(const Location & ressourceLocation, double quantity)
{
	m_dWoodStock += m_World->consumeRessource(ressourceLocation, quantity);
}

void Civilization::createBuilding(const Location & emplacement)
{
	//Check if the location is not used by a ressource and not already used by a building
	const Graph & map = m_World->getMap();

	double	x = emplacement.x(),
			y = emplacement.y(),
			z = emplacement.z();

	if( m_World->isConstructible(emplacement) )
	{
		m_Buildings.push_back(new Building(x, y, z, this));
		map(x, y)->setReachable(false);

		//Create units on the locations surrounding the new building (in fonction of the free space arround the building)
		std::list<Node * > neighbourNodes = m_World->getMap()(x, y)->neighbours();
		for(auto node = neighbourNodes.begin(); node != neighbourNodes.end(); ++node)
		{
			Unit * unit = new Unit((*node)->x(), (*node)->y(), (*node)->z(), this);
			unit->setBehaviour(new NopBehaviour(unit));
			m_FreeUnits.push_back(unit);
			m_Units.push_back(unit);
		}
	}
	else
		throw std::runtime_error("Impossible to create a building because the emplacement specified is already occupied by a ressource.");
}

const std::list<Unit *> & Civilization::getFreeUnitsList() const
{
	return m_FreeUnits;
}

std::list<Unit *> & Civilization::getFreeUnitsList()
{
	return m_FreeUnits;
}

const std::list<Unit *> & Civilization::getLumberjacksList() const
{
	return m_Lumberjacks;
}

std::list<Unit *> & Civilization::getLumberjacksList()
{
	return m_Lumberjacks;
}

const std::list<Unit *> & Civilization::getBuildersList() const
{
	return m_Builders;
}

std::list<Unit *> & Civilization::getBuildersList()
{
	return m_Builders;
}

const std::list<Unit *> & Civilization::getFoodGatherersList() const
{
	return m_FoodGatherers;
}
std::list<Unit *> & Civilization::getFoodGatherersList()
{
	return m_FoodGatherers;
}

const std::list<Unit *> & Civilization::getMinersList() const
{
	return m_Miners;
}
std::list<Unit *> & Civilization::getMinersList()
{
	return m_Miners;
}

std::list<Unit *> & Civilization::getRichestList()
{
		std::list<Unit *> * richestList = (&m_FoodGatherers);
		unsigned int	max = (unsigned int) richestList->size(),
						size = (unsigned int) m_Miners.size();

		if(max < size)
		{
			max = size;
			richestList = (&m_Miners);
		}

		size = (unsigned int) m_Lumberjacks.size();
		if(max < size)
		{
			max = size;
			richestList = (&m_Lumberjacks);
		}

		return (*richestList);
}

void Civilization::consumeRessource(RessourceType ressourceType, double quantity)
{
	switch(ressourceType)
	{
		case RessourceType::wood:
			m_dWoodStock -= quantity;
		break;

		case RessourceType::gold:
			m_dGoldStock -= quantity;
		break;

		case RessourceType::food:
			m_dFoodStock -= quantity;
		break;
	}
}




#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, World * world)
	: ActiveEntity(x, y, z, new CivilizationBehaviour(this))
{
	if(world)
		m_World = world;
	else
		throw std::invalid_argument("Le pointeur sur le monde passe en parametre du constructeur de Civilization ne peut pas etre NULL.");

	m_Memory = new Memory((m_World->getMap()).size());

	m_Buildings.push_back(new Building(x, y, z, this));

	m_dFoodStock = 0;
	m_dGoldStock = 0;
	m_dWoodStock = 0;
}

Civilization::~Civilization()
{
	delete m_Memory;

	for(auto unit = m_FreeUnits.begin(); unit != m_FreeUnits.end(); ++unit)
		delete (*unit);

	for(auto unit = m_Gatherers.begin(); unit != m_Gatherers.end(); ++unit)
		delete (*unit);

	for(auto unit = m_Lumberjacks.begin(); unit != m_Lumberjacks.end(); ++unit)
		delete (*unit);

	for(auto unit = m_Miners.begin(); unit != m_Miners.end(); ++unit)
		delete (*unit);

	for(auto building = m_Buildings.begin(); building != m_Buildings.end(); ++building)
		delete (*building);
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


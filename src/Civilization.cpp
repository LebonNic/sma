#include "Civilization.h"

Civilization::Civilization(double x, double y, double z, Behaviour * behaviour, World * world)
	: ActiveEntity(x, y, z, behaviour)
{
	if(world)
		m_World = world;
	else
		throw std::invalid_argument("Le pointeur sur le monde passe en parametre du constructeur de Civilization ne peut pas etre NULL.");

	m_Memory = new Memory((m_World->getMap()).size());

	m_dFoodStock = 0;
	m_dGoldStock = 0;
	m_dWoodStock = 0;
}

Civilization::~Civilization()
{
	delete m_Memory;
}

const Memory & Civilization::getMemory()
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


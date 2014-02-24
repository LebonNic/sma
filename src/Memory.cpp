#include "Memory.h"


Memory::Memory(unsigned int size)
{
	m_uSize = size;

	m_FoodMap = std::vector<std::vector<bool>> (m_uSize);
	m_GoldMap = std::vector<std::vector<bool>> (m_uSize);
	m_WoodMap = std::vector<std::vector<bool>> (m_uSize);
	m_DiscoveredArea = std::vector<std::vector<bool>> (m_uSize);

	initArray(m_FoodMap, false);
	initArray(m_GoldMap, false);
	initArray(m_WoodMap, false);
	initArray(m_DiscoveredArea, false);
}

void Memory::initArray(std::vector<std::vector<bool>> & arr, bool value)
{
	for(auto vec = arr.begin(); vec != arr.end(); ++vec)
	{
		(*vec) = std::vector<bool>(m_uSize);
		std::fill((*vec).begin(), (*vec).end(), value);
	}
}

Memory::~Memory(void)
{
}

const std::vector<std::vector<bool>> & Memory::getFoodMap() const
{
	return m_FoodMap;
}

const std::vector<std::vector<bool>> & Memory::getGoldMap() const
{
	return m_GoldMap;
}

const std::vector<std::vector<bool>> & Memory::getWoodMap() const
{
	return m_WoodMap;
}

const std::vector<std::vector<bool>> & Memory::getDiscoveredArea() const
{
	return m_DiscoveredArea;
}

void Memory::setFoodMap(const Location & l, bool val)
{
	m_FoodMap[(unsigned int) l.x()][(unsigned int) l.y()] = val;
}

void Memory::setGoldMap(const Location & l, bool val)
{
	m_GoldMap[(unsigned int) l.x()][(unsigned int) l.y()] = val;
}

void Memory::setWoodMap(const Location & l, bool val)
{
	m_WoodMap[(unsigned int) l.x()][(unsigned int) l.y()] = val;
}

void Memory::setDiscoveredArea(const Location & l, bool val)
{
	m_DiscoveredArea[(unsigned int) l.x()][(unsigned int) l.y()] = val;
}

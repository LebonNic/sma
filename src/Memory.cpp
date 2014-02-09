#include "Memory.h"


Memory::Memory(unsigned int size)
{
	m_uSize = size;

	m_FoodMap = std::vector<std::vector<bool>> (m_uSize);
	m_GoldMap = std::vector<std::vector<bool>> (m_uSize);
	m_WoodMap = std::vector<std::vector<bool>> (m_uSize);

	initArray(m_FoodMap, false);
	initArray(m_GoldMap, false);
	initArray(m_WoodMap, false);
}

void Memory::initArray(std::vector<std::vector<bool>> & arr, bool value)
{
	for(auto vec = arr.begin(); vec != arr.end(); ++vec)
		std::fill((*vec).begin(), (*vec).end(), value);
}

Memory::~Memory(void)
{
}

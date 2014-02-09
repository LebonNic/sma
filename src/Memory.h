#pragma once

#include <vector>

class Memory
{
private:
	unsigned int m_uSize;
	std::vector<std::vector<bool>> m_FoodMap;
	std::vector<std::vector<bool>> m_GoldMap;
	std::vector<std::vector<bool>> m_WoodMap;

	void initArray(std::vector<std::vector<bool>> & arr, bool value);
public:
	Memory(unsigned int size);
	~Memory(void);
};


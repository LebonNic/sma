#pragma once

#include <vector>
#include "Location.h"

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

	const std::vector<std::vector<bool>> & getFoodMap() const;
	const std::vector<std::vector<bool>> & getGoldMap() const;
	const std::vector<std::vector<bool>> & getWoodMap() const;

	void setFoodMap(const Location & l, bool val);
	void setGoldMap(const Location & l, bool val);
	void setWoodMap(const Location & l, bool val);

};


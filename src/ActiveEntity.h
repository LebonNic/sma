#pragma once
#include "Entity.h"
#include <string>
#include <sstream>
#include <fstream>

enum ActiveEntityType
{
	unit,
	building,
	group
};

class ActiveEntity :
	public Entity
{
private:
    ActiveEntityType m_Type;

    void setType(ActiveEntityType type);
public:
	ActiveEntity(double x, double y, double z, Graph *map, Owner owner, ActiveEntityType type);

	ActiveEntityType type(void);
};


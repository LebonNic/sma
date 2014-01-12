#pragma once
#include "Entity.h"


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
	ActiveEntityType type;
public:
	ActiveEntity(void);
	~ActiveEntity(void);
};


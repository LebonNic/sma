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
    ActiveEntityType m_Type;


    void setType(ActiveEntityType type);
public:
	ActiveEntity(double x, double y, double z, Owner owner, double maxHitPoints);
	~ActiveEntity(void);


    ActiveEntityType type(void);
};


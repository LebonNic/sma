#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include "Entity.h"
#include "Behaviour.h"
#include "Location.h"


class ActiveEntity : public Entity
{
private:
	Behaviour * m_Behaviour;

public:
	ActiveEntity(double x, double y, double z, Graph *map, /*Owner owner,*/ Behaviour * behaviour);
	ActiveEntity(const Location & location, Graph *map, /*Owner owner,*/ Behaviour * behaviour);
	ActiveEntity();
	virtual ~ActiveEntity();
	virtual void run() = 0;
};


#pragma once

#include "Behaviour.h"
#include "Building.h"

class Building;

class BuildingBehaviour : public Behaviour
{
private:
	Building * m_Building;

public:
	BuildingBehaviour(Building * building);
	virtual ~BuildingBehaviour(void);
	virtual void execute();
};


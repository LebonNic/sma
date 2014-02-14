#pragma once

#include "Behaviour.h"
#include "Building.h"

#define BUILDING_RUN_MESSAGE ">		[INFO] Building [" << m_Building->id() <<"] is running."

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


#pragma once

#define NOMINMAX

#include "Civilization.h"
#include "Behaviour.h"
#include "GathererBehaviour.h"
#include "BuilderBehaviour.h"


#define CIVILIZATION_RUN_MESSAGE ">	[INFO] Civilization [" << m_Civilization->id() <<"] is running"
#define RESSOURCE_TYPES_COUNT 3 

class Civilization;

class CivilizationBehaviour : public Behaviour
{

private:
	Civilization * m_Civilization;

	void affectFreeUnitsToGatheringTasks();
	void affectUnitsToBuildingTasks();

public:
	CivilizationBehaviour(Civilization * civilization);
	virtual ~CivilizationBehaviour(void);
	virtual void execute();
};


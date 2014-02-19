#pragma once

#include "Civilization.h"
#include "Behaviour.h"
#include "GathererBehaviour.h"

#define CIVILIZATION_RUN_MESSAGE ">	[INFO] Civilization [" << m_Civilization->id() <<"] is running"

class Civilization;

class CivilizationBehaviour : public Behaviour
{

private:
	Civilization * m_Civilization;
public:
	CivilizationBehaviour(Civilization * civilization);
	virtual ~CivilizationBehaviour(void);
	virtual void execute();
};


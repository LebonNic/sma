#pragma once

#include "Civilization.h"
#include "Behaviour.h"

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


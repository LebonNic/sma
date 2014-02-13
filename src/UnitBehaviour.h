#pragma once

#include "Unit.h"
#include "Behaviour.h"

class Unit;

class UnitBehaviour : public Behaviour
{
private:
	Unit * m_Unit;
public:
	UnitBehaviour(Unit * unit);
	virtual ~UnitBehaviour(void);
	virtual void execute() = 0;
};


#pragma once

#include "Behaviour.h"

#define UNIT_RUN_MESSAGE ">		[INFO] Unit [" << m_Unit->id() << "] is running."

class Unit;

class UnitBehaviour : public Behaviour
{
protected:
	Unit * m_Unit;
public:
	UnitBehaviour(Unit * unit);
	virtual ~UnitBehaviour(void);
	virtual void execute() = 0;
};


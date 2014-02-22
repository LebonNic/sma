#pragma once

#include "Behaviour.h"

#define UNIT_RUN_MESSAGE ">		[INFO] Unit [" << m_Unit->id() << "] is running."

class Unit;

class UnitBehaviour : public Behaviour
{
protected:
	Unit * m_Unit;
	static const unsigned int m_strikesNumber;
public:
	UnitBehaviour(Unit * unit);
	virtual ~UnitBehaviour(void);
	virtual void execute() = 0;
};


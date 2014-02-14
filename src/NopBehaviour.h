#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"

#define UNIT_NOP_MESSAGE ">			[INFO] Unit is doing nothing."

class NopBehaviour : public UnitBehaviour
{
public:
	NopBehaviour(Unit * unit);
	virtual ~NopBehaviour(void);
	virtual void execute();
};


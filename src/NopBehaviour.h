#pragma once

#include "UnitBehaviour.h"

class Unit;

class NopBehaviour : public UnitBehaviour
{
public:
	NopBehaviour(Unit * unit);
	virtual ~NopBehaviour(void);
	virtual void execute();
};


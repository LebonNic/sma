#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"

class NopBehaviour : public UnitBehaviour
{
public:
	NopBehaviour(Unit * unit);
	virtual ~NopBehaviour(void);
	virtual void execute();
};


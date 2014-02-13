#pragma once

#include "UnitBehaviour.h"

class NopBehaviour : public UnitBehaviour
{
public:
	NopBehaviour(Unit * unit);
	virtual ~NopBehaviour(void);
	virtual void execute();
};


#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"

class BuilderBehaviour : public UnitBehaviour
{
public:
	BuilderBehaviour(Unit * unit);
	~BuilderBehaviour(void);
	virtual void execute();
};


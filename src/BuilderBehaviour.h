#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"

#define UNIT_BUILDER_MESSAGE ">			[INFO] Unit is a builder."

class BuilderBehaviour : public UnitBehaviour
{
public:
	BuilderBehaviour(Unit * unit);
	~BuilderBehaviour(void);
	virtual void execute();
};


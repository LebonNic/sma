#pragma once

#include "UnitBehaviour.h"
#include "Unit.h"

#define UNIT_GATHERER_MESSAGE ">			[INFO] Unit is a gatherer."

class GathererBehaviour : public UnitBehaviour
{
public:
	GathererBehaviour(Unit * unit);
	~GathererBehaviour(void);
	virtual void execute();
};


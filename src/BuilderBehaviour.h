#pragma once

#include "UnitBehaviour.h"

class BuilderBehaviour : public UnitBehaviour
{
public:
	BuilderBehaviour(Unit * unit);
	~BuilderBehaviour(void);
	virtual void execute();
};


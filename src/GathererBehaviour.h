#pragma once

#include "UnitBehaviour.h"

class GathererBehaviour : public UnitBehaviour
{
public:
	GathererBehaviour(Unit * unit);
	~GathererBehaviour(void);
	virtual void execute();
};


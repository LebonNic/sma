#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include "UnitBehaviour.h"
#include "Unit.h"
#include "NormalDistributionGenerator.h"

#define UNIT_BUILDER_MESSAGE ">			[INFO] Unit is a builder."

class BuilderBehaviour : public UnitBehaviour
{
private:
	static NormalDistributionGenerator m_NormalDistribGenerator;
	static MersenneTwister m_PseudoRandomGenerator;

	void findConstructibleArea();
public:
	BuilderBehaviour(Unit * unit);
	~BuilderBehaviour(void);
	virtual void execute();
};


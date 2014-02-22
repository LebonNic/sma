#include "BuilderBehaviour.h"

NormalDistributionGenerator BuilderBehaviour::m_NormalDistribGenerator(0, 0, 0);
MersenneTwister BuilderBehaviour::m_PseudoRandomGenerator(0);
const double BuilderBehaviour::m_dStandardDeviationCoefficient = 2.5;
const unsigned int BuilderBehaviour::m_uConstructionDuration = 20;

BuilderBehaviour::BuilderBehaviour(Unit * unit)
	: UnitBehaviour(unit)
{
	m_bConstructibleAreaFound = false;
	m_uConstructionProgress = 0;
}


BuilderBehaviour::~BuilderBehaviour(void)
{
}

void BuilderBehaviour::findConstructibleArea()
{
	Location	p1,
				p2,
				goal;

	const Civilization & civi = m_Unit->getCivilization();
	const World & world = civi.getWorld();
	bool constructibleAreaFound = false;
	unsigned int	i = 0,
					mapSize = world.getSize();
	
	m_NormalDistribGenerator.setStandardDeviation(civi.getBuildings().size() * BuilderBehaviour::m_dStandardDeviationCoefficient);

	while(!constructibleAreaFound && i < UnitBehaviour::m_strikesNumber)
	{
		double randomAngle = BuilderBehaviour::m_PseudoRandomGenerator.genrand_real1() * M_PI;
		std::pair<double,double> pair = m_NormalDistribGenerator.getPair();

		p1.setX((unsigned int)(abs(pair.first * cos(randomAngle) + civi.x())) % mapSize);
		p1.setY((unsigned int)(abs(pair.first * sin(randomAngle) + civi.y())) % mapSize);

		p2.setX((unsigned int)(abs(pair.second * cos(randomAngle) + civi.x())) % mapSize);
		p2.setY((unsigned int)(abs(pair.second * sin(randomAngle) + civi.y())) % mapSize);

		if(world.isConstructible(p1))
		{
			goal = p1;
			constructibleAreaFound = true;
		}

		else if(world.isConstructible(p2))
		{
			goal = p2;
			constructibleAreaFound = true;
		}
		++i;
	}

	if(constructibleAreaFound)
	{
		m_bConstructibleAreaFound = m_Unit->findPathArroundTarget(goal);
		if(m_bConstructibleAreaFound)
			m_Unit->setUnitState(UnitStates::moving);
	}
}

void BuilderBehaviour::constructBuilding()
{
	if(m_uConstructionProgress < BuilderBehaviour::m_uConstructionDuration)
		++m_uConstructionProgress;

	else
	{
		Civilization & civi = m_Unit->getCivilization();
		m_uConstructionProgress = 0;
		m_bConstructibleAreaFound = false;
		civi.createBuilding(m_Unit->getUnitTargetLocation());
		m_Unit->setUnitState(UnitStates::nop);
		civi.getBuildersList().remove(m_Unit);
		civi.getFreeUnitsList().push_back(m_Unit);
	}
}

void BuilderBehaviour::execute()
{
	/*qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_BUILDER_MESSAGE;*/

	switch(m_Unit->getUnitState())
	{
	case(UnitStates::nop):

		if(!m_bConstructibleAreaFound)
			findConstructibleArea();
		else
			m_Unit->setUnitState(UnitStates::working);
		break;

	case(UnitStates::moving):
		m_Unit->advanceOnPath();
		break;

	case(UnitStates::working):
		constructBuilding();
		break;
	}
}

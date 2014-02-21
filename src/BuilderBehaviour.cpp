#include "BuilderBehaviour.h"

NormalDistributionGenerator BuilderBehaviour::m_NormalDistribGenerator(0, 0, 0);
MersenneTwister BuilderBehaviour::m_PseudoRandomGenerator(0);

BuilderBehaviour::BuilderBehaviour(Unit * unit)
	: UnitBehaviour(unit)
{
}


BuilderBehaviour::~BuilderBehaviour(void)
{
}

void BuilderBehaviour::findConstructibleArea()
{
	Location	p1,
				p2;

	const Civilization & civi = m_Unit->getCivilization();

	double randomAngle = BuilderBehaviour::m_PseudoRandomGenerator.genrand_real1() * M_PI;
	std::pair<double,double> pair = m_NormalDistribGenerator.getPair();

	p1.setX(pair.first * cos(randomAngle) + civi.x());
	p1.setY(pair.first * sin(randomAngle) + civi.y());
}

void BuilderBehaviour::execute()
{
	//TODO implement the logic of the unit's builder behaviour here.
	//The following peace of code is just a test.
	qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_BUILDER_MESSAGE;
}

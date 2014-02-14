#include "BuilderBehaviour.h"


BuilderBehaviour::BuilderBehaviour(Unit * unit)
	: UnitBehaviour(unit)
{
}


BuilderBehaviour::~BuilderBehaviour(void)
{
}

void BuilderBehaviour::execute()
{
	//TODO implement the logic of the unit's builder behaviour here.
	//The following peace of code is just a test.
	qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_BUILDER_MESSAGE;
}

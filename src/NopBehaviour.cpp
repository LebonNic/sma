#include "NopBehaviour.h"


NopBehaviour::NopBehaviour(Unit * unit)
	: UnitBehaviour(unit)
{
}


NopBehaviour::~NopBehaviour(void)
{
}

void NopBehaviour::execute()
{
	//TODO implement the logic of the unit's nop behaviour here.
	//The following peace of code is just a test.
	qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_NOP_MESSAGE;
}

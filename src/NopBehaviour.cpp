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
	/*qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_NOP_MESSAGE;*/
}

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
	qDebug() << ">		[INFO] Run de l'unit d'ID : " << m_Unit->id();
	qDebug() << ">		[INFO] L'unit est en mode NOP.";
}

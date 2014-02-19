#include "GathererBehaviour.h"


GathererBehaviour::GathererBehaviour(Unit * unit)
	: UnitBehaviour(unit)
{
}


GathererBehaviour::~GathererBehaviour(void)
{
}

void GathererBehaviour::execute()
{
	//TODO implement the logic of the unit's gatherer behaviour here.
	//The following peace of code is just a test.
	qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_GATHERER_MESSAGE;


}

const RessourceType & GathererBehaviour::getFocusedRessource() const
{
	return m_FocusedRessource;
}

void GathererBehaviour::setRessource(RessourceType ressourceType)
{
	m_FocusedRessource = ressourceType;
}

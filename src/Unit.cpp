#include "Unit.h"


Unit::Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x, y, z, behaviour)
{
	m_Civilization = civilization;
	m_State = UnitState::nop;
}

Unit::~Unit()
{
}

void Unit::run()
{
	Agent::run();
}

void Unit::advanceOnPath()
{
	if(!m_Path.empty())
	{
		Node * n = m_Path.front();
		m_Path.remove(m_Path.front());
		this->setLocation(Location(n->x(), n->y(), n->z()));
	}
}

void Unit::updateCivilizationMap()
{
	Location UnitLocation = this->location();
	std::list<Node *> adjacentNodes = (m_Civilization->getWorld().getMap())(UnitLocation.x(), UnitLocation.y())->neighbours();

	for(auto node = adjacentNodes.begin(); node != adjacentNodes.end(); ++node)
	{

	}
}
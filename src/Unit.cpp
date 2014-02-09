#include "Unit.h"


Unit::Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x, y, z, behaviour, civilization)
{
	m_Group = NULL;
}

Unit::~Unit()
{
}

Group * Unit::getGroup() const
{
	return m_Group;
}

void Unit::setGroup(Group * group)
{
	m_Group = group;
}
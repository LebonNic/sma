#include "Unit.h"


Unit::Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x, y, z, behaviour, civilization)
{
}

Unit::~Unit()
{
}

void Unit::run()
{
	Agent::run();
}

void Unit::attack()
{
}

void Unit::build()
{

}

void Unit::harvest()
{
}

void Unit::move()
{
}

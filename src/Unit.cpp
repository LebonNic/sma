#include "Unit.h"


Unit::Unit(double x, double y, double z, Graph *map, Behaviour * behaviour, AgentType type)
	: Agent(x, y, z, map, behaviour, type)
{

}

Unit::~Unit()
{
}
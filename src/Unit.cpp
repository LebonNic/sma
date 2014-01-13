#include "Unit.h"


Unit::Unit(double x, double y, double z, Owner owner, double maxHitPoints)
    : ActiveEntity(x,y,z,owner,maxHitPoints)
{

}
Unit::~Unit(void)
{
}

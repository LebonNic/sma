#include "Ressource.h"


Ressource::Ressource(double x, double y, double z, Owner owner, double quantity)
	: PassiveEntity(PassiveEntityType::ressource,x,y,z,owner,quantity)
{
}
Ressource::~Ressource(void)
{
}

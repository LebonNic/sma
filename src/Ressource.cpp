#include "Ressource.h"


Ressource::Ressource(RessourceType type, double x, double y, double z, double quantity)
	: PassiveEntity(PassiveEntityType::ressource,x,y,z)
{
	setRessourceType(type);
	setQuantity(quantity);
}
Ressource::~Ressource(void)
{
}


void Ressource::setRessourceType(RessourceType type)
{
	m_RessourceType = type;
}
void Ressource::setQuantity(double quantity)
{
	m_dQuantity = quantity;
}


double Ressource::quantity(void) const
{
	return m_dQuantity;
}
RessourceType Ressource::ressourceType(void) const
{
	return m_RessourceType;
}
	
bool Ressource::consume(double quantity)
{
	bool success = false;
	if (quantity > 0 && quantity <= this->quantity())
	{
		success = true;
		setQuantity(this->quantity() - quantity);
	}

	return success;
}
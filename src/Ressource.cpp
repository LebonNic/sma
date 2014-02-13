#include "Ressource.h"


Ressource::Ressource(RessourceType type, double x, double y, double z, double quantity, World * world)
	: PassiveEntity(PassiveEntityType::ressource,x,y,z)
{
	setRessourceType(type);
	setQuantity(quantity);
	setWorld(world);

	if(this->m_RessourceType == RessourceType::wood)
		(m_World->getMap()).addObstacle(this->location());
}

Ressource::~Ressource(void)
{
}

bool Ressource::isConsumed()
{
	return true;
}

void Ressource::setWorld(World * world)
{
	m_World = world;
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
	
double Ressource::consume(double quantity)
{
	if (quantity > 0 && quantity <= this->quantity())
	{
		setQuantity(this->quantity() - quantity);
	}
	return 0;
}
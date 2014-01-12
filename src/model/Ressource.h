#pragma once
#include "PassiveEntity.h"

enum RessourceType
{
	wood,
	gold,
	food
};

class Ressource :
	public PassiveEntity
{
private:
	RessourceType m_RessourceType;

	void setRessourceType(RessourceType type);
	void setQuantity(double quantity);
public:
	Ressource(RessourceType type, double x = 0.0, double y = 0.0, double z = 0.0, Owner owner = Entity::NATURE_OWNER, double quantity = 100.0);
	~Ressource(void);


	double quantity(void);
	RessourceType ressourceType(void);
	
	bool consume(double quantity);
};


#pragma once
#include "PassiveEntity.h"
#include "World.h"

enum RessourceType
{
	wood,
	gold,
	food
};

class World;

class Ressource : public PassiveEntity
{
private:
	RessourceType m_RessourceType;
	double m_dQuantity;
	World * m_World;

	void setRessourceType(RessourceType type);
	void setQuantity(double quantity);
	void setWorld(World * world);
	
public:
	Ressource(RessourceType type, double x, double y, double z, double quantity, World * world);
	~Ressource(void);


	double quantity(void) const;
	
	RessourceType ressourceType(void) const;
	
	double consume(double quantity);
	bool isConsumed();
};


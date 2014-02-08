#pragma once
#include "PassiveEntity.h"

enum RessourceType
{
	wood,
	gold,
	food
};

class Ressource : public PassiveEntity
{
private:
	RessourceType m_RessourceType;
	double m_dQuantity;

	void setRessourceType(RessourceType type);
	void setQuantity(double quantity);
public:
	Ressource(RessourceType type, double x, double y, double z, Graph * map, double quantity);
	~Ressource(void);


	double quantity(void);
	RessourceType ressourceType(void);
	
	bool consume(double quantity);
};


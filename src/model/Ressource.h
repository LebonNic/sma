#pragma once
#include "PassiveEntity.h"

class Ressource :
	public PassiveEntity
{
public:
	Ressource(double x = 0.0, double y = 0.0, double z = 0.0, Owner owner = Entity::NATURE_OWNER, double quantity = 100.0);
	~Ressource(void);
};


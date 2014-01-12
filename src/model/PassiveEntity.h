#pragma once
#include "Entity.h"

enum PassiveEntityType
{
	ressource
};


class PassiveEntity :
	public Entity
{
private:
	PassiveEntityType type;
public:
	PassiveEntity(void);
	~PassiveEntity(void);
};


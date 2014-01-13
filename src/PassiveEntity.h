#pragma once
#include "Entity.h"

enum PassiveEntityType
{
	ressource
};


class PassiveEntity :
	public Entity
{
protected:
	PassiveEntityType m_Type;

	void setType(PassiveEntityType type);
public:
	PassiveEntity(PassiveEntityType type = PassiveEntityType::ressource, double x = 0.0, double y = 0.0, double z = 0.0, Owner owner = Entity::NATURE_OWNER, double quantity = 100.0);
	~PassiveEntity(void);

	PassiveEntityType type(void);
};


#pragma once
#include "Entity.h"

enum PassiveEntityType
{
	ressource
};


class PassiveEntity : public Entity
{
protected:
	PassiveEntityType m_Type;

	void setType(PassiveEntityType type);
public:
	PassiveEntity(PassiveEntityType type, double x, double y, double z);
	~PassiveEntity(void);

	PassiveEntityType type(void);
};


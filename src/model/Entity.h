#pragma once
#include "Location.h"


class Entity
{
private:
	Location *m_Location;
public:
	Entity();
	~Entity();


	double x();
	double y();
	double z();
};


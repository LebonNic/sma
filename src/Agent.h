#pragma once

#include "ActiveEntity.h"
#include "Civilization.h"
#include "Behaviour.h"

class Agent : public ActiveEntity
{
private:
	Civilization * m_Civilisation;
public:
	Agent(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Agent();
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual void harvest() = 0;
	virtual void move()/* = 0*/;
};
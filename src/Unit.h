#pragma once
#include <list>
#include <vector>
#include <string>



#include "Group.h"
#include "Behaviour.h"
#include "Civilization.h"
#include "Agent.h"

class Group;

class Unit : public Agent
{
private:
	Group * m_Group;
public:
	Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization);
	virtual ~Unit();

	Group * getGroup() const;
	void setGroup(Group * group);
	
};


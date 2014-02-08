#pragma once
#include <list>
#include <vector>
#include <string>
#include "ActiveEntity.h"
#include "Attribute.h"
#include "Building.h"
#include "Group.h"
#include "Graph.h"
#include "Node.h"
#include "Ressource.h"
#include "Agent.h"
class Group;

class Unit : public Agent
{
private:
	
public:
	Unit(double x, double y, double z, Behaviour * behaviour);
	virtual ~Unit();
	
};


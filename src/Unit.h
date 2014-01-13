#pragma once
#include <list>
#include <vector>
#include "ActiveEntity.h"
#include "Attribute.h"
#include "Building.h"
#include "Group.h"
#include "Node.h"
#include "Ressource.h"
class Group;


class Unit :
	public ActiveEntity
{
private:
	std::vector<Attribute> m_Attributes;
	std::list<Node *> m_Path;
	std::list<Entity *> m_Objectives;
	Group *m_Group;


	void setAttribute(AttributeId id, double value);
public:
    Unit(double x, double y, double z, Owner owner, double maxHitPoints);
	~Unit(void);


	double attribute(AttributeId id);


	void followPath(void);
	bool moveTo(Node *location);


	// Actions
	void death(void);
	bool gather(Ressource *ressource);
	bool attack(ActiveEntity *entity);
	bool build(Building *building, Node *location);
	bool lookForObjective(void);


	// Group actions
	bool joinGroup(Group *group);
	bool createGroupWith(Unit *unit);
	bool quitGroup(void);
};


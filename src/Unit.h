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
class Group;


class Unit :
	public ActiveEntity
{
private:
	std::vector<Attribute> m_DefaultAttributes;
	std::vector<Attribute> m_Attribute;
	std::list<Node *> m_Path;
	std::list<Entity *> m_Objectives;
	Group *m_Group;

	bool loadUnit(const std::string & filename);
	void setDefaultAttribute(AttributeType id, double value);
	void setAttribute(AttributeType id, double value);
	void initializeAttributes(void);
public:
    Unit(const std::string & filename, double x, double y, double z, Graph *map, Owner owner);


	double attribute(AttributeType id);


	bool followPath(void);
	bool moveTo(const Location & location);


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


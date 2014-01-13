#pragma once
#include <list>
#include "Location.h"
#include "Edge.h"

class Edge;

class Node
{
private:
	Location *m_Location;
	std::list<Edge *> m_Edges;
	Node * m_Father;
	double	m_dFScore,
			m_dGScore,
			m_dHScore;

	void setLocation(Location *location);
public:
	Node(Location *location);
	Node(double x, double y, double z);
	~Node(void);


	double x(void);
	double y(void);
	double z(void);

	Location *location(void);
	const std::list<Edge *> & adjacentEdges(void);
	std::list<Node *> neighbours(void);


	double distanceTo(Node *to);
	void linkTo(Node *to);
	
};


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
	double distanceTo2D(Node *to);
	double diagonalDistanceTo2D(Node *to);
	void addEdge(Edge* edge);
};


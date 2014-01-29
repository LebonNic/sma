#pragma once
#include <list>
#include "Location.h"
#include "Edge.h"

class Edge;

class Node
{
private:
	Location m_Location;
	std::list<Edge *> m_Edges;
	bool m_bReachable;

public:
	Node(const Location & location, bool reachable = true);
	Node(double x, double y, double z, bool reachable = true);
	Node(const Node & n);
	Node & operator =(const Node & n);

	~Node(void);

	double x(void) const;
	double y(void) const;
	double z(void) const;

	Location location(void);
	const std::list<Edge *> & adjacentEdges(void) const;
	const std::list<Node *> neighbours(void) const;

	bool getReachable() const;
	void setReachable(bool reachable);

	double distanceTo(Node *to);
	double distanceTo2D(Node *to);
	double diagonalDistanceTo2D(Node *to);
	void addEdge(Edge* edge);
};


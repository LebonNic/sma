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

	Location location(void) const;
	const std::list<Edge *> & adjacentEdges(void) const;
	std::list<Node *> neighbours(void) const;

	bool isReachable() const;
	void setReachable(bool reachable);

	double distanceTo(Node *to) const;
	double distanceTo2D(Node *to) const;
	double diagonalDistanceTo2D(Node *to) const;
	void addEdge(Edge* edge);
};


#pragma once
#include <list>
#include "Node.h"
#include "Edge.h"

class Graph
{
private:
	std::list<Node *> m_Nodes;
	std::list<Edge *> m_Edges;
public:
	Graph(void);
	~Graph(void);


	std::list<Node *> nodes(void);
	std::list<Edge *> edges(void);


	void addNode(Node *node);
	void addNode(double x, double y, double z);
	void linkNodeFromTo(Node *from, Node *to);
};


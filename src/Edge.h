#pragma once
#include <algorithm>
#include "Node.h"

class Node;


class Edge
{
private:
	double m_dLength;
	double m_dCost;
	Node *m_From;
	Node *m_To;
	bool m_bDirected;

	void setLength(double length);
	void setCost(double cost);
	void setFrom(Node *from);
	void setTo(Node *to);
	void setDirected(bool directed);
public:
	Edge(Node *from, Node *to, bool directed = false);
	~Edge(void);

	double length(void);
	double cost(void);
	Node *from(void);
	Node *to(void);
	bool isDirected(void);


	void setUnreachable(void);
};


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

	double getFScore(void) const;
	double getGScore(void) const;
	double getHScore(void) const;

	void setFScore(double fScore);
	void setGScore(double gScore);
	void setHScore(double hScore);

	Node * getFather() const;
	void setFather(Node * father);

	Location *location(void);
	const std::list<Edge *> & adjacentEdges(void);
	std::list<Node *> neighbours(void);


	double distanceTo(Node *to);
	void linkTo(Node *to);

	class ComparaisonOperator
	{
	private:
		bool m_bReverse;
	public:
		ComparaisonOperator(const bool reverse = false) {m_bReverse = reverse;}
		bool operator()(const Node * nodeA, const Node * nodeB) const
		{
			if(m_bReverse)
				return nodeA->m_dFScore > nodeB->m_dFScore;
			else
				return nodeA->m_dFScore < nodeB->m_dFScore;
		}
	};
};


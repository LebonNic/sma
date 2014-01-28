#include "Node.h"
using namespace std;


Node::Node(Location *location)
{
	m_Location = location;
}
Node::Node(double x, double y, double z)
{
	m_Location = new Location(x,y,z);
}
Node::~Node(void)
{
	delete m_Location;
}


double Node::x(void)
{
	return this->m_Location->x();
}
double Node::y(void)
{
	return this->m_Location->y();
}
double Node::z(void)
{
	return this->m_Location->z();
}

Location *Node::location(void)
{
	return this->m_Location;
}
const list<Edge *> & Node::adjacentEdges(void)
{
	return this->m_Edges;
}
list<Node *> Node::neighbours(void)
{
	list<Node *> neighbours;
	for(auto it = m_Edges.begin(); it != m_Edges.end(); ++it)
	{
		if (this == (*it)->to())
			neighbours.push_back((*it)->from());
		else
			neighbours.push_back((*it)->to());
	}
	return neighbours;
}

double Node::distanceTo(Node *to)
{
	double dx = to->x() - x();
	double dy = to->y() - y();
	//double dz = to->z() - z();

	return sqrt(dx*dx + dy*dy /*+ dz*dz*/);
}
void Node::addEdge(Edge* edge)
{
	m_Edges.push_back(edge);
}

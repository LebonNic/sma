#include "Node.h"
using namespace std;

Node::Node(const Location & location, bool reachable)
{
	m_Location = location;
	m_bReachable = reachable;
}

Node::Node(double x, double y, double z, bool reachable)
{
	m_Location.setX(x);
	m_Location.setY(y);
	m_Location.setZ(z);
	m_bReachable = reachable;
}

Node::~Node(void)
{
}

Node::Node(const Node & n)
{
	m_Location = n.m_Location;
	m_Edges = n.m_Edges;
	m_bReachable = n.m_bReachable;
}

Node & Node::operator =(const Node & n)
{
	if(this != &n)
	{
		m_Location = n.m_Location;
		m_Edges = n.m_Edges;
	}
	return *this;
}

double Node::x(void) const
{
	return this->m_Location.x();
}
double Node::y(void) const
{
	return this->m_Location.y();
}
double Node::z(void) const
{
	return this->m_Location.z();
}

Location Node::location(void)
{
	return this->m_Location;
}

const list<Edge *> & Node::adjacentEdges(void) const
{
	return this->m_Edges;
}

const list<Node *> Node::neighbours(void) const
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
	double dz = to->z() - z();

	return sqrt(dx*dx + dy*dy + dz*dz);
}

double Node::distanceTo2D(Node *to)
{
	double dx = to->x() - x();
	double dy = to->y() - y();

	return sqrt(dx*dx + dy*dy);
}

double Node::diagonalDistanceTo2D(Node *to)
{
	double	dx = abs(this->x() - to->x()),
			dy = abs(this->y() - to->y());

	return std::max(dx, dy);
}

void Node::addEdge(Edge* edge)
{
	m_Edges.push_back(edge);
}

bool Node::getReachable() const
{
	return m_bReachable;
}

void Node::setReachable(bool reachable)
{
	m_bReachable = reachable;
}
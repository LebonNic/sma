#include "Graph.h"
using namespace std;


Graph::Graph(void)
{
}
Graph::~Graph(void)
{
	// Delete Nodes
	for(auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it)
	{
		delete (*it);
	}
	// Delete Edges
	for(auto it = m_Edges.begin(); it != m_Edges.end(); ++it)
	{
		delete (*it);
	}
}


list<Node *> Graph::nodes(void)
{
	return m_Nodes;
}
list<Edge *> Graph::edges(void)
{
	return m_Edges;
}


void Graph::addNode(Node *node)
{
	if(find(m_Nodes.begin(), m_Nodes.end(), node) == m_Nodes.end())
	{
		m_Nodes.push_back(node);
	}
}
void Graph::addNode(double x, double y, double z)
{
	Node *node = new Node(x,y,z);
	m_Nodes.push_back(node);
}
void Graph::linkNodeFromTo(Node *from, Node *to)
{
	this->addNode(from);
	this->addNode(to);
	from->linkTo(to);
}
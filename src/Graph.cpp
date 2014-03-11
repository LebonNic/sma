/**
 * @file Graph.cpp
 * @brief Graph class definition
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */


#include "Graph.h"
using namespace std;

Graph::Graph(unsigned int size)
{
	setWidth(size);
	setHeight(size);
	m_PathFinder = new PathFinder(size);

	m_Nodes = vector<vector<Node *>>(size);

	for (unsigned int i = 0; i < size; ++i)
	{
		m_Nodes[i] = vector<Node *>(size);
	}

	for(unsigned int i = 0; i < size; ++i)
		for(unsigned int j = 0; j < size; ++j)
			m_Nodes[i][j] = new Node(i,j);

	for(unsigned int i = 0; i < size; ++i)
		for(unsigned int j = 0; j < size - 1; ++j)
			this->linkNodeFromTo(m_Nodes[i][j], m_Nodes[i][j+1]);

	for(unsigned int j = 0; j  < size; ++j )
		for(unsigned int i = 0; i < size - 1; ++i)
			this->linkNodeFromTo(m_Nodes[i][j], m_Nodes[i+1][j]);

	//Parcours en diagonale du graphe
	for(unsigned int slice = 0; slice < size + size - 1; ++slice)
	{
		unsigned int z = slice < size ? 0 : slice - size + 1;

		for(unsigned int j = z; j < slice - z; ++j)
		{
			this->linkNodeFromTo(m_Nodes[j][slice - j], m_Nodes[j + 1][slice - j - 1]);
		}
	}

	//Parcours en diagonale du graphe
	int zbis = 0;
	for(int slice = size + size - 2; slice >=0 ; --slice)
	{
		int z;

		if(slice >= (int)(size - 1))
		{
			z = (slice - size + 1);
		}
		else
		{
			z = 0;
			zbis--;
		}

		for(int j = z; j < slice - z; ++j)
		{
			this->linkNodeFromTo(m_Nodes[slice - j][slice - j - z - zbis], m_Nodes[slice - j - 1][slice - j - z - zbis - 1]);
		}
	}
}


Graph::~Graph(void)
{
	destroy();
}

void Graph::destroy(void)
{
	// Delete Nodes
	for(unsigned int i = 0; i < m_Nodes.size(); ++i)
		for(unsigned int j = 0; j < m_Nodes[i].size(); ++j)
			delete m_Nodes[i][j];

	// Delete Edges
	for(auto it = m_Edges.begin(); it != m_Edges.end(); ++it)
	{
		delete (*it);
	}

	delete m_PathFinder;
	
}

const PathFinder & Graph::getPathFinder() const
{
	return (*m_PathFinder);
}

void Graph::setWidth(unsigned int width)
{
	this->m_uWidth = width;
}

void Graph::setHeight(unsigned int height)
{
	this->m_uHeight = height;
}

Node * Graph::operator()(unsigned int i, unsigned int j) const
{
	if(i < m_uHeight && j < m_uWidth)
	{
		return m_Nodes[i][j];
	}
	else
		throw runtime_error("Out of range in the graph's nodes array.");
}

const std::vector<std::vector<Node *>> & Graph::nodes(void)
{
	return m_Nodes;
}

list<Edge *> Graph::edges(void)
{
	return m_Edges;
}

unsigned int Graph::size(void) const
{
	return m_uHeight;
}

Node *Graph::addNode(unsigned int x, unsigned int y, double z)
{
	Node *node = new Node(x,y,z);
	m_Nodes[x][y] = node; //TODO attention au cast implicite

	return node;
}

void Graph::linkNodeFromTo(Node *from, Node *to)
{
	Edge *edge = new Edge(from,to);
	this->m_Edges.push_back(edge);
	from->addEdge(edge);
	to->addEdge(edge);
}

bool CompareScore(const Score & a, const Score & b)
{
	return a.m_dFScore < b.m_dFScore;
}

std::list<Node *> Graph::findPathFromTo(Node * from, Node * to)
{
	return m_PathFinder->findPathFromTo(from, to);
}

void Graph::generateRandomPerlin(double scale, unsigned int seed)
{
    PerlinNoise noise(seed);
	for(unsigned int y = 0; y < m_uHeight; ++y)
	{
        for(unsigned int x = 0; x < m_uWidth; ++x)
		{
			double z = noise.noise(x * scale, y * scale, 0.5);
			m_Nodes[x][y]->setZ(z);
		}
	}
}

void Graph::addObstacle(const Location & l)
{
	m_Nodes[(unsigned int) l.x()][(unsigned int) l.y()]->setReachable(false);
}

void Graph::removeObstacle(const Location & l)
{
	m_Nodes[(unsigned int) l.x()][(unsigned int) l.y()]->setReachable(true);
}

void Graph::removeObstacle(unsigned int x, unsigned int y)
{
	m_Nodes[x][y]->setReachable(true);
}

void Graph::addObstacle(unsigned int x, unsigned int y)
{
	m_Nodes[x][y]->setReachable(false);
}
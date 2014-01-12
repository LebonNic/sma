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


void Graph::setWidth(unsigned int width)
{
	this->m_uWidth = width;
}
void Graph::setHeight(unsigned int height)
{
	this->m_uHeight = height;
}


list<Node *> Graph::nodes(void)
{
	return m_Nodes;
}
list<Edge *> Graph::edges(void)
{
	return m_Edges;
}
unsigned int Graph::width(void)
{
	return m_uWidth;
}
unsigned int Graph::height(void)
{
	return m_uHeight;
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


void Graph::generateRandomPerlin(double xSize, double ySize, double scale, unsigned int seed)
{
	double x = 0.0;
	double y = 0.0;
	PerlinNoise noise(rand());

	setWidth((unsigned int) xSize);
	setHeight((unsigned int) ySize);
	for(x = 0.0; x < xSize; x+=1.0)
	{
		for(y = 0.0; y < ySize; y+=1.0)
		{
			double z = noise.noise(x * scale, y * scale, 0.5);
			this->addNode(x,y,z);
		}
	}
}


vector<vector<unsigned int>> Graph::heightMap(void)
{
	// Allocate heightMap
	vector<vector<unsigned int>> heightMap(this->width());
	for (unsigned int i = 0; i < this->width(); ++i)
	{
		vector<unsigned int> vector(this->height());
		heightMap[i] = vector;
	}

	// Set z value for the heightMap
	for (auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it)
	{
		unsigned int x = (unsigned int) (*it)->x();
		unsigned int y = (unsigned int) (*it)->y();
		unsigned int z = (unsigned int) ((*it)->z()*16);
		heightMap[x][y] = z;
	}

	return heightMap;
}
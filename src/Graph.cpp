#include "Graph.h"
using namespace std;

Graph::Graph(void)
{
}
Graph::~Graph(void)
{
	// Delete Nodes
	for(unsigned int i = 0; i < m_uHeight; ++i)
		for(unsigned int j = 0; j < m_uWidth; ++j)
			delete m_Nodes[i][j];

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

Node Graph::operator()(unsigned int i, unsigned int j) const
{
	if(i < m_uHeight && j < m_uWidth)
	{
		return *(m_Nodes[i][j]);
	}
	else
		throw runtime_error("Out of range in the graph's nodes array.");
}

std::vector<std::vector<Node *>> Graph::nodes(void)
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

Node *Graph::addNode(double x, double y, double z)
{
	Node *node = new Node(x,y,z);
	m_Nodes[x][y] = node;

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
	return m_PathFinder.findPathFromTo(from, to);
}

void Graph::generateRandomPerlin(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed)
{
    PerlinNoise noise(seed);
	m_Nodes = vector<vector<Node *>>(xSize);
	for (unsigned int i = 0; i < xSize; ++i)
	{
		m_Nodes[i] = vector<Node *>(ySize);
	}

	setWidth(xSize);
	setHeight(ySize);
    for(unsigned int y = 0; y < ySize; ++y)
	{
        for(unsigned int x = 0; x < xSize; ++x)
		{
			double z = noise.noise(x * scale, y * scale, 0.5);
			m_Nodes[x][y] = this->addNode(x,y,z);
		}
	}

	for(unsigned int i = 0; i < xSize; ++i)
		for(unsigned int j = 0; j < ySize - 1; ++j)
			this->linkNodeFromTo(m_Nodes[i][j], m_Nodes[i][j+1]);

	for(unsigned int j = 0; j  < ySize; ++j )
		for(unsigned int i = 0; i < xSize - 1; ++i)
			this->linkNodeFromTo(m_Nodes[i][j], m_Nodes[i+1][j]);

	////Parcours en diagonale du graphe
	for(unsigned int slice = 0; slice < xSize + ySize - 1; ++slice)
	{
		unsigned int z = slice < xSize ? 0 : slice - xSize + 1;

		for(unsigned int j = z; j < slice - z; ++j)
		{
			this->linkNodeFromTo(m_Nodes[j][slice - j], m_Nodes[j + 1][slice - j - 1]);
		}
	}

	int zbis = 0;
	for(int slice = xSize + ySize - 2; slice >=0 ; --slice)
	{
		int z;

		if(slice >= (int)(xSize - 1))
		{
			z = (slice - xSize + 1);
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

	this->findPathFromTo(m_Nodes[0][0], m_Nodes[14][25]);
}

//vector<vector<unsigned int>> Graph::heightMap(void)
//{
//	// Allocate heightMap
//	vector<vector<unsigned int>> heightMap(this->width());
//	for (unsigned int i = 0; i < this->width(); ++i)
//	{
//		vector<unsigned int> vector(this->height());
//		heightMap[i] = vector;
//	}
//
//	// Set z value for the heightMap
//	for (auto it = m_Nodes.begin(); it != m_Nodes.end(); ++it)
//	{
//		unsigned int x = (unsigned int) (*it)->x();
//		unsigned int y = (unsigned int) (*it)->y();
//		unsigned int z = (unsigned int) ((*it)->z()*16);
//		heightMap[x][y] = z;
//	}
//
//	return heightMap;
//}

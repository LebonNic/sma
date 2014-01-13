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
Node *Graph::addNode(double x, double y, double z)
{
	Node *node = new Node(x,y,z);
	m_Nodes.push_back(node);

	return node;
}
void Graph::linkNodeFromTo(Node *from, Node *to)
{
	this->addNode(from);
	this->addNode(to);
	from->linkTo(to);
}

void findPathFromTo(Node * from, Node * to)
{
	bool goalReached = false;
	std::priority_queue<Score, std::vector<Score>, Score::CompareScore> openSet;
	std::list<Score> closedSet;

	Score startingNode;

	startingNode.m_N = from ;
	startingNode.m_dGScore = 0 ;
	startingNode.m_dFScore = startingNode.m_dGScore + startingNode.m_N->distanceTo(to) ;
	
	openSet.push(startingNode);

	while(!openSet.empty() && !goalReached)
	{
		Score currentNode = openSet.top();

		if(currentNode.m_N == to)
		{
			goalReached = true;
		}
		else
		{
			openSet.pop();
			closedSet.push_back(currentNode);
			
			std::list<Node *> neighboursList = currentNode.m_N->neighbours();
			for(list<Node *>::iterator neighbour = neighboursList.begin(); neighbour != neighboursList.end(); ++neighbour)
			{
				Score neighbourNode;
				neighbourNode.m_N = *neighbour;
				if(std::find(closedSet.begin(), closedSet.end(), neighbourNode) != closedSet.end())
				{
					double possibleGScore = currentNode.m_dGScore + currentNode.m_N->distanceTo(*neighbour); // ou currentNode.m_N->distanceTo(neighbourNode.m_N)

					if(possibleGScore  < neighbourNode.m_dGScore) //Il manque le test "neighbor not in openset"
					{
						neighbourNode.m_Father = currentNode.m_N;
						neighbourNode.m_dGScore = possibleGScore;
						neighbourNode.m_dFScore = neighbourNode.m_dGScore + neighbourNode.m_N->distanceTo(to);
						openSet.push(neighbourNode);
					}
				}
			}
		}
	}
}

void Graph::generateRandomPerlin(unsigned int xSize, unsigned int ySize, double scale, unsigned int seed)
{
    PerlinNoise noise(seed);
	vector<vector<Node *>> nodeGrid(xSize);
	for (unsigned int i = 0; i < xSize; ++i)
	{
		vector<Node *> nodeRow(ySize);
		nodeGrid[i] = nodeRow;
	}

	setWidth(xSize);
	setHeight(ySize);
    for(unsigned int y = 0; y < ySize; ++y)
	{
        for(unsigned int x = 0; x < xSize; ++x)
		{
			double z = noise.noise(x * scale, y * scale, 0.5);
			nodeGrid[x][y] = this->addNode(x,y,z);
		}
	}

	for(unsigned int i = 0; i < xSize; ++i)
	{
		for(unsigned int j = 0; j < ySize; ++j)
		{
			if(i > 0)
			{
				nodeGrid[i][j]->linkTo(nodeGrid[i-1][j]);
				if(j > 0)
					nodeGrid[i][j]->linkTo(nodeGrid[i-1][j-1]);
			}
			if(j > 0)
			{
				nodeGrid[i][j]->linkTo(nodeGrid[i][j-1]);
				if (i < xSize - 1)
					nodeGrid[i][j]->linkTo(nodeGrid[i+1][j-1]);
			}

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

#pragma once
#include <list>
#include <vector>
#include <Windows.h>
#include <queue>
#include <algorithm>
#include "PathFinder.h"
#include "Node.h"
#include "Edge.h"
#include "PerlinNoise.h"
#include "Score.h"

class Graph
{
private:
	std::vector<std::vector<Node *>> m_Nodes;
	std::list<Edge *> m_Edges;
	unsigned int m_uWidth;
	unsigned int m_uHeight;
	PathFinder m_PathFinder;


void setWidth(unsigned int width);
void setHeight(unsigned int height);
public:
	Graph(void);
	~Graph(void);

	const std::vector<std::vector<Node *>> & nodes(void);
	std::list<Edge *> edges(void);
	unsigned int width(void);
	unsigned int height(void);
	Node * operator()(unsigned int i, unsigned int j) const;

	Node *addNode(double x, double y, double z);
	void linkNodeFromTo(Node *from, Node *to);
	std::list<Node *> findPathFromTo(Node * from, Node * to);
	void addObstacle(const Location & l);
	void addObstacle(unsigned int x, unsigned int y);

	void generateRandomPerlin(unsigned int size, double scale = 1.0, unsigned int seed = 0);
	const PathFinder & getPathFinder() const;

	/*std::vector<std::vector<unsigned int>> heightMap(void);*/
};


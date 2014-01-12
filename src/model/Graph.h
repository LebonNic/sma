#pragma once
#include <list>
#include <Windows.h>
#include "Node.h"
#include "Edge.h"
#include "PerlinNoise.h"

class Graph
{
private:
	std::list<Node *> m_Nodes;
	std::list<Edge *> m_Edges;
	unsigned int m_uWidth;
	unsigned int m_uHeight;


void setWidth(unsigned int width);
void setHeight(unsigned int height);
public:
	Graph(void);
	~Graph(void);


	std::list<Node *> nodes(void);
	std::list<Edge *> edges(void);
	unsigned int width(void);
	unsigned int height(void);


	void addNode(Node *node);
	void addNode(double x, double y, double z);
	void linkNodeFromTo(Node *from, Node *to);


	void generateRandomPerlin(double xSize, double ySize, double scale = 1.0, unsigned int seed = 0);


	std::vector<std::vector<unsigned int>> heightMap(void);
};


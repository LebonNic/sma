/**
 * @file Graph.h
 * @brief Graph class declaration
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

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

/**
 *	@brief The Graph class
 *	
 *	This class manages different sets of data in order to propose an interface to manipulate a square grid graph.
 *	The class stores a matrix of nodes and a list of edges. It has a width and an height. And finally,
 *	it uses a PathFinder object to calculate the shortest path between two nodes. 
 */
class Graph
{
private:
	std::vector<std::vector<Node *>> m_Nodes;	//!< @brief A nodes matrix 
	std::list<Edge *> m_Edges;					//!< @brief A edges list
	unsigned int m_uWidth;						//!< @brief The matrix's width
	unsigned int m_uHeight;						//!< @brief The matrix's height
	PathFinder * m_PathFinder;					//!< @brief A pathfinder object used to calculate shortest paths

	/**
     * @brief setWidth Sets the graph's width
	 * @param width The new graph's width
     */
	void setWidth(unsigned int width);

	/**
     * @brief setHeight Sets the graph's height
	 * @param height The new graph's height
     */
	void setHeight(unsigned int height);

	/**
     * @brief addNode Add a node to the graph's matrix 
	 * @param x The row index
	 * @param y The column index
	 * @param z The node's elevation
     * @return A pointer on the added node
     */
	Node * addNode(unsigned int x, unsigned int y, double z);

	/**
     * @brief linkNodeFromTo Create an edge between the two nodes passed as parameter
	 * @param from The edge's incoming node
	 * @param to The edge's outgoing node
     */
	void linkNodeFromTo(Node *from, Node *to);

	/**
     * @brief destroy Processes memory cleannig
     */
	void destroy(void);
public:

	/**
     * @brief Graph Default constructor
     */
	Graph(unsigned int size);

	/**
     * @brief ~Graph Destructor
     */
	~Graph(void);

	/**
     * @brief nodes Gets the graph's nodes matrix
     * @return The graph's nodes matrix
     */
	const std::vector<std::vector<Node *>> & nodes(void);

	/**
     * @brief edges Gets the graph's edges list
     * @return The graph's edges list
     */
	std::list<Edge *> edges(void);

	/**
     * @brief size Gets the graph's size
     * @return The graph's size
     */
	unsigned int size(void) const;

	/**
     * @brief getPathFinder Gets the graph's PathFinder object
     * @return The graph's PathFinder object
     */
	const PathFinder & getPathFinder() const;

	/**
     * @brief operator() Gets a particular node from the graph identified by a row and a column index
	 * @param i The row index
	 * @param j The column index
     * @return The node specified by the row and the column
	 * @throws runtime_error Throws a runtime error if the indexes are out of the matrix range
     */
	Node * operator()(unsigned int i, unsigned int j) const;

	/**
     * @brief findPathFromTo Calculates the shortest path between two nodes of the graph
	 * @param from The starting node
	 * @param to The node goal
	 * @return A list of nodes that links the starting and the goal node.
     */
	std::list<Node *> findPathFromTo(Node * from, Node * to);

	/**
     * @brief addObstacle Sets the node specified by the location passed as parameter to unreachable
	 * @param l The node's location to transform in obstacle
     */
	void addObstacle(const Location & l);

	/**
     * @brief addObstacle Sets the node specified by the x and y coordinates to unreachable
	 * @param x The row index of the node to transform in obstacle
	 * @param y The column index of the node to transform in obstacle
     */
	void addObstacle(unsigned int x, unsigned int y);

	/**
     * @brief removeObstacle Sets the node specified by the location passed as parameter to reachable
	 * @param l The node's location
     */
	void removeObstacle(const Location & l);

	/**
     * @brief removeObstacle Sets the node specified by the x and y coordinates to reachable
	 * @param x The row index of the node
	 * @param y The column index of the node
     */
	void removeObstacle(unsigned int x, unsigned int y);

	/**
     * @brief generateRandomPerlin Generates a map using a Perlin noise to set the nodes' elevation
	 * @param size The square grid graph
	 * @param scale A scale value to control the spacing between nodes
	 * @param seed A seed to initialize the generator used to create the Perlin noise
     */
	void generateRandomPerlin(double scale = 1.0, unsigned int seed = 0);

	/*std::vector<std::vector<unsigned int>> heightMap(void);*/
};


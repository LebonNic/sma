/**
 * @file Node.h
 * @brief Node class declaration
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#pragma once
#include <list>
#include "Location.h"
#include "Edge.h"

class Edge;

/**
 *	@brief The Node class
 *	
 *	This class is a part of a graph data structure. It is used to store a set
 *	of informations concerning a node. The Graph class uses a matrix of Node.
 */
class Node
{
private:
	Location m_Location;		//!< @brief The node's location 
	std::list<Edge *> m_Edges;	//!< @brief The list of edges linked to the node
	bool m_bReachable;			//!< @brief A boolean value to indicate if the node is reachable or not 

public:

	/**
     * @brief Node constructor
	 * @param location The location of the node
	 * @param reachable The boolean to specify if the node is reachable or not
	*/
	Node(const Location & location, bool reachable = true);

	/**
     * @brief Node constructor
	 * @param x The x coordinate of the node
	 * @param y The y coordinate of the node
	 * @param z The z coordinate of the node (elevation)
	 * @param reachable The boolean to specify if the node is reachable or not
	*/
	Node(double x, double y, double z, bool reachable = true);

	/**
     * @brief Node copy constructor
	 * @param n The node to copy on the instanciation
	*/
	Node(const Node & n);

	/**
     * @brief operator = Affectation operator
	 * @param n The node to copy on the affectation
	*/
	Node & operator =(const Node & n);

	/**
     * @brief ~Graph Destructor
     */
	~Node(void);

	/**
     * @brief x Gets the x coordinate of the node
     * @return The x coordinate of the node
     */
	double x(void) const;

	/**
     * @brief y Gets the y coordinate of the node
     * @return The y coordinate of the node
     */
	double y(void) const;

	/**
     * @brief z Gets the z coordinate of the node
     * @return The z coordinate of the node
     */
	double z(void) const;

	/**
     * @brief location Gets the node's coordinates as a Location object
     * @return The location of the node
     */
	Location location(void) const;

	/**
     * @brief adjacentEdges Gets the adjacent edges of the node
     * @return A list of adjacent edges
     */
	const std::list<Edge *> & adjacentEdges(void) const;

	/**
     * @brief neighbours Gets the adjacent nodes of the current object
     * @return A list of adjacent nodes
     */
	std::list<Node *> neighbours(void) const;

	/**
     * @brief isReachable Says if the node is reachable or not
     * @return A boolean value that indicates if the node is reachable or not
     */
	bool isReachable() const;

	/**
     * @brief setReachable	Sets the value that indicates if the node is reachable or not
	 *						with the boolean passed as parameter
	 * @param reachable		The boolean value that specifies if the node is reachable or not
     */
	void setReachable(bool reachable);

	/**
     * @brief distanceTo Computes the euclidean distance between the current node and the one which is passed as parameter
	 * @param to The node used to compute the distance
     * @return The euclidean ditance between the nodes
     */
	double distanceTo(Node *to) const;

	/**
     * @brief distanceTo2D Computes the euclidean distance between the current node and the one which is passed as parameter.
	 * But it compares 
	 * @param to The node used to compute the distance
     * @return The euclidean ditance between the nodes
     */
	double distanceTo2D(Node *to) const;
	double diagonalDistanceTo2D(Node *to) const;
	void addEdge(Edge* edge);
};


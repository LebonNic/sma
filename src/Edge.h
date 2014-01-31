/**
 * @file Edge.h
 * @brief Edge class declaration
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#pragma once
#include <algorithm>
#include "Node.h"

class Node;

/**
 *	@brief The Edge class
 *	
 *	This class is a part of a graph data structure. It is used to store different
 *	informations about an edge that links two nodes from a graph.
 */
class Edge
{
private:
	double m_dLength;	//!< @brief Distance between the two nodes that the edge links 
	double m_dCost;		//!< @brief The cost to cross the edge
	Node *m_From;		//!< @brief One of the two nodes that the edge links 
	Node *m_To;			//!< @brief One of the two nodes that the edge links 
	bool m_bDirected;	//!< @brief Specifies if the edge is directed or not

	/**
     * @brief setLength Sets the edge's length
	 * @param length The new edge's length
     */
	void setLength(double length);

	/**
     * @brief setCost Sets the edge's cost
	 * @param cost The new edge's cost
     */
	void setCost(double cost);

	/**
     * @brief setFrom Sets the edge's incoming node
	 * @param from The edge's incoming node
     */
	void setFrom(Node *from);

	/**
     * @brief setTo Sets the edge's outgoing node
	 * @param from The edge's outgoing node
     */
	void setTo(Node *to);

	/**
     * @brief setDirected Defines if the edge is directed or not
	 * @param directed The boolean value that specifies  if the edge is directed or not
     */
	void setDirected(bool directed);
public:

	/**
     * @brief Edge Default constructor
	 * @param from The edge's incoming node
	 * @param to The edge's outgoing node
	 * @param directed A The boolean value that specifies if the edge is directed or not
     */
	Edge(Node *from, Node *to, bool directed = false);

	/**
     * @brief ~Edge Destructor
     */
	~Edge(void);

	/**
     * @brief length Gets the edge's length
     * @return Edge's length
     */
	double length(void);

	/**
     * @brief cost Gets the edge's cost
     * @return Edge's cost
     */
	double cost(void);

	/**
     * @brief from Gets the edge's incoming node
     * @return Edge's incoming node
     */
	Node *from(void);

	/**
     * @brief to Gets the edge's outgoing node
     * @return Edge's outgoing node
     */
	Node *to(void);

	/**
     * @brief isDirected Gets the edge's status
     * @return The boolean value that indicates if the edge is directed or not
     */
	bool isDirected(void);

	/**
     * @brief setUncrossable Sets the edge's cost to the maximum value of an int in order to make it uncrossable
     */
	void setUncrossable(void);
};


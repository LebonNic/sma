/**
 * @file Edge.cpp
 * @brief Edge class definition
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Edge.h"
using namespace std;


Edge::Edge(Node *from, Node *to, bool directed)
{
	setFrom(from);
	setTo(to);
	setDirected(directed);
	setLength(from->distanceTo(to));
	setCost(abs(from->z()-to->z()));
}
Edge::~Edge(void)
{
}



void Edge::setLength(double length) 
{ 
	this->m_dLength = length; 
}
void Edge::setCost(double value) 
{
	this->m_dCost = value;
}
void Edge::setFrom(Node *from)
{
	this->m_From = from;
}
void Edge::setTo(Node *to)
{
	this->m_To = to;
}
void Edge::setDirected(bool directed)
{
	this->m_bDirected = directed;
}



double Edge::length(void)
{
	return this->m_dLength;
}
double Edge::cost(void)
{
	return this->m_dCost;
}
Node *Edge::from(void)
{
	return this->m_From;
}
Node *Edge::to(void)
{
	return this->m_To;
}
bool Edge::isDirected(void)
{
	return this->m_bDirected;
}



void Edge::setUncrossable(void)
{
	setCost(numeric_limits<double>::infinity());
}
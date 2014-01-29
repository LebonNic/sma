#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <vector>
#include <algorithm>
#include "Node.h"
#include "Score.h"

class PathFinder
{
private:
	Score	m_StartingNode,
			m_Goal;

	std::vector<Score *>	m_OpenSet,
							m_ClosedSet;

	std::list<Node *> m_Path;

	bool m_bGoalReached;

	void processMemoryCleaning();
	void setStartingNode(Node * node);
	void setGoal(Node * node);
	double computeMovingCost(const Score & current, const Score & next);
	double computeHScore(const Score & current);
	std::list<Node *> reconstructPath(void);
	
public:

	PathFinder(void);
	~PathFinder(void);
	std::list<Node *> findPathFromTo(Node * from, Node * to);
	const std::vector<Score *> & getOpenSet() const;
	const std::vector<Score *> & getClosedSet() const;
	Node * getStartingNode(void)const;
	Node * getGoal(void) const;
	
};

#endif
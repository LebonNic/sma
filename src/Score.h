#pragma once
#include "Node.h"

class Score
{
public:
	Node	* m_N,
			* m_Father;
	double	m_dFScore,
			m_dGScore,
			m_dHScore;

	Score(Node * n, double gScore);
	Score();
	Score(const Score & s);
	Score & operator=(const Score & s);
	bool operator==(const Score & s);

	/*class CompareScore
	{
		public: 
			CompareScore(){}
		bool operator()(const Score & a, const Score & b) const
		{
			return a.m_dFScore < b.m_dFScore;
		}
	};*/
};


#pragma once
#include "Node.h"

class Score
{
public:
	Node	* m_N;
	Score	* m_Father;

	double	m_dFScore,
			m_dGScore;

	Score(Node * n, double gScore);
	Score();
	Score(const Score & s);
	Score & operator=(const Score & s);
	bool operator==(const Score & s);

	class CompareScoreByPointer
	{
	private:
		const Score * m_Score;

	public:
		explicit CompareScoreByPointer(const Score * score){ m_Score = score; }

		bool operator()(const Score * otherScore) const
		{
			return m_Score->m_N == otherScore->m_N;
		}
	};

};



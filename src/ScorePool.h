#pragma once

#include <vector>
#include <stdexcept>
#include "Score.h"
class ScorePool
{
private:
	std::list<Score *>		m_AvailableScores,
							m_UsedScores;
public:
	ScorePool(unsigned int size);
	~ScorePool(void);

	Score * getAvailableScore();
	Score * getAvailableScore(const Score & s);
	void resetPool();
};


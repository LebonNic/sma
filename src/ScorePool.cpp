#include "ScorePool.h"

ScorePool::ScorePool(unsigned int size)
{
	for(unsigned int i = 0; i < size; ++i)
		m_AvailableScores.push_back(new Score());
}

ScorePool::~ScorePool(void)
{
	for(auto score = m_AvailableScores.begin(); score != m_AvailableScores.end(); ++score)
		delete (*score);

	for(auto score = m_UsedScores.begin(); score != m_UsedScores.end(); ++score)
		delete (*score);
}

Score * ScorePool::getAvailableScore()
{
	Score * score;

	if(!m_AvailableScores.empty())
	{
		score = m_AvailableScores.front();
		m_AvailableScores.pop_front();
		m_UsedScores.push_back(score);
	}
	else
		throw std::runtime_error("No more free scores are available.");

	return score;
}

Score * ScorePool::getAvailableScore(const Score & s)
{
	Score * score;

	if(!m_AvailableScores.empty())
	{
		score = m_AvailableScores.front();
		(*score) = s;
		m_AvailableScores.pop_front();
		m_UsedScores.push_back(score);
	}
	else
		throw std::runtime_error("No more free scores are available.");

	return score;
}

void ScorePool::resetPool()
{
	Score * score;
	while(!m_UsedScores.empty())
	{
		score = m_UsedScores.front();
		m_UsedScores.pop_front();
		m_AvailableScores.push_back(score);
	}
}

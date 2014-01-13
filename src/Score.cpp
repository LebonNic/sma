#include "Score.h"

Score::Score()
{
	m_N = NULL;
	m_Father = NULL;
	m_dFScore = std::numeric_limits<double>::max();
	m_dGScore = std::numeric_limits<double>::max();
	m_dHScore = std::numeric_limits<double>::max();
}

Score::Score(Node * n, double fScore)
{
	m_N = n;
	m_Father = NULL;
	m_dFScore = fScore;
	m_dGScore = std::numeric_limits<double>::max();
	m_dHScore = std::numeric_limits<double>::max();
}

Score::Score(const Score & s)
{
	this->m_dFScore = s.m_dFScore;
	this->m_dGScore = s.m_dGScore;
	this->m_dHScore = s.m_dHScore;
	this->m_N = s.m_N;
	this->m_Father = m_Father;
}

Score & Score::operator=(const Score & s)
{
	if(this != &s)
	{
		this->m_dFScore = s.m_dFScore;
		this->m_dGScore = s.m_dGScore;
		this->m_dHScore = s.m_dHScore;
		this->m_N = s.m_N;
		this->m_Father = s.m_Father;
	}
	return *this;
}

bool Score::operator==(const Score & s)
{
	bool equal = false;

	if(this->m_N == s.m_N)
		equal = true;

	return equal;
}


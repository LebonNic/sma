#include "PathFinder.h"

PathFinder::PathFinder(void)
{
	m_bGoalReached = false;
}

PathFinder::~PathFinder(void)
{
	processMemoryCleaning();
}

Node * PathFinder::getStartingNode(void) const
{
	return m_StartingNode.m_N;
}

Node * PathFinder::getGoal(void) const
{
	return m_Goal.m_N;
}

bool CompareScore(Score * a, Score * b)
{
	return a->m_dFScore < b->m_dFScore;
}

std::list<Node *> PathFinder::findPathFromTo(Node * from, Node * to)
{
	Score	* current,
			neighbour;

	//Nettoyage des exécutions précédantes
	processMemoryCleaning();

	m_bGoalReached = false;

	//Initialisation du noeud de départ
	this->setStartingNode(from);
	m_StartingNode.m_dGScore = 0;
	m_StartingNode.m_dFScore = m_StartingNode.m_dGScore + this->computeHScore(m_StartingNode);

	this->setGoal(to);

	m_OpenSet.push_back(new Score(m_StartingNode));

	//Tant que le vecteur de noeuds à explorer n'est pas vide et que l'on n'a pas attent l'objectif
	while(!m_OpenSet.empty() && !m_bGoalReached)
	{
		//On récupère le premier élément dans la liste des noeuds dont le parcours a été planifié
		current = m_OpenSet.front();

		//L'objectif est atteint
		if(current->m_N == m_Goal.m_N)
		{
			m_bGoalReached = true;
		}

		//Sinon...
		else
		{
			//On retire le premier élément des noeuds à parcourir
			m_OpenSet.erase(m_OpenSet.begin());
			m_ClosedSet.push_back(current);

			//Parcours des voisins du noeuds courrant
			std::list<Node *> neighboursList = (current->m_N)->neighbours();
			for(auto itCurrentNeighbour = neighboursList.begin(); itCurrentNeighbour != neighboursList.end(); ++itCurrentNeighbour)
			{
				neighbour.m_N = (*itCurrentNeighbour);
				if(std::find_if(m_ClosedSet.begin(), m_ClosedSet.end(), Score::CompareScoreByPointer(&neighbour)) != m_ClosedSet.end())
				{
					double possibleGScore = current->m_dGScore + computeMovingCost((*current), neighbour); 
					std::vector<Score *>::iterator ite = std::find_if(m_OpenSet.begin(), m_OpenSet.end(), Score::CompareScoreByPointer(&neighbour));

					if(ite == m_OpenSet.end() || possibleGScore  < neighbour.m_dGScore) //Il manque le test "neighbor not in openset"
					{
						neighbour.m_Father = current;
						neighbour.m_dGScore = possibleGScore;
						neighbour.m_dFScore = neighbour.m_dGScore + this->computeHScore(neighbour);

						if(ite == m_OpenSet.end())
							m_OpenSet.push_back(new Score(neighbour));
					}
				}
			}
		}
		std::make_heap(m_OpenSet.begin(), m_OpenSet.end(), CompareScore);
		std::sort_heap(m_OpenSet.begin(), m_OpenSet.end(), CompareScore);
	}

	return reconstructPath();
}

void PathFinder::processMemoryCleaning()
{
	for(auto ite = m_OpenSet.begin(); ite != m_OpenSet.end(); ++ite)
		delete (*ite);

	for(auto ite = m_ClosedSet.begin(); ite != m_ClosedSet.end(); ++ite)
		delete (*ite);

	for(auto ite = m_Path.begin(); ite != m_Path.end(); ++ite)
		delete (*ite);

	m_OpenSet.clear();
	m_ClosedSet.clear();
	m_Path.clear();
}

void PathFinder::setStartingNode(Node * node)
{
	m_StartingNode.m_N = node;
}

void PathFinder::setGoal(Node * node)
{
	m_Goal.m_N = node;
}


double PathFinder::computeMovingCost(const Score & current, const Score & next)
{
	return (current.m_N)->distanceTo(next.m_N);
}

double PathFinder::computeHScore(const Score & current)
{
	return (current.m_N)->distanceTo(m_Goal.m_N);
}

std::list<Node *> PathFinder::reconstructPath(void)
{
	Score * current = &(m_Goal);

	if(m_bGoalReached)
	{
		m_Path.push_back(current->m_N);
		current = current->m_Father;
	}

	return m_Path;
}
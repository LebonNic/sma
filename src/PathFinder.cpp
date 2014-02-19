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

	this->setGoal(to);

	//Initialisation du noeud de départ
	this->setStartingNode(from);
	m_StartingNode.m_dGScore = 0;
	m_StartingNode.m_dFScore = m_StartingNode.m_dGScore + this->computeHScore(m_StartingNode);

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
			m_Goal.m_Father = current->m_Father;
		}

		//Sinon...
		else
		{
			//On retire le premier élément des noeuds à parcourir
			m_OpenSet.erase(m_OpenSet.begin());
			m_ClosedSet.push_back(new Score(*current));

			//Parcours des voisins du noeuds courrant
			std::list<Node *> neighboursList = (current->m_N)->neighbours();
			for(auto itCurrentNeighbour = neighboursList.begin(); itCurrentNeighbour != neighboursList.end(); ++itCurrentNeighbour)
			{
				neighbour.m_N = (*itCurrentNeighbour);

				//Pour chaque voisin on test s'il n'a pas déjà été exploré
				if(std::find_if(m_ClosedSet.begin(), m_ClosedSet.end(), Score::CompareScoreByPointer(&neighbour)) == m_ClosedSet.end())
				{
					double possibleGScore = current->m_dGScore + computeMovingCost((*current), neighbour); 
					std::vector<Score *>::iterator ite = std::find_if(m_OpenSet.begin(), m_OpenSet.end(), Score::CompareScoreByPointer(&neighbour));

					//Si le voisin en cours n'a pas été exploré ou qu'il se trouve dans liste des noeuds à parcourir
					//et que le nouveau coût pour l'atteindre a diminué
					if(ite == m_OpenSet.end() || possibleGScore  < (*ite)->m_dGScore)
					{
						neighbour.m_Father = current;
						neighbour.m_dGScore = possibleGScore;
						neighbour.m_dFScore = neighbour.m_dGScore +  (this->computeHScore(neighbour)); //TODO Possibilité d'ajouter un tie breaker ici

						if(ite == m_OpenSet.end())
							m_OpenSet.push_back(new Score(neighbour));
					}
				}
			}
		}
		//Tri de la liste des noeuds à parcourir par ordre croissant de f score
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

	m_OpenSet.clear();
	m_ClosedSet.clear();
	m_Path.clear();
}

const std::vector<Score *> & PathFinder::getOpenSet() const
{
	return m_OpenSet;
}

const std::vector<Score *> & PathFinder::getClosedSet() const
{
	return m_ClosedSet;
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
	/*return (current.m_N)->diagonalDistanceTo2D(next.m_N);*/
	return (current.m_N)->distanceTo2D(next.m_N);
}

double PathFinder::computeHScore(const Score & current)
{
	/*return (m_Goal.m_N)->diagonalDistanceTo2D(current.m_N);*/
	return (current.m_N)->distanceTo2D(m_Goal.m_N);
}

std::list<Node *> PathFinder::reconstructPath(void)
{
	Score * current = &(m_Goal);

	if(m_bGoalReached)
	{
		do
		{
			m_Path.push_front(current->m_N);
			current = current->m_Father;

		}while(current);
	}

	return m_Path;
}
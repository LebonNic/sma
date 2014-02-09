#include "Agent.h"

Agent::Agent(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: ActiveEntity(Location(x,y,z),behaviour)
{
	if(civilization)
		m_Civilisation = civilization;
	else
		throw std::invalid_argument("Le pointeur sur la civilization passe en parametre du constructeur d'Agent ne peut pas etre NULL.");
}

Agent::~Agent()
{
}

void Agent::run()
{
	ActiveEntity::run();
}

void Agent::attack()
{
}

void Agent::harvest()
{
}

void Agent::move()
{
}
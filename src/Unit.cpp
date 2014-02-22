#include "Unit.h"

const unsigned int Unit::m_uDefaultRange = 10;
const double  Unit::m_dGatheringCapacity = 20.0;


Unit::Unit(double x, double y, double z, Civilization * civilization)
	: Agent(x, y, z, new NopBehaviour(this), civilization)
{
	m_State = UnitStates::nop;
	m_uRange = Unit::m_uDefaultRange;
}

Unit::~Unit()
{
	for(auto node = m_Path.begin(); node != m_Path.end(); ++node)
		delete (*node);
}

const UnitStates & Unit::getUnitState() const
{
	return m_State;
}

void Unit::setUnitState(const UnitStates & j)
{
	m_State = j;
}


const Location & Unit::getUnitTargetLocation(void) const
{
	return m_TargetLocation;
}

void Unit::setUnitTargetLocation(const Location & targetLocation)
{
	m_TargetLocation = targetLocation;
}

void Unit::run()
{
	Agent::run();
}

void Unit::advanceOnPath()
{
	if(!m_Path.empty())
	{
		Node * n = m_Path.front();
		m_Path.remove(m_Path.front());
		this->setLocation(Location(n->x(), n->y(), n->z()));
		this->updateCivilizationMaps();
		if(m_Path.empty())
			m_State = UnitStates::nop;
	}
}

void Unit::updateCivilizationMaps()
{
	
	unsigned int
		i_begin = ( this->location().x() - m_uRange < 0 ) ? 0 : (this->location().x() - m_uRange),
		i_end = (this->location().x() + m_uRange > m_Civilization->getWorld().getSize()) ? m_Civilization->getWorld().getSize() : (this->location().x() + m_uRange),
		j_begin = ( this->location().y() - m_uRange < 0 ) ? 0 : (this->location().y() - m_uRange),
		j_end = (this->location().y() + m_uRange > m_Civilization->getWorld().getSize()) ? m_Civilization->getWorld().getSize() : (this->location().y() + m_uRange);

	const std::vector<std::vector<Ressource *>> & ressourceMap = m_Civilization->getWorld().getRessourcesMap();

	for(unsigned int i = i_begin; i < i_end; ++i)
	{
		for(unsigned int j = j_begin; j < j_end; ++j)
		{
			Ressource * ressource = ressourceMap[i][j];
			if(ressource)
			{
				switch(ressource->ressourceType())
				{
				case RessourceType::food:
					m_Civilization->locateFood(ressource->location());
					break;

				case RessourceType::gold:
					m_Civilization->locateGold(ressource->location());
					break;

				case RessourceType::wood:
					m_Civilization->locateWood(ressource->location());
					break;
				}
			}
			else
				m_Civilization->locateEmptinessSpace(Location(i, j));
		}
	}
}

bool Unit::findPathTo(const Location & goal)
{
	bool found = false;

	Graph & map = m_Civilization->getWorld().getMap();
	m_Path = map.findPathFromTo( map( this->location().x(), this->location().y() ), map( goal.x(), goal.y() ) );

	if(m_Path.size() > 0)
	{
		found = true;
		m_State = UnitStates::moving;
	}

	return found;
}

bool Unit::findPathArroundTarget(const Location & emplacement)
{
	bool found = false;
	
	//Recherche un sommet voisin de celui sur lequel se situe l'objectif cible. Celui-ci doit être atteignable (il ne doit pas être un obstacle).
	std::list<Node *> neighbours = (m_Civilization->getWorld().getMap()(emplacement.x(), emplacement.y()))->neighbours();
	auto node = neighbours.begin();
	
	while( !found && node != neighbours.end() )
	{
		found = (*node)->isReachable();

		if(!found)
			++node;
	}
		
	//Si un voisin est accessible, recherche d'un chemin jusqu'à celui-ci
	if(found)
		found = this->findPathTo(Location((*node)->x(), (*node)->y()));

	if(found)
		this->setUnitTargetLocation(emplacement);

	return found;
}

const Civilization & Unit::getCivilization(void) const
{
	return (*m_Civilization);
}

Civilization & Unit::getCivilization(void)
{
	return (*m_Civilization);
}

double Unit::getGatheringCapacity(void)
{
	return m_dGatheringCapacity;
}
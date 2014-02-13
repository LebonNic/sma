#include "Unit.h"


Unit::Unit(double x, double y, double z, Behaviour * behaviour, Civilization * civilization)
	: Agent(x, y, z, behaviour)
{
	m_Civilization = civilization;
	m_State = UnitState::nop;
}

Unit::~Unit()
{
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
	}
}

void Unit::updateCivilizationMaps()
{
	
	unsigned int
		i_begin = ( this->location().x() - m_uRange < 0 ) ? 0 : (this->location().x() - m_uRange),
		i_end = (this->location().x() + m_uRange > m_Civilization->getWorld().getSize()) ? m_Civilization->getWorld().getSize() : (this->location().x() + m_uRange),
		j_begin = ( this->location().y() - m_uRange < 0 ) ? 0 : (this->location().y() - m_uRange),
		j_end = (this->location().y() + m_uRange > m_Civilization->getWorld().getSize()) ? m_Civilization->getWorld().getSize() : (this->location().y() + m_uRange);

	const std::vector<std::vector<Ressource *>> ressourceMap = m_Civilization->getWorld().getRessourcesMap();

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

void Unit::setPathTo(const Location & goal)
{
	Graph map = m_Civilization->getWorld().getMap();
	m_Path = map.findPathFromTo( map( this->location().x(), this->location().y() ), map( goal.x(), goal.y() ) );
}
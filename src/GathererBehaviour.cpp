#include "GathererBehaviour.h"


MersenneTwister GathererBehaviour::m_Generator(0); //TODO : Change the seed value to initialize randomly the generator


GathererBehaviour::GathererBehaviour(Unit * unit, RessourceType focusedRessource)
	: UnitBehaviour(unit)
{
	m_FocusedRessource = focusedRessource;
	m_bRessourceFound = false;
}


GathererBehaviour::~GathererBehaviour(void)
{
}

void GathererBehaviour::execute()
{
	//TODO implement the logic of the unit's gatherer behaviour here.
	//The following peace of code is just a test.
	/*qDebug() << UNIT_RUN_MESSAGE;
	qDebug() << UNIT_GATHERER_MESSAGE;
	qDebug() << "Focused ressource : " << m_FocusedRessource;*/

	switch(m_Unit->getUnitState())
	{
	case UnitStates::nop:

		if(!m_bRessourceFound)
			findPathToRessource();
		else
			m_Unit->setUnitState(UnitStates::working);
		break;

	case UnitStates::moving:
		m_Unit->advanceOnPath();
		break;

	case UnitStates::working:
		gatherRessource();
		break;
	}
}

const RessourceType & GathererBehaviour::getFocusedRessource() const
{
	return m_FocusedRessource;
}

void GathererBehaviour::setFocusedRessource(RessourceType ressourceType)
{
	m_FocusedRessource = ressourceType;
}

void GathererBehaviour::findPathToRessource(void)
{
	const Civilization & unitCivilization = m_Unit->getCivilization();
	const Memory & civilizationMemory = unitCivilization.getMemory();

	std::vector<std::vector<bool>> ressourceMap;

	unsigned int mapSize = unitCivilization.getWorld().getSize();

	double minDist = std::numeric_limits<double>::max();

	Location ressourceLocation;

	unsigned int	x,
					y;

	bool find = false;

	//Sélection de la map de ressources que l'unité doit récolter
	switch(m_FocusedRessource)
	{
	case RessourceType::food:
		ressourceMap = civilizationMemory.getFoodMap();
		break;

	case RessourceType::gold:
		ressourceMap = civilizationMemory.getGoldMap();
		break;

	case RessourceType::wood:
		ressourceMap = civilizationMemory.getWoodMap();
		break;
	}

	//Sélection de points aléatoire sur la map de ressources sélectionnée
	for(unsigned int i = 0; i < GathererBehaviour::m_strikesNumber; ++i)
	{
		x = GathererBehaviour::m_Generator.genrand_int32() % mapSize,
		y = GathererBehaviour::m_Generator.genrand_int32() % mapSize;

		//S'il s'agit d'une ressource (case de la matrice non NULL)
		if(ressourceMap[x][y])
		{
			double	dx = m_Unit->x() - x,
					dy = m_Unit->y() - y,
					distance = (dx * dx) + (dy * dy); //Is sqrt(dx * dx + dy * dy) useful ?

			//On ne garde que la ressource la plus proche de l'unité
			if(distance < minDist)
			{
				minDist = distance;
				ressourceLocation.setX(x);
				ressourceLocation.setY(y);
			}
		}
	}

	//Signifie qu'une ressource a été trouvée
	if(minDist < std::numeric_limits<double>::max())
		m_bRessourceFound = m_Unit->findPathArroundTarget(ressourceLocation);
	
	//Si l'unité ne trouve pas de chemin jusqu'à la ressource alors, elle tente de trouver une direction aléatoire pour explorer la map
	if(!m_bRessourceFound)
		findRandomPath();
}

void GathererBehaviour::findRandomPath(void)
{
	unsigned int i = 0;
	bool find = false;
	const Civilization & unitCivilization = m_Unit->getCivilization();
	unsigned int mapSize = unitCivilization.getWorld().getSize();

	while(i < GathererBehaviour::m_strikesNumber && !find)
	{
		unsigned int	x = GathererBehaviour::m_Generator.genrand_int32() % mapSize,
						y = GathererBehaviour::m_Generator.genrand_int32() % mapSize;

		Node * node = unitCivilization.getWorld().getMap()(x,y);

		if(node->isReachable())
		{
			find = m_Unit->findPathTo(Location(x,y));
		}
		++i;
	}
}

void GathererBehaviour::gatherRessource(void)
{
	const Location & target = m_Unit->getUnitTargetLocation();

	//Check if the ressource is available (not already consumed by someone else)
	if(!(m_Unit->getCivilization().getWorld().getRessourcesMap()[target.x()][target.y()]))
	{
		m_Unit->setUnitState(UnitStates::nop);
		m_bRessourceFound = false;
	}

	//Not consumed
	else
	{
		switch(m_FocusedRessource)
		{
			
		case RessourceType::food:
			(m_Unit->getCivilization()).increaseFoodStockFromRessource(target, Unit::getGatheringCapacity());
			break;

		case RessourceType::gold:
			(m_Unit->getCivilization()).increaseGoldStockFromRessource(target, Unit::getGatheringCapacity());
			break;

		case RessourceType::wood:
			(m_Unit->getCivilization()).increaseWoodStockFromRessource(target, Unit::getGatheringCapacity());
			break;
		}
	}
}

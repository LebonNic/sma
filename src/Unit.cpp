#include "Unit.h"


Unit::Unit(const std::string & filename, double x, double y, double z, Graph *map, Owner owner)
	: ActiveEntity(x,y,z,map,owner,ActiveEntityType::unit)
{
	loadUnit(filename);
}

bool Unit::loadUnit(const std::string & filename)
{
	std::fstream inputStream(filename.c_str(), std::fstream::in);

	if(inputStream.bad())
		return false;

	std::string attribute, line;
	std::stringstream buffer;
	double attributeValue;
	this->initializeAttributes();

	while(!inputStream.eof())
	{
		std::getline(inputStream, line);
		buffer.str(line);

		buffer >> attribute >> attributeValue;
		if(!attribute.compare("hitPoints"))
		{
			this->setDefaultAttribute(AttributeType::hitPoints, attributeValue);
			this->setAttribute(AttributeType::hitPoints, attributeValue);
		}
		else if(!attribute.compare("damageClose"))
		{
			this->setDefaultAttribute(AttributeType::damageClose, attributeValue);
			this->setAttribute(AttributeType::damageClose, attributeValue);
		}
		else if(!attribute.compare("damageDistance"))
		{
			this->setDefaultAttribute(AttributeType::damageDistance, attributeValue);
			this->setAttribute(AttributeType::damageDistance, attributeValue);
		}
		else if(!attribute.compare("damageBuilding"))
		{
			this->setDefaultAttribute(AttributeType::damageBuilding, attributeValue);
			this->setAttribute(AttributeType::damageBuilding, attributeValue);
		}
		else if(!attribute.compare("defenseClose"))
		{
			this->setDefaultAttribute(AttributeType::defenseClose, attributeValue);
			this->setAttribute(AttributeType::defenseClose, attributeValue);
		}
		else if(!attribute.compare("defenseDistance"))
		{
			this->setDefaultAttribute(AttributeType::defenseDistance, attributeValue);
			this->setAttribute(AttributeType::defenseDistance, attributeValue);
		}
		else if(!attribute.compare("defenseBuilding"))
		{
			this->setDefaultAttribute(AttributeType::defenseBuilding, attributeValue);
			this->setAttribute(AttributeType::defenseBuilding, attributeValue);
		}
		else if(!attribute.compare("perceptionDistance"))
		{
			this->setDefaultAttribute(AttributeType::perceptionDistance, attributeValue);
			this->setAttribute(AttributeType::perceptionDistance, attributeValue);
		}
		else if(!attribute.compare("stealth"))
		{
			this->setDefaultAttribute(AttributeType::stealth, attributeValue);
			this->setAttribute(AttributeType::stealth, attributeValue);
		}
		else if(!attribute.compare("rangeClose"))
		{
			this->setDefaultAttribute(AttributeType::rangeClose, attributeValue);
			this->setAttribute(AttributeType::rangeClose, attributeValue);
		}
		else if(!attribute.compare("rangeDistance"))
		{
			this->setDefaultAttribute(AttributeType::rangeDistance, attributeValue);
			this->setAttribute(AttributeType::rangeDistance, attributeValue);
		}
		else
			return false;

		buffer.clear();
	}

	inputStream.close();
	return true;
}

void Unit::initializeAttributes(void)
{
	// Clear existing attributes
	this->m_Attribute.clear();
	this->m_DefaultAttributes.clear();

	// Add null atributes
	Attribute attribute = Attribute(AttributeType (0),0.0);
	for (unsigned int i = 0; i < Attribute::COUNT; ++i)
	{
		attribute = Attribute(AttributeType (i), 0.0);
		m_Attribute.push_back(attribute);
		m_DefaultAttributes.push_back(attribute);
	}
}

void Unit::setDefaultAttribute(AttributeType id, double value)
{
	this->m_DefaultAttributes[(unsigned int) id].setValue(value);
}

void Unit::setAttribute(AttributeType id, double value)
{
	this->m_Attribute[(unsigned int) id].setValue(value);
}

double Unit::attribute(AttributeType type)
{
	return this->m_Attribute[(unsigned int) type].value();
}

bool Unit::followPath(void)
{
	// There is a path to follow
	if (this->m_Path.size() > 0)
	{
		Node *nextNode = this->m_Path.front();
		this->setLocation(nextNode->location());

		this->m_Path.pop_front();
		return true;
	}
	// No path to follow
	else
		return false;
}

bool Unit::moveTo(Location *location)
{
	Location *current = this->location();
	this->m_Path = this->map()->findPathFromTo(
		(*(this->map())) ( (unsigned int) current->x(), (unsigned int) current->y() ),
		(*(this->map())) ( (unsigned int) location->x(), (unsigned int) location->y() )
	);
}
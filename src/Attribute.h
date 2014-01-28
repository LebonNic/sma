#pragma once

enum AttributeType
{
	hitPoints,
	damageClose,
	damageDistance,
	damageBuilding,
	defenseClose,
	defenseDistance,
	defenseBuilding,
	perceptionDistance,
	stealth,
	rangeClose,
	rangeDistance
};

class Attribute
{
private:
	AttributeType m_Type;
	double m_dValue;

public:
	static const unsigned int COUNT = 11;

	Attribute(AttributeType type, double value);

	void setValue(double value);
	void setType(AttributeType type);

	AttributeType type(void);
	double value(void);
};


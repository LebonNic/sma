#pragma once

enum AttributeId
{
	damageClose,
	damageDistance,
	damageBuilding,
	defenseClose,
	defenseDistance,
	defenseBuilding,
	perceptionDistance,
	stealth
};

class Attribute
{
private:
	AttributeId m_Id;
	double m_dValue;


	void setValue(double value);
public:
	Attribute(void);
	~Attribute(void);


	double value(void);
};


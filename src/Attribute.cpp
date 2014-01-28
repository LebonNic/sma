#include "Attribute.h"


Attribute::Attribute(AttributeType type, double value)
{
	this->setType(type);
	this->setValue(value);
}


void Attribute::setType(AttributeType type)
{
	this->m_Type = type;
}
void Attribute::setValue(double value)
{
	this->m_dValue = value;
}


AttributeType Attribute::type(void)
{
	return this->m_Type;
}
double Attribute::value(void)
{
	return this->m_dValue;
}

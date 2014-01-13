#pragma once

class Location
{
private:
	double m_dX;
	double m_dY;
	double m_dZ;
public:
	Location();
	Location(double x, double y, double z);
	~Location(void);

	
	double x();
	double y();
	double z();


	void setX(double x);
	void setY(double y);
	void setZ(double z);
};


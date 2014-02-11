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
	Location(const Location & l);
	Location & operator=(const Location & l);
	~Location(void);
	
	double x() const;
	double y() const;
	double z() const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);
};


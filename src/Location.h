#pragma once

class Location
{
private:
	double m_dX;
	double m_dY;
	double m_dZ;
public:
	Location();
	Location(double x, double y, double z = 0);
	Location(const Location & l);
	Location & operator=(const Location & l);
	~Location(void);
	
	double x() const;
	double y() const;
	double z() const;

	void setX(double x);
	void setY(double y);
	void setZ(double z);

	void setX(unsigned int x);
	void setY(unsigned int y);
	void setZ(unsigned int z);
};


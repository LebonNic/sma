#pragma once
class Point
{
private:
	double m_dX;
	double m_dY;
public:
	Point(void);
	Point(double x, double y);
	Point(const Point & point);
	~Point(void);
	Point & operator=(const Point & point);
	double getX(void) const;
	double getY(void) const;
	void setX(double x);
	void setY(double y);
	void setCoordinates(double x, double y);
	void setCoordinates(const Point & point);
};


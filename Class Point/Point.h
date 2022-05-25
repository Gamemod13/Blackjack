#ifndef POINT_H
#define POINT_H
#include<iostream>


class Point
{
private:
	double m_a;
	double m_b;
public:
	Point(double a = 0.0, double b = 0.0)
		: m_a(a), m_b(b) 
	{
	}
	void print() const {
		std::cout << "Point(" << m_a << ", " << m_b <<")" << std::endl;
	}
	friend double distanceFrom(const Point& first,const Point& second);
};

#endif


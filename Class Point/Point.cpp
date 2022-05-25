#include "Point.h"
#include<cmath>

double distanceFrom(const Point& first, const Point& second){
	return 
		sqrt((first.m_a - second.m_a) * (first.m_a - second.m_a) + (first.m_b - second.m_b) * (first.m_b - second.m_b));
}
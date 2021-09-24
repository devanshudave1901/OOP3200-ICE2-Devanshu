#include "CartesianPoint.h"

#include <string>
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <iostream>


// Class definition section

// constructor for CartesianPoint
CartesianPoint::CartesianPoint(const int x, const int y) : m_x(x), m_y(y)
{/*
	SetPoint(x, y);*/
}


CartesianPoint::~CartesianPoint() = default;

// copy constructor
CartesianPoint::CartesianPoint(const CartesianPoint& point2)
{
	SetPoint(point2.GetX(), point2.GetY());
	std::cout << "I am used" << std::endl;
}

// + operator
CartesianPoint CartesianPoint::operator+(const CartesianPoint& point2) const
{
	CartesianPoint tempPoint;
	tempPoint.SetX((*this).GetX() + point2.GetX());
	tempPoint.SetY((*this).GetY() + point2.GetY());

	return tempPoint;
}

// - operator defination
double CartesianPoint::operator-(const CartesianPoint& point_to) const
{
	const int xDelta = point_to.GetX()- m_x;

	// difference between y values
	const int yDelta = point_to.GetY() - m_y;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

// == operator defination 
bool CartesianPoint::operator==(const CartesianPoint& other_point) const
{

	return ((GetX() == other_point.GetX()) && (GetY() == other_point.GetY()));
}

// = operator defination
CartesianPoint CartesianPoint::operator=(const CartesianPoint& new_point)
{
	SetX((new_point.GetX()));
	SetY(new_point.GetY());

	return *this;

}

// ostream defination
std::ostream& operator<<(std::ostream& out, const CartesianPoint& point)
{
	out << point.ToString();
	return out;
}

// istream operator defination
std::istream& operator>>(std::istream& in, CartesianPoint& point)
{
	in >> point.m_x;
	in.ignore();
	in >> point.m_y;

	return  in;
}




// Setters
void CartesianPoint::SetPoint(int x, int y)
{
	SetX(x);
	SetY(y);
}

// SetX defination
void CartesianPoint::SetX(int x)
{
	m_x = x;
}

// SetY defination

void CartesianPoint::SetY(int y)
{
	m_y = y;
}
// Getters
//GetX defination

int CartesianPoint::GetX() const
{
	return m_x;
}

// GETY defination
int CartesianPoint::GetY() const
{
	return m_y;
}


/** GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/
double CartesianPoint::GetDistanceTo(const CartesianPoint& point_to) const
{
	// difference between x values
	const int xDelta = point_to.GetX() - m_x;

	// difference between y values
	const int yDelta = point_to.GetY()  - m_y;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

/** ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/
//ToString Method
std::string CartesianPoint::ToString() const
{
	// declare a stringstream object
	std::stringstream strOut;

	// build the string
	strOut << "(" << m_x << ", " << m_y << ")";

	// return the string
	return strOut.str();
}

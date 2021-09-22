#pragma once

#include <iostream>
#include <sstream>      // std::ostringstream



// Declare your class here#pragma once
class Vector {
public:


	Vector(double x = 0.0, double y = 0.0);

	~Vector() = default;

	Vector& operator+=(Vector const& v);
	Vector& operator-=(Vector const& v);
	Vector& operator*=(double scale);
	Vector& operator/=(double scale);
	Vector operator-() const;

	double length() const;
	double operator*(Vector const& v) const;

	bool operator==(Vector const& v) const;
	bool operator!=(Vector const& v) const;

	//To avoid the duplicity of data and member functions of ios class, 
	//it is declared as virtual base class when inheriting in istream and ostream 
	friend std::ostream& operator<<(std::ostream& os, Vector const& v);
	friend std::istream& operator>>(std::istream& is, Vector& v);
	

private:
	double first;
	double second;
};

Vector operator+(Vector const& lhs, Vector const& rhs);
Vector operator-(Vector const& lhs, Vector const& rhs);
Vector operator*(Vector const& lhs, double scale);
Vector operator*(double scale, Vector const& rhs);
Vector operator/(Vector const& lhs, double scale);



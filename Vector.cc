#pragma once
#include "Vector.h"
#include <iostream>
#include <cmath> 
// implement all the functions declared in Vector.h here

// member functions
Vector::Vector(double x, double y)
	: first{ x }, second{ y } {}

// with Vector& you can return *this which mean -->
// a reference to a local object is returned, 
// the returned reference can be used to chain function calls
// on a single object
Vector& Vector::operator+=(Vector const& v) {
	first += v.first;
	second += v.second;
	return *this;
}

Vector& Vector::operator-=(Vector const& v) {
	first -= v.first;
	second -= v.second;
	return *this;
}

Vector& Vector::operator*=(double scale) {
	first *= scale;
	second *= scale;
	return *this;
}

Vector& Vector::operator/=(double scale) {
	first /= scale;
	second /= scale;
	return *this;
}

//Still access to *this but can't return it
Vector Vector::operator-() const {
	Vector V{ *this };
	V.first = -first;
	V.second = -V.second;
	return V;
}

bool Vector::operator==(Vector const& v) const {
	return (first == v.first && second == v.second);
}


bool Vector::operator!=(Vector const& v) const {
	return !(*this == v);
}

double Vector::length() const {
	double sum;
	sum = std::sqrt(first * first + second * second);
	return sum;
}

double Vector::operator*(Vector const& v) const {
	return first * v.first + second * v.second;
}



// friend functions
std::ostream& operator<<(std::ostream& os, Vector const& v) {
	return os << '(' << v.first << ", " << v.second << ')';
}
std::istream& operator>>(std::istream& is, Vector& v) {
	Vector temp;
	//Discards leading whitespace from an input stream.
	is >> std::ws;
	// Returns the next character in the input sequence, without extracting it: 
	//The character is left as the next character to be extracted from the stream.
	if (is.peek() == '(') {
		if (is.ignore(1) >> std::ws >> temp.first >> std::ws){
			if (is.peek() == ',') {
				if (is.ignore(1) >> std::ws >> temp.second >> std::ws) {
					if (is.peek() == ')') {
						is.ignore(1);
						v = temp;
						return is;
					}
				}
				}
			}
			
	}
	is.setstate(std::ios::failbit);
	return is;

}


// non member functions
Vector operator+(Vector const &lhs, Vector const &rhs) {
	
	return Vector{ lhs }+=rhs;
}

Vector operator-(Vector const& lhs, Vector const& rhs) {

	return Vector{ lhs } -= rhs;
}

Vector operator*(Vector const& lhs, double scale) {
	return Vector{ lhs } *= scale;
}

Vector operator*(double scale, Vector const& rhs) {
	return rhs * scale;
}

Vector operator/(Vector const& lhs, double scale) {
	return Vector{ lhs } /= scale;
}
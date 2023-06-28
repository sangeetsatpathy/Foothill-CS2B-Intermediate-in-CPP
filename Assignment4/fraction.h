#pragma once
#include <iostream>

/*
Sangeet Satpathy
CS2B Spring 2023
Fraction.h
Professor Dave Harden

This class represent Fraction objects, storing numerators and denominators. It supports
operations between fractions and whole numbers, outputting the fraction in various forms,
and always storing the fraction in reduced form. The class supports negative fractions,
improper fractions, and whole numbers.

setNumerator: post -> numerator value will be updated and simplified accordingly.
setDenominator: pre -> denominator is a nonzero integer. post -> denominator value will be updated + simplified

friend istream& operator>>: pre -> fraction object is instantiated. post -> fraction num + den updated.
*/
class Fraction {
public:
	Fraction(int numerator = 0, int denom = 1);

	friend bool operator<(const Fraction lhs, const Fraction rhs);
	friend bool operator>(const Fraction lhs, const Fraction rhs);
	friend bool operator<=(const Fraction lhs, const Fraction rhs);
	friend bool operator>=(const Fraction lhs, const Fraction rhs);
	friend bool operator==(const Fraction lhs, const Fraction rhs);
	friend bool operator!=(const Fraction lhs, const Fraction rhs);

	int getNumerator();
	int getDenominator();
	friend std::ostream& operator<< (std::ostream& out, const Fraction f);
	friend std::istream& operator>>(std::istream& in, Fraction& f);
	void setNumerator(int n);
	void setDenominator(int d);

	friend Fraction operator+(const Fraction lhs, const Fraction rhs);
	friend Fraction operator-(const Fraction lhs, const Fraction rhs);
	friend Fraction operator*(const Fraction lhs, const Fraction rhs);
	friend Fraction operator/(const Fraction lhs, const Fraction rhs);

	friend Fraction operator+(const Fraction lhs, int rhs);
	friend Fraction operator-(const Fraction lhs, int rhs);
	friend Fraction operator*(const Fraction lhs, int rhs);
	friend Fraction operator/(const Fraction lhs, int rhs);


	Fraction operator+=(Fraction rhs);
	Fraction operator-=(Fraction rhs);
	Fraction operator*=(Fraction rhs);
	Fraction operator/=(Fraction rhs);

	Fraction operator+=(int rhs);
	Fraction operator-=(int rhs);
	Fraction operator*=(int rhs);
	Fraction operator/=(int rhs);

	Fraction operator++();
	Fraction operator--();
	Fraction operator++(int);
	Fraction operator--(int);
	int num;
	int den;
	static int abs(int n);
private:
	void simplify();

};
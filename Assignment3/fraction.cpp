#include "fraction.h"
#include <string>
#include <cassert>
using namespace std;

/*
Sangeet Satpathy
CS2B Spring 2023
Fraction.cpp
Professor Dave Harden


Class invariant:
Private data members used are num and den of the Fraction class, which represents the numerator
and denominator.

We can guarantee that the denominator of the fraction will NEVER be 0.
*/

//TESTING

//------------------------------------------------
//TESTING ^^

Fraction::Fraction(int numerator, int denom) {
	assert(denom != 0);
	this->num = numerator;
	this->den = denom;
	Fraction::simplify();
}


bool operator<(const Fraction lhs, const Fraction rhs) {
	if (lhs.num * rhs.den < lhs.den * rhs.num) {
		return true;
	}
	return false;
}

bool operator>(const Fraction lhs, const Fraction rhs) {
	if (lhs.num * rhs.den > lhs.den * rhs.num) {
		return true;
	}
	return false;
}

bool operator<=(const Fraction lhs, const Fraction rhs) {
	return !(lhs > rhs);
}

bool operator>=(const Fraction lhs, const Fraction rhs) {
	return !(lhs < rhs);
}

bool operator==(const Fraction lhs, const Fraction rhs) {
	if (lhs.num * rhs.den == lhs.den * rhs.num) {
		return true;
	}
	return false;
}

bool operator!=(const Fraction lhs, const Fraction rhs) {
	return !(lhs == rhs);
}

ostream& operator<<(ostream& out, const Fraction f) {
	if (f.den == 1) {
		out << f.num;
		return out;
	}

	if (Fraction::abs(f.num) > f.den) {
		int remainder = f.num % f.den;
		int wholeNum = (abs(f.num) - abs(remainder)) / abs(f.den);
		if (f.num < 0) {
			out << "-";
		}
		out << wholeNum << "+" << abs(remainder) << "/" << abs(f.den);
		return out;
	}

	out << f.num << "/" << f.den;
	return out;
}

istream& operator>>(istream& in, Fraction& f) {
	string thisFract;
	in >> thisFract;
	int fractLength = thisFract.length();
	bool negative = false;
	bool mixed = false;
	bool whole = true;
	int plusIndex = -1;
	int slashIndex = -1;
	for (int i = 0; i < fractLength; i++) {
		if (thisFract[i] == '-') {
			negative = true;
		}
		else if (thisFract[i] == '+') {
			mixed = true;
			plusIndex = i;
		}
		else if (thisFract[i] == '/') {
			whole = false;
			slashIndex = i;
		}
	}

	if (!whole) {
		f.setDenominator(stoi(thisFract.substr(slashIndex + 1, thisFract.length())));
	}
	else {
		f.setDenominator(1);
	}

	if (mixed) {
		f.setNumerator(stoi(thisFract.substr(plusIndex + 1, slashIndex)));
		int wholeNum = stoi(thisFract.substr(0, plusIndex));
		if (negative) {
			f.setNumerator(f.getNumerator() + (-1 * wholeNum * f.getDenominator()));
			f.setNumerator(f.getNumerator() * -1);
		}
		else {
			f.setNumerator(f.getNumerator() + wholeNum * f.getDenominator());
		}
	}
	else if (whole) {
		f.setNumerator(stoi(thisFract));
	}
	else { // not a whole integer, not a mixed fraction, 
		f.setNumerator(stoi(thisFract.substr(0, slashIndex)));
	}
	f.simplify();
	return in;
}

int Fraction::abs(int n) {
	if (n < 0) {
		return -1 * n;
	}
	return n;
}

void Fraction::setNumerator(int n) {
	num = n;
}

void Fraction::setDenominator(int d) {
	assert(d != 0);
	den = d;
}

/*
Reduces the current fraction, transferring any negative signs onto the numerator.
Does so by checking every factor downwards from whichever value is smaller, the numerator or denominator.
*/
void Fraction::simplify() {
	if (den < 0) {
		num = num * -1;
		den = den * -1;
	}

	if (num == 0) {
		den = 1;
	}

	if (abs(num) < abs(den)) {
		for (int i = abs(num); i > 0; i--) {
			if (num % i == 0 && den % i == 0) {
				num = num / i;
				den = den / i;
				return;
			}
		}
	}
	else {
		for (int i = abs(den); i > 0; i--) {
			if (num % i == 0 && den % i == 0) {
				num = num / i;
				den = den / i;
				return;
			}
		}
	}
}


Fraction operator+(const Fraction lhs, const Fraction rhs) {
	int multipliedDen = lhs.den * rhs.den;
	Fraction returnval = Fraction(lhs.num * rhs.den + lhs.den * rhs.num, multipliedDen);
	return returnval;
}

Fraction operator-(const Fraction lhs, const Fraction rhs) {
	return lhs + (rhs * -1);
}
Fraction operator*(const Fraction lhs, const Fraction rhs) {
	return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}
Fraction operator/(const Fraction lhs, const Fraction rhs) {
	return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

Fraction operator+(const Fraction lhs, int rhs) {
	Fraction newRhs = Fraction(rhs, 1);
	return lhs + (newRhs);
}

Fraction operator-(const Fraction lhs, int rhs) {
	return lhs + (rhs * -1);
}

Fraction operator*(const Fraction lhs, int rhs) {
	return Fraction(lhs.num * rhs, lhs.den);
}

Fraction operator/(const Fraction lhs, int rhs) {
	return Fraction(lhs.num, lhs.den * rhs);
}


Fraction Fraction::operator+=(Fraction rhs) {
	num = num * rhs.getDenominator() + den * rhs.getNumerator();
	den = den * rhs.getDenominator();
	Fraction::simplify();
	return *this;
}

Fraction Fraction::operator-=(Fraction rhs) {
	Fraction::operator+=(rhs * -1);
	Fraction::simplify();
	return *this;
}

Fraction Fraction::operator*=(Fraction rhs) {
	num = num * rhs.getNumerator();
	den = den * rhs.getDenominator();
	Fraction::simplify();
	return *this;
}

Fraction Fraction::operator/=(Fraction rhs) {
	num = num * rhs.getDenominator();
	den = den * rhs.getNumerator();
	simplify();
	return *this;
}

Fraction Fraction::operator+=(int rhs) {
	Fraction::operator+=(Fraction(rhs, 1));
	return *this;
}

Fraction Fraction::operator-=(int rhs) {
	Fraction::operator-=(Fraction(rhs, 1));
	return *this;
}

Fraction Fraction::operator*=(int rhs) {
	Fraction::operator*=(Fraction(rhs, 1));
	return *this;
}

Fraction Fraction::operator/=(int rhs) {
	Fraction::operator/=(Fraction(rhs, 1));
	return *this;
}

Fraction Fraction::operator++() {
	Fraction::operator+=(1);
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	Fraction::operator+=(1);
	return temp;
}

Fraction Fraction::operator--() {
	Fraction::operator-=(1);
	return *this;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	Fraction::operator-=(1);
	return temp;
}

int Fraction::getNumerator() {
	return num;
}

int Fraction::getDenominator() {
	return den;
}
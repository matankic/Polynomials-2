#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "Polynomial.h"

class Rational{
private:
	Polynomial nom, denom;
public:
	Rational();
	Rational(const Polynomial&, const Polynomial&);
	Polynomial &getNom();
	Polynomial &getDenom();
	Rational & operator=(const Rational &);
	Rational & operator+(const Rational &) const;
	Rational & operator*(const Rational &) const;
	Rational & operator*(const double) const;
	void print();
	friend ostream & operator<<(ostream &, const Rational &);
	friend Rational & operator*(const double, const Rational &);
};

#endif

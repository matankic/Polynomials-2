#include <iostream>
#include "Rational.h"

Rational::Rational() : nom(), denom(0)
	{ denom.setCoeff(0, 1); }
Rational::Rational(const Polynomial &p1, const Polynomial &p2)
	{ nom = p1; denom = p2; }
Polynomial &Rational::getNom()
	{ return nom; }
Polynomial &Rational::getDenom()
	{ return denom; }
void Rational::print(){
	nom.print();
	cout << "--------------------------" << endl;
	denom.print();
}
ostream &operator<<(ostream &print, const Rational &r){
	print <<"numerator="<< r.nom;
	print << "--------------------------" << endl;
	print <<"denominator="<< r.denom;
	return print;
}
Rational & Rational::operator=(const Rational &r){
	nom = r.nom;
	denom = r.denom;
	return *this;
}
Rational & Rational::operator+(const Rational &r) const{
	Rational *rat = new Rational(nom * r.denom + denom * r.nom, denom * r.denom);
	return *rat;
}
Rational & Rational::operator*(const Rational &r) const{
	Rational *rat = new Rational(nom * r.nom, denom * r.denom);
	return *rat;
}
Rational & Rational::operator*(const double c) const{
	Rational *rat = new Rational(nom * c, denom * c);
	return *rat;
}
Rational & operator*(const double c, const Rational &r){
	return r*c;
}

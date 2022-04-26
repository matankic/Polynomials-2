#include <iostream>
#include "Polynomial.h"
#include "Rational.h"
double getCoefficient(const Polynomial &p, int n)
{
	return p.getCoeff(n);
}
void testPolynomial()
{
	cout << "----- start testPolynomial ---------" << endl;
	cout << "test0 :" << Polynomial::getMaxDegree() <<endl;
	Polynomial p1;
	cout << "test1: " <<p1;
	Polynomial p2(16);
	p2.setCoeff(2, 0.4);
	cout << "test2: " << p2 << "degree=" << p2.getDegree(false)<<endl;
	double c[5] = { 0.1, 0.2, 0 ,11.5, 1.3};
	Polynomial p3(c,4);
	cout << "test3: " << p3;
	p2.setCoeff(2, 0.0);
	cout << "test4: " << p2;
	p2 = (p1 + 2.5*p3 -0.9*p3)*p3;
	double v[4];
	v[0] = getCoefficient(p2, 3);
	v[1] = getCoefficient(p2, 0);
	v[2] = getCoefficient(p2, -1);
	v[3] = getCoefficient(p2, 10);
	cout << "test6 :maxDegree = " << Polynomial::getMaxDegree() << endl;
	cout << "______________"<< endl;
}
void testRational() {
	cout << "----- start testRational ---------" << endl;
	cout << "test7" << endl;
	Rational r1;
	r1.print();
	cout << r1;
	double c[] = { 0,2,2,3,4,5 };
	Polynomial p1(c, 5);
	c[0] = 1.2;
	Polynomial p2(c, 3);
	Rational r2(p1, p2);
	cout << "test8" << endl;
	r2.print();
	cout << endl<< r2<<endl;
	cout << "test9" << endl;
	cout << "Numerator is " << r2.getNom();
	cout << "Denominator is " << r2.getDenom();
	Rational r3 = r2*r2 + r2;
	cout << "test10" << endl;
	double v[8];
	v[0] = getCoefficient(r3.getNom(), 3);
	v[1] = getCoefficient(r3.getNom(), 0);
	v[2] = getCoefficient(r3.getNom(), -1);
	v[3] = getCoefficient(r3.getNom(), 10);
	v[4] = getCoefficient(r3.getDenom(), 3);
	v[5] = getCoefficient(r3.getDenom(), 0);
	v[6] = getCoefficient(r3.getDenom(), -1);
	v[7] = getCoefficient(r3.getDenom(), 10);
	double d[21] = {0};
	d[0] = 1;
	Polynomial p3(d, 20);
	Rational r4(p3, p3);
	r4 = (r2 + r4)*r2;
	cout << "test11 : r4 = " << endl << r4 << endl;
	cout << "test12 :maxDegree = " << Polynomial::getMaxDegree() << endl;
	cout << "__________________________"<<endl;
}

int main()
{
	testPolynomial();
	testRational();
}

#include <iostream>
#include "Polynomial.h"

int Polynomial::maxDegree = 0;

Polynomial::Polynomial() : coeff(NULL), degree(0)
	{	}
Polynomial::Polynomial(int n) : degree(n){
	coeff  = new double[n+1];
	int i;
	for (i = 0; i <= n; i++)
		coeff[i] = 0;
}
Polynomial::Polynomial(double a[], int n) : degree(n){
	coeff  = new double[n+1];
	int i;
	for (i = 0; i <= n; i++){
		coeff[i] = a[i];
		if (a[i] && i > maxDegree)
			maxDegree = i;
	}
}
Polynomial::Polynomial(const Polynomial &p){
	degree = p.degree;
	if (!p.coeff)
		coeff = NULL;
	else{
		coeff = new double[degree + 1];
		int i;
		for (i = 0; i <= degree; i++)
			coeff[i] = p.coeff[i];
	}
}
Polynomial::~Polynomial(){
	/*
	if(coeff){
		delete [] coeff;
		coeff = NULL;
	}
	*/
}
Polynomial &Polynomial::setCoeff(int deg, double c){
	coeff[deg] = c;
	return *this;
}
void Polynomial::print() const{
	cout << "polynomial = ";
	if (!coeff && !degree) {
		cout << "0" << endl;
		return;
	}
	int i, max = 0;
	for (i = 0; i <= degree; i++) {
		if (coeff[i] && i > max)
			max = i;
	}
	for(i = 0; i <= max; i++){
		if (i == 0) {
			if (!coeff[i])
				cout << "0";
			else
				cout << coeff[i];
		}
		else {
			cout << "+";
			if (!coeff[i])
				cout << "(0)";
			else
				cout << "(" << coeff[i] << ")";
			cout << "*X^" << i;
		}
	}
	cout << endl;
}
int Polynomial::getMaxDegree(){
	return maxDegree;
}
int Polynomial::getDegree(bool what) const{
	if (!what) 
		return degree;
	else
		return getDegree();
}
int Polynomial::getDegree() const{
	int i, cnt = 0;
	for (i = 0; i <= degree; i++)
		if (coeff[i])
			cnt = i;
	return cnt;
}
double Polynomial::getCoeff(int index) const{
	return coeff[index];
}
ostream &operator<<(ostream &print, const Polynomial &p){
	print << "polynomial = ";
	if (!p.coeff && !p.degree) {
		print << "0" << endl;
		return print;
	}
	int i, max = 0;
	for (i = 0; i <= p.degree; i++) {
		if (p.coeff[i] && i > max)
			max = i;
	}
	for(i = 0; i <= max; i++){
		if (i == 0) {
			if (!p.coeff[i])
				print << "0";
			else
				print << p.coeff[i];
		}
		else {
			print << "+";
			if (!p.coeff[i])
				print << "(0)";
			else
				print << "(" << p.coeff[i] << ")";
			print << "*X^" << i;
		}
	}
	print << endl;
	return print;
}
Polynomial & Polynomial::operator=(const Polynomial &p){
	if(coeff)
		delete [] coeff;
	coeff  = new double[p.degree+1];
	degree = p.degree;
	int i;
	for(i = 0; i <= p.degree; i++)
		coeff[i] = p.coeff[i];
	return *this;
}
Polynomial & Polynomial::operator+(const Polynomial &p) const{
	int i, max;
	p.degree >= degree ? max = p.degree : max = degree;
	Polynomial *poly = new Polynomial(max);
	for(i = 0; i <= degree && i <= p.degree && p.coeff && coeff; i++)
		poly->coeff[i] = coeff[i] + p.coeff[i];
	while(i <= degree && coeff){
		poly->coeff[i] = coeff[i];
		i++;
	}
	while(i <= p.degree && p.coeff){
		poly->coeff[i] = p.coeff[i];
		i++;
	}
	return *poly;
}
Polynomial & Polynomial::operator-(const Polynomial &p) const{
	int i, max;
	p.degree >= degree ? max = p.degree : max = degree;
	Polynomial *poly = new Polynomial(max);
	for(i = 0; i <= degree && i <= p.degree; i++)
		poly->coeff[i] = coeff[i] - p.coeff[i];
	while(i <= degree){
		poly->coeff[i] = coeff[i];
		i++;
	}
	while(i <= p.degree){
		poly->coeff[i] = -p.coeff[i];
		i++;
	}
	return *poly;
}
Polynomial & Polynomial::operator*(const Polynomial &p) const{
	Polynomial *poly = new Polynomial(degree + p.degree);
	int i, j;
	for(i = 0; i <= degree; i++){
		for(j = 0; j <= p.degree; j++){
			poly->coeff[i+j] += coeff[i] * p.coeff[j];
			if (poly->coeff[i+j] && i+j > maxDegree)
				maxDegree = i+j;
		}
	}
	return *poly;
}
Polynomial & Polynomial::operator*(const double c) const{
	Polynomial *poly = new Polynomial();
	*poly = *this;
	int i;
	for(i = 0; i <= degree; i++)
		poly->coeff[i] *= c;
	return *poly;
}
Polynomial & operator*(const double c, const Polynomial &p){
	return p*c;
}

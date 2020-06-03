#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <vector>

using namespace std;

class Polinom{
	private:
		vector<double> koef;
	public:
		//konstruktori!
		Polinom() {}
		Polinom(int stepen);
		Polinom(const vector<double>& elementi);
		Polinom(const Polinom& p);
	
		//metodi
		void dodaj(double x);
		void normalizuj();

		//mozemo prijateljski funkcijama a mozemo i da promenimo znacenje operatora
		Polinom* operator +(const Polinom& p) const;
		Polinom* operator -(const Polinom& p) const;
		Polinom* operator *(const Polinom& p) const;
		Polinom* operator -() const;

		//implementriramo metode jednak i vrednost;
		
		bool operator ==(const Polinom& p) const;
		bool operator !=(const Polinom& p) const;

		double vrednost(double x) const;
		
		//prikazivanje polinom
		void ispisi() const;
		//implementriamo metode za izvod i integral
		Polinom* izvod() const;
		Polinom* integral(double c) const;

};

#endif 

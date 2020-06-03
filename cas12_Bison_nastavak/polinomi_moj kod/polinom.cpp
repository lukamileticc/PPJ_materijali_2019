#include "polinom.hpp"
#include <vector>

using namespace std;

//implementiramo konstruktore
Polinom::Polinom(int stepen){
	koef.resize(stepen);

	for(auto it = koef.begin();it != koef.end();it++)
		*it = 0;
}
Polinom::Polinom(const vector<double>& elementi){
	koef = elementi;
}
//Konstruktor kopije mislim
Polinom::Polinom(const Polinom& p){

	koef = p.koef;
}

//implementiramo metode!
void Polinom::dodaj(double x) {
	koef.push_back(x);
}

void Polinom::normalizuj(){
	
	for(auto it = koef.rbegin(); it != koef.rend() && *it == 0; it++)
		koef.pop_back();
}		

//menjamo znacenje operatora
//ovo smo mogli i sa friend metodama
//ali onda moramo imati dva argumenta
Polinom* Polinom::operator +(const Polinom& p) const{
	
	int velicina = max(p.koef.size(),koef.size());
	vector<double> novi(velicina+1);
	for(int i = 0; i < velicina;i++){
		
		if(i < koef.size())
			novi[i] = koef[i];
		else
			novi[i] = 0;

		if(i <= p.koef.size())
			novi[i] += p.koef[i];
		
	}

	Polinom* rezultat = new Polinom(novi);
	rezultat->normalizuj();
	return rezultat;

}
Polinom* Polinom::operator -(const Polinom& p)const{

	auto it1 = koef.begin();
	auto it2 = p.koef.begin();
	Polinom* novi = new Polinom();
	for(; it1 != koef.end() && it2 != p.koef.end(); it1++,it2++)
		novi->dodaj(*it1 - *it2);

	for(;it1 != koef.end();it1++)
		novi->dodaj(*it1);
	for(;it2 != p.koef.end();it2++)
		novi->dodaj((-*it2));

	novi->normalizuj();
	return novi;

}
Polinom* Polinom::operator *(const Polinom& p) const{
	
	int deg1 = koef.size();
	int deg2 = koef.size();

	Polinom* novi = new Polinom(deg1 + deg2);
	for(int i = 0; i < deg1 ; i++)
		for(int j = 0; j < deg2;j++)
			novi->koef[i+j] += koef[i]* p.koef[j];

	novi->normalizuj();
	return novi;

}
Polinom* Polinom::operator -()const{
	
	Polinom* novi = new Polinom;
	for(auto it = koef.begin(); it != koef.end();it++)
		novi->dodaj(-(*it));
	
	return novi;
}

bool Polinom::operator == (const Polinom& p) const{
	
	if(koef.size() != p.koef.size())
		return false;
	
	for(int i = 0; i < koef.size();i++)
		if(koef[i] != p.koef[i])
			return false;

	return true;

}

bool Polinom::operator !=(const Polinom& p ) const{
	
	return !(koef == p.koef);
}
//hornerova sema
double Polinom::vrednost(double x) const{
	
	double rezultat = 0;
	int stepen = koef.size() -1;
	for(int i = stepen; i >= 0;i--)
		rezultat = rezultat * x + koef[i];

	return rezultat;
}

//ispisivanje
void Polinom::ispisi() const{
	
	for(int i = 0; i < koef.size();i++){
		
	if(koef[i] == 0)
		continue;
	if(i!= 0 && koef[i] >0)
		cout << "+ ";

	cout << koef[i];
	
	if(i > 0)
		cout << "x ";
	if(i > 1)
		cout << "^" << i;

	cout << " ";
	}

}

//metode za izvod i integral
Polinom* Polinom::izvod() const{
	
	vector<double> novi;
	
	if(koef.size()-1 > 0){ 
		int novi_stepen = koef.size() -2;

		for(int i = 0; i <= novi_stepen;i++){
			double izracunaj = (i+1)*koef[i+1];
			novi.push_back(izracunaj);
		}
	}
	Polinom* novi_Polinom = new Polinom(novi);
	novi_Polinom->normalizuj();
	return novi_Polinom;
}
Polinom* Polinom::integral(double c) const{
	
	vector<double> novi;
	novi.push_back(c);
	novi.push_back(koef[0]);
	for(int i = 1; i< koef.size();i++){
		double izracunaj =1.0/(i+1) *koef[i];
		novi.push_back(izracunaj);
	}

	Polinom* novi_Polinom = new Polinom(novi);
	novi_Polinom->normalizuj();
	return novi_Polinom;
}






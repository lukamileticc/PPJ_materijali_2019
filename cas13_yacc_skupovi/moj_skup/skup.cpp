#include <iostream>
#include <set>
#include "skup.hpp"

using namespace std;

Skup::Skup() { }

Skup::Skup(int pocetak,int kraj){

	for(int i = pocetak; i <= kraj;i++)
		elementi.insert(i);
}
void Skup::dodaj(int x){
	elementi.insert(x);
}
void Skup::obrisi(int x){
	if(nadji(x))
		elementi.erase(x);
}
void Skup::stampaj() const{
	
	cout << "{";
	auto it = elementi.begin();
	while(it != elementi.end()){
		if(it != elementi.begin())
			cout << ", ";
		cout << *it;
		it++;
	}
	cout << "}" << endl;
}

bool Skup::nadji(int x) const{
	
	auto it = elementi.find(x);
	if(it == elementi.end())
		return false;
	else
		return true;
}
int Skup::brojElemenata() const{
	
	return elementi.size();
}

//implementiramo prijateljske funkcije

Skup* unija(const Skup* prvi,const Skup* drugi){

	Skup* novi_skup = new Skup();
	auto it1 = prvi->elementi.begin();
	auto it2 = drugi->elementi.begin();
	for(; it1 != prvi->elementi.end();it1++)
		novi_skup->dodaj(*it1);
	for(; it2 != drugi->elementi.end();it2++)
		novi_skup->dodaj(*it2);

	return novi_skup;
}

Skup* razlika(const Skup* prvi,const Skup* drugi){
	
	//kreiramo kopiju da bismo nju modifikovali
	//verovatno je to podrazumevan konstruktor kopije
	Skup* rezultat = new Skup(*prvi);
	
	for(auto it = prvi->elementi.begin();it != prvi->elementi.end();it++){
		if(drugi->nadji(*it))
			rezultat->obrisi(*it);
	}

	return rezultat;
}

Skup* presek(const Skup* prvi,const Skup* drugi){

	//kreiramo kopiju da bismo nju modifikovali
	//verovatno je to podrazumevan konstruktor kopije
	Skup* rezultat = new Skup(*prvi);

	for(auto it = prvi->elementi.cbegin();it != prvi->elementi.cend(); it++){
		if(!drugi->nadji(*it))	//nadjen u drugom
			rezultat->obrisi(*it);
	}		

	return rezultat;
}

bool Skup::podskup(const Skup* veci) const{
	
	for(auto it = elementi.cbegin();it != elementi.cend();it++){
		if(!veci->nadji(*it)) //nije nadjen u drugom
		return false;
	}

	return true;
}
/*
int main() {

	Skup s(0,13);
	s.stampaj();
	
 	Skup t;
	t.dodaj(-33);
	t.dodaj(24);
	t.stampaj();

	return 0;
}


*/






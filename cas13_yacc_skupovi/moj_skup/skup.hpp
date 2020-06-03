#ifndef SKUP_
#define SKUP_

#include <set>
#include <iostream>

using namespace std;

class Skup{

	private:
		set<int> elementi;

	public:
		//kostruktori
		Skup();
		Skup(int pocetak,int kraj);

		void dodaj(int x);
		void obrisi(int x);
		void stampaj() const;
		bool nadji(int x) const;
		bool podskup(const Skup* veci) const;
		int brojElemenata() const;
		
	//prijateljske funkcije
	
	friend Skup* unija(const Skup* prvi,const Skup* drugi);
	friend Skup* presek(const Skup* prvi,const Skup* drugi);
	friend Skup* razlika(const Skup* prvi,const Skup* drugi);
		
};

#endif

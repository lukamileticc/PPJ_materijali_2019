#ifndef _FORMULA
#define _FORMULA

#include <string>

using namespace std;

// 1-> TRUE
// 0->FALSE
// -1->UNDEF


class formula{

	private:
		int val;

	public:
	 //geter
	    int get_value() const;
	 //kostruktor
		formula(int vrednost);
	
	//za ispis;
	string ispisi() const;
	//metode
	friend int konjukcija(const formula& f1,const formula &f2) ;
	friend int disjunkcija(const formula& f1,const formula &f2);
	friend int implikacija(const formula& f1,const formula &f2);
 	friend int ekvivalencija(const formula& f1,const formula &f2);
	int negacija() const;

};


#endif 

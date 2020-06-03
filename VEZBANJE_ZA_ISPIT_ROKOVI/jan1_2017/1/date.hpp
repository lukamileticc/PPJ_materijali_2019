#ifndef _DATE
#define _DATE

#include <vector>
using namespace std;

class Date{

	private:
		//vrednosti dan mesec godina cuvacu u vektoru
		vector<int> dmg;
	public:
		//podrazumevani konstruktor
		Date();
		//konstruktor za vrednosti
		Date(int dan,int mesec,int godina);
		//geteri za dan i za mesec i za godinu
		int get_dan(){
			return dmg[0];
		}
		int get_mesec(){
			return dmg[1];
		}
		int get_godina(){
			return dmg[2];
		}
		//ispis u odredjenom formatu
		void ispisi_EUR() const;
		void ispisi_USA() const;
		void ispisi_ISO() const;
		
		//poredjenje datuma
		friend bool manje(Date& d1,Date& d2) ;
		friend bool vece(Date& d1,Date& d2) ;
		friend bool jednako(Date& d1,Date& d2) ;
		friend bool razlicito(Date& d1,Date& d2) ;
				

};
#endif

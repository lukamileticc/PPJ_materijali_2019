#include "date.hpp"
#include <iostream>
#include <vector>
using namespace std;

Date::Date(){
	//namestam podrazumevani datum
	dmg.push_back(1); 
	dmg.push_back(1);	
	dmg.push_back(1); 
}
Date::Date(int dan, int mesec,int godina){
	dmg.push_back(dan); 
	dmg.push_back(mesec);	
	dmg.push_back(godina); 
}	

void Date::ispisi_EUR() const{
	// dd.mm.gggg
	
	if(dmg[0] < 10)
		cout << 0;
	cout << dmg[0] << '.';
	
	//za mesec isto
	if(dmg[1] < 10)
		cout << 0;
	cout << dmg[1] << '.';
	//za godinu
	if(dmg[2] < 1000)
		cout << 0;
	if(dmg[2] < 100)
		cout << 0;
	if(dmg[2] < 10)
		cout << 0;
	cout << dmg[2];

	cout << endl;
}
void Date::ispisi_USA() const{
	// dd/mm/gggg 
	
	if(dmg[0] < 10)
		cout << 0;
	cout << dmg[0] << '/';
	
	//za mesec isto
	if(dmg[1] < 10)
		cout << 0;
	cout << dmg[1] << '/';
	//za godinu
	if(dmg[2] < 1000)
		cout << 0;
	if(dmg[2] < 100)
		cout << 0;
	if(dmg[2] < 10)
		cout << 0;
	cout << dmg[2];
			

	cout <<  endl;
	
}
void Date::ispisi_ISO() const{
	//gggg-mm-dd
	
	//za godinu
	if(dmg[2] < 1000)
		cout << 0;
	if(dmg[2] < 100)
		cout << 0;
	if(dmg[2] < 10)
		cout << 0;
	cout << dmg[2] << "-";
	//za mesec isto
	if(dmg[1] < 10)
		cout << 0;
	cout << dmg[1] << '-';
	if(dmg[0] < 10)
		cout << 0;
	cout << dmg[0];
	

	cout <<  endl;
}
//poredjenje datuma
bool manje(Date& d1,Date& d2) {
	
	//ako su godine vece odma vracamo false
	if(d1.dmg[2] > d2.dmg[2])
		return false;
	else if(d1.dmg[2] < d2.dmg[2])
		return true;
	else{ //godine su jednake gledamo mesece
		if(d1.dmg[1] > d2.dmg[1])
			return false;
		else if(d1.dmg[1] < d2.dmg[1])
			return true;

		else{//meseci su jednaki gledamo dane
			if(d1.dmg[1] >= d2.dmg[1])
				return false;
			else if(d1.dmg[1] < d2.dmg[1])
				return true;
		}
	}
	//ovo stavljam zbog return vrednost nema znacene
	return true;
	
}
bool vece(Date& d1,Date& d2) {
//ako su godine vece odma vracamo false
	if(d1.dmg[2] > d2.dmg[2])
		return true;
	else if(d1.dmg[2] < d2.dmg[2])
		return false;
	else{ //godine su jednake gledamo mesece
		if(d1.dmg[1] > d2.dmg[1])
			return true;
		else if(d1.dmg[1] < d2.dmg[1])
			return false;

		else{//meseci su jednaki gledamo dane
			if(d1.dmg[1] >= d2.dmg[1])
				return true;
			else if(d1.dmg[1] < d2.dmg[1])
				return false;
		}
	}

	//ovo stavljam zbog return vrednost nema znacene
	return true;
}
bool jednako(Date& d1,Date& d2){
	
	//ako je jednako sve true
	if(d1.dmg[0] == d2.dmg[0] && d1.dmg[1] == d2.dmg[1] && d1.dmg[2] == d2.dmg[2])
		return true;

	return false;
}
bool razlicito(Date& d1,Date& d2) {

	if(d1.dmg[0] == d2.dmg[0] && d1.dmg[1] == d2.dmg[1] && d1.dmg[2] == d2.dmg[2])
		return false;

	return true;

}

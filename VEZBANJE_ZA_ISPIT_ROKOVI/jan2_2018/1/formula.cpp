#include "formula.hpp"

#include <string>
using namespace std;

formula::formula(int vrednost){
	val = vrednost;
}

int konjukcija(const formula& f1,const formula &f2) {
	if(f1.val == 0 || f2.val == 0)
		return 0;
	else if(f1.val == 1 && f2.val == 1)
		return 1;
	else 
		return -1; //undef

}
int disjunkcija(const formula& f1,const formula &f2) {
	if(f1.val == 1 || f2.val == 1)
		return 1;
	else if(f1.val == 0 && f2.val == 0)
		return 0;
	else 
		return -1;//undef

}
int implikacija(const formula& f1,const formula &f2) {
	
	// f1 => f2 menjamo sa ~f1 || f2
	
	int vrednost = f1.negacija();
	formula negiranoF1 = formula(vrednost);
	return disjunkcija(negiranoF1,f2);
	
}
int ekvivalencija(const formula& f1,const formula &f2){
	
	// f1 <=> f2 menjamo (a => b) && (b==>a)

	formula tmp1 = formula(implikacija(f1,f2));
	formula tmp2 = formula(implikacija(f2,f1));
	
	return konjukcija(tmp1,tmp2);
}
int formula::negacija() const{

	if(val == 1)
		return 0;
	else if(val == 0)
		return 1;
	else
		return -1; //undef
}
string formula::ispisi() const{
	
	if(val == 1) return "True";
	else if(val == 0) return "False";
	else return "Undef";
}
int formula::get_value() const{
	return val;
}
/*
int main(){


	return 0;
}
*/

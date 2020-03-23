#include <iostream>
#include "tests.h"
using namespace std;

int main()
{
	TestAll();
	Repo v;
	v.addProd(Produs("Margarina", Produs::data(23, 3, 2020), 5.5));
	v.addProd(Produs("Unt", Produs::data(22, 1, 2019), 6.2));
	v.addProd(Produs("Cereale", Produs::data(23, 3, 2020), 7.4));
	v.addProd(Produs("Faina", Produs::data(21, 2, 2020), 4.3));
	v.addProd(Produs("Mustar", Produs::data(17, 12, 2018), 5.2));
	v.addProd(Produs("Telemea", Produs::data(23, 3, 2020), 8.6));
	v.addProd(Produs("Banane", Produs::data(10, 7, 2019), 2.7));
	v.addProd(Produs("Piper", Produs::data(23, 3, 2020), 3.75));
	v.getAll();
	v.Reducere(Produs::data(1, 1, 2020));
	v.print();
	return 0;
}
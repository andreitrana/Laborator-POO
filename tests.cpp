#include "tests.h"

void TestGetters()
{
	Produs v("Lapte", Produs::data(22, 3, 2020), 3.4);
	assert(strcmp(v.getNume(), "Lapte") == 0);
	assert(v.getData().zi == 22 && v.getData().luna == 3 && v.getData().an == 2020);
	assert(v.getPret() == 3.4);
}

void TestSetters()
{
	Produs v("Unt", Produs::data(19, 7, 2019), 6.0);
	v.setNume("Margarina");
	v.setData(Produs::data(20, 8, 2019));
	double pret = 6.2;
	v.setPret(pret);
	assert(strcmp(v.getNume(), "Margarina") == 0);
	assert(v.getData().zi == 20 && v.getData().luna == 8 && v.getData().an == 2019);
	assert(v.getPret() == 6.2);
}

void TestOperator()
{
	Produs v("Zahar", Produs::data(20, 4, 2014), 5.4);
	Produs v1 = v;
	assert(strcmp(v1.getNume(), "Zahar") == 0);
	assert(v1.getData().zi == 20 && v1.getData().luna == 4 && v1.getData().an == 2014);
	assert(v1.getPret() == 5.4);
}

void TestProdusConstructors()
{
	Produs a, b("Salam", Produs::data(21, 5, 2017), 4.5), c = b;
	assert(strcmp(a.getNume(), "") == 0 && a.getData().zi == 0 && a.getData().luna == 0 && a.getData().an == 0 && a.getPret() == 0.0);
	assert(strcmp(b.getNume(), "Salam") == 0 && b.getData().zi == 21 && b.getData().luna == 5 && b.getData().an == 2017 && b.getPret() == 4.5);
	assert(strcmp(c.getNume(), "Salam") == 0 && c.getData().zi == 21 && c.getData().luna == 5 && c.getData().an == 2017 && c.getPret() == 4.5);
}

void TestRepoConstructors()
{
	Repo a;
	assert(a.getSize() == 0);
	Produs v[3];
	Repo b(v, 3), c = b;
	assert(b.getSize() == 3);
	assert(c.getSize() == 3);
}

void TestRepoAdd()
{
	Produs a, b("Faina", Produs::data(21, 5, 2017), 4.5), c = b;
	Produs v[3] = { a,b,c };
	Repo r(v, 3);
	r.addProd(Produs("Zahar", Produs::data(22, 2, 2018), 5.5));
	assert(r.getSize() == 4);
}

void TestGetSize()
{
	Repo v;
	for (int i = 0; i < 5; i++)
		v.addProd(Produs("Malai", Produs::data(20, 4, 2019), 4.5));
	assert(v.getSize() == 5);
}

void TestGetProd()
{
	Repo v;
	Produs a("Cereale", Produs::data(21, 2, 2012), 7.6), b("Ulei", Produs::data(23, 4, 2015), 4.75), c("Otet", Produs::data(21, 2, 2012), 4.99);
	v.addProd(a);
	v.addProd(b);
	v.addProd(c);
	assert(v.getProd(2) == c);
}

void TestReducere()
{
	Repo v;
	v.addProd(Produs("Cereale", Produs::data(21, 2, 2012), 7.6));
	v.addProd(Produs("Ulei", Produs::data(23, 4, 2015), 4.5));
	v.addProd(Produs("Otet", Produs::data(21, 2, 2012), 4.9));
	v.addProd(Produs("Zmeura", Produs::data(25, 8, 2018), 11));
	v.addProd(Produs("Banane", Produs::data(12, 6, 2017), 3.5));
	v.Reducere(Produs::data(1, 1, 2017));
	assert(v.getProd(0).getPret() == 6.84 && v.getProd(1).getPret() == 4.05 && v.getProd(2).getPret() == 4.41);
}

void TestAll()
{
	TestProdusConstructors();
	TestRepoConstructors();
	TestGetSize();
	TestRepoAdd();
	TestGetters();
	TestSetters();
	TestOperator();
	TestGetProd();
	TestReducere();
}
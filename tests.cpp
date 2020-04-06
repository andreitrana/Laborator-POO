#include "tests.h"

//Entity.h
void testEntityConstructors()
{
	Carte a, b("Marile sperante", "Charles Dickens", false), c(b);
	assert(a.getStatus() == false);
	assert(strcmp(b.getTitlu(), "Marile sperante") == 0 && strcmp(b.getAutor(),"Charles Dickens")==0 && b.getStatus()==false);
	assert(strcmp(c.getTitlu(), "Marile sperante") == 0 && strcmp(c.getAutor(), "Charles Dickens") == 0 && c.getStatus() == false);
}

void testEntitySetters()
{
	Carte a("Marile sperante", "Charles Dickens", false);
	a.setTitlu("Mandrie si prejudecata");
	a.setAutor("Jane Austen");
	a.setStatus(true);
	assert(strcmp(a.getTitlu(), "Mandrie si prejudecata") == 0 && strcmp(a.getAutor(), "Jane Austen") == 0 && a.getStatus() == true);
}

void testEntityGettters()
{
	Carte a("Marile sperante", "Charles Dickens", false);
	assert(strcmp(a.getTitlu(), "Marile sperante") == 0 && strcmp(a.getAutor(), "Charles Dickens") == 0 && a.getStatus()==false);
}

void testEntityOperators()
{
	Carte a("Marile sperante", "Charles Dickens", false), b;
	b = a;
	assert(b == a);
}

//Repository.h
void testRepositoryConstructors()
{
	std::deque<Carte> d;
	d.push_back(Carte("Marile sperante","Charles Dickens", false));
	Repo a, b(&d), c(b);
	assert(a.getAll().size() == 0);
	assert(strcmp(b.getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(b.getAll()[0].getAutor(), "Charles Dickens") == 0 && b.getAll()[0].getStatus() == false);
	assert(strcmp(c.getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(c.getAll()[0].getAutor(), "Charles Dickens") == 0 && c.getAll()[0].getStatus() == false);
}

void testRepositorySetters()
{
	std::deque<Carte> d,e;
	d.push_back(Carte("Marile sperante", "Charles Dickens", false));
	e.push_back(Carte("Mandrie si prejudecata", "Jane Austen", false));
	Repo a(&d);
	a.setAll(e);
	assert(strcmp(a.getAll()[0].getTitlu(), "Mandrie si prejudecata") == 0 && strcmp(a.getAll()[0].getAutor(), "Jane Austen") == 0 && a.getAll()[0].getStatus() == false);
}

void testRepositoryGetters()
{
	std::deque<Carte> d,e;
	d.push_back(Carte("Marile sperante", "Charles Dickens", false));
	d.push_back(Carte("Mandrie si prejudecata", "Jane Austen", false));
	Repo a(&d);
	e = a.getAll();
	assert(strcmp(e[0].getTitlu(), "Marile sperante") == 0 && strcmp(e[0].getAutor(), "Charles Dickens") == 0 && e[0].getStatus() == false);
	assert(strcmp(e[1].getTitlu(), "Mandrie si prejudecata") == 0 && strcmp(e[1].getAutor(), "Jane Austen") == 0 && e[1].getStatus() == false);
}

void testRepositoryAddItem()
{
	Repo a;
	a.addItem(Carte("Marile sperante", "Charles Dickens", false));
	a.addItem(Carte("Mandrie si prejudecata", "Jane Austen", false));
	assert(strcmp(a.getAll()[0].getTitlu(), "Marile sperante") == 0);
	assert(strcmp(a.getAll()[1].getTitlu(), "Mandrie si prejudecata") == 0);
}

void testRepositoryOperators()
{
	std::deque<Carte> d;
	d.push_back(Carte("Marile sperante", "Charles Dickens", false));
	Repo a(&d), b;
	b = a;
	assert(strcmp(b.getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(b.getAll()[0].getAutor(), "Charles Dickens") == 0 && b.getAll()[0].getStatus() == false);
}

//Service.h
void testServiceConstructors()
{
	std::deque<Carte> s;
	s.push_back(Carte("Marile sperante","Charles Dickens", false));
	s.push_back(Carte("Mandrie si prejudecata", "Jane Austen", false));
	Repo r(&s);
	Service a, b(&r), c(b);
	assert(a.getRepo().getAll().size() == 0);
	assert(strcmp(b.getRepo().getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(b.getRepo().getAll()[0].getAutor(), "Charles Dickens") == 0 && b.getRepo().getAll()[0].getStatus() == false);
	assert(strcmp(c.getRepo().getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(c.getRepo().getAll()[0].getAutor(), "Charles Dickens") == 0 && c.getRepo().getAll()[0].getStatus() == false);
}

void testServiceSetters()
{
	Service a;
	a.add(Carte("Marile sperante", "Charles Dickens", false));
	a.update_title("Marile sperante","Mandrie si prejudecata");
	a.update_autor("Mandrie si prejudecata", "Jane Austen");
	a.update_status("Mandrie si prejudecata", true);
	assert(strcmp(a.getRepo().getAll()[0].getTitlu(), "Mandrie si prejudecata") == 0 && strcmp(a.getRepo().getAll()[0].getAutor(), "Jane Austen") == 0 && a.getRepo().getAll()[0].getStatus() == true);
}

void testServiceGetters()
{
	std::deque<Carte> d;
	d.push_back(Carte("Mandrie si prejudecata", "Charles Dickens", false));
	d.push_back(Carte("Marile sperante", "Jane Austen", false));
	Repo r(&d);
	Service a(&r);
	assert(a.getRepo().getAll()[0] == d[0] && a.getRepo().getAll()[1] == d[1]);
}

void testServiceOperators()
{
	std::deque<Carte> s;
	s.push_back(Carte("Marile sperante", "Charles Dickens", false));
	s.push_back(Carte("Mandrie si prejudecata", "Jane Austen", false));
	Repo r(&s);
	Service a, b(&r);
	a = b;
	assert(strcmp(a.getRepo().getAll()[0].getTitlu(), "Marile sperante") == 0 && strcmp(a.getRepo().getAll()[0].getAutor(), "Charles Dickens") == 0 && a.getRepo().getAll()[0].getStatus() == false);
}

void testServiceAddFunction()
{
	Service s;
	s.add(Carte("Mandrie si prejudecata", "Charles Dickens", false));
	assert(strcmp(s.getRepo().getAll()[0].getTitlu(), "Mandrie si prejudecata") == 0);
}

void testServiceDelFunction()
{
	Service s;
	s.add(Carte("Marile sperante", "Charles Dickens", false));
	s.del("Marile sperante");
	assert(s.getRepo().getAll().size() == 0);
}

void testServiceFindFunction()
{
	Service s;
	s.add(Carte("Marile sperante", "Charles Dickens", false));
	s.add(Carte("Mandrie si prejudecata", "Jane Austen", false));
	s.add(Carte("Ocolul pamantului in 80 de zile", "Jules Verne", false));
	assert(s.find("Ocolul pamantului in 80 de zile") == 2);
}

void testServiceImprumutFunction()
{
	Service s;
	s.add(Carte("Mandrie si prejudecata", "Jane Austen", false));
	s.imprumut("Mandrie si prejudecata");
	assert(s.getRepo().getAll()[0].getStatus() == true);
}

//UserInterface.h
void testUserInterfaceConstructors()
{
	Service s;
	s.add(Carte("Marile sperante", "Charles Dickens", false));
	UI a, b(&s), c(b);
	assert(strcmp(b.getService().getRepo().getAll()[0].getTitlu(), "Marile sperante") == 0);
	assert(strcmp(c.getService().getRepo().getAll()[0].getTitlu(), "Marile sperante") == 0);
}

void testUserInterfaceSetters()
{
	Service s;
	s.add(Carte("Marile sperante", "Charles Dickens", true));
	UI u;
	u.setService(&s);
	assert(u.getService().getRepo().getAll()[0] == s.getRepo().getAll()[0]);
}

void testUserInterfaceGetters()
{
	Service s;
	s.add(Carte("Marile sperante", "Mandrie si prejudecata", false));
	s.add(Carte("Mandrie si prejudecata", "Jane Austen", false));
	UI u(&s);
	assert(u.getService().getRepo().getAll()[0] == s.getRepo().getAll()[0]);
}


void TestAll()
{
	testEntityConstructors();
	testEntitySetters();
	testEntityGettters();
	testEntityOperators();

	testRepositoryConstructors();
	testRepositorySetters();
	testRepositoryGetters();
	testRepositoryAddItem();
	testRepositoryOperators();

	testServiceConstructors();
	testServiceSetters();
	testServiceGetters();
	testServiceOperators();
	testServiceAddFunction();
	testServiceDelFunction();
	testServiceFindFunction();
	testServiceImprumutFunction();

	testUserInterfaceConstructors();
	testUserInterfaceSetters();
	testUserInterfaceGetters();
}

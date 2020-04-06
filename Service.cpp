#include "Service.h"

Service::Service()
{
	r = new Repo();
}

Service::Service(Repo* other)
{
	r = new Repo();
	*r = *other;
}

Service::Service(Service& other)
{
	r = new Repo();
	*r = other.getRepo();
}

Service::~Service()
{
	delete r;
}

Service& Service::operator=(Service& other)
{
	*r = other.getRepo();
	return *this;
}

size_t Service::find(const char* titlu)
{
	std::deque<Carte> copy = r->getAll();
	for (size_t i = 0; i < copy.size(); i++)
		if (strcmp(copy[i].getTitlu(), titlu)==0)
			return i;
	return -1;	
}

void Service::del(const char* titlu)
{
	size_t i = find(titlu);
	if ( i == -1)
		return;
	std::deque<Carte> copy = r->getAll();
	copy.erase(copy.begin() + i);
	r->setAll(copy);
}

void Service::add(const Carte& carte)
{
	if (find(carte.getTitlu()) != -1)
		return;
	r->addItem(carte);
}

void Service::imprumut(const char* titlu)
{
	size_t i = find(titlu);
	if (i == -1)
		return;
	if (r->getAll()[i].getStatus() == true)
		std::cout << "Cartea nu este disponibila";
	else
		r->getAll()[i].setStatus(true);
}

void Service::print()
{
	std::deque<Carte> copy = r->getAll();
	for (size_t i = 0; i < copy.size(); i++)
	{
		std::cout << copy[i].getTitlu() << "\t" << copy[i].getAutor()<<"\t";
		if (copy[i].getStatus() == true)
			std::cout << "imprumutata\n";
		else
			std::cout << "neimprumutata\n";
	}
}

void Service::update_title(const char* titlu, const char* new_title)
{
	size_t i = find(titlu);
	if (i == -1)
		return;
	r->getAll()[i].setTitlu(new_title);
}

void Service::update_autor(const char* titlu, const char* new_autor)
{
	size_t i = find(titlu);
	if (i == -1)
		return;
	r->getAll()[i].setAutor(new_autor);
}

void Service::update_status(const char* titlu, bool status)
{
	size_t i = find(titlu);
	if (i == -1)
		return;
	r->getAll()[i].setStatus(status);
}

Repo& Service::getRepo()
{
	return *r;
}

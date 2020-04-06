#include "Repository.h"

Repo::Repo()
{
	v = new std::deque<Carte>();
}

Repo::Repo(std::deque<Carte>* a)
{
	v = new std::deque<Carte>();
	*v = *a;
}

Repo::Repo(Repo& other)
{
	v = new std::deque<Carte>();
	*v = other.getAll();
}

Repo::~Repo()
{
	delete v;
}

Repo& Repo::operator=(Repo& other)
{
	*v = other.getAll();
	return *this;
}

void Repo::addItem(const Carte& carte)
{
	v->push_back(carte);
}

std::deque<Carte>& Repo::getAll()
{
	return *v;
}

void Repo::setAll(std::deque<Carte>& other)
{
	*v = other;
}

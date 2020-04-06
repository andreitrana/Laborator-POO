#include "Entity.h"

Carte::Carte()
{
	titlu = new char[51];
	autor = new char[51];
	status = false;
}

Carte::Carte(const char* t, const char* a, bool s)
{
	titlu = new char[51];
	autor = new char[51];
	strcpy(titlu, t);
	strcpy(autor, a);
	status = s;
}

Carte::Carte(const Carte& other)
{
	titlu = new char[51];
	autor = new char[51];
	strcpy(titlu, other.getTitlu());
	strcpy(autor, other.getAutor());
	status = other.getStatus();
}

Carte::~Carte()
{
	delete[] titlu;
	delete[] autor;
}

Carte& Carte::operator=(const Carte& other)
{
	strcpy(titlu, other.getTitlu());
	strcpy(autor, other.getAutor());
	status = other.getStatus();
	return *this;
}

bool Carte::operator==(const Carte& other)
{
	return (strcmp(titlu, other.getTitlu()) == 0 && strcmp(autor, other.getAutor()) == 0 && status == other.getStatus());
}

void Carte::setTitlu(const char* titlu)
{
	strcpy(this->titlu, titlu);
}

void Carte::setAutor(const char* autor)
{
	strcpy(this->autor, autor);
}

void Carte::setStatus(bool status)
{
	this->status = status;
}

const char* Carte::getTitlu() const
{
	return titlu;
}

const char* Carte::getAutor() const
{
	return autor;
}

const bool& Carte::getStatus() const
{
	return status;
}

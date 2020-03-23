#include "Produs.h"

Produs::Produs()
{
	strcpy(nume, "");
	d.zi = d.luna = d.an = 0;
	pret = 0.0;
}

Produs::~Produs()
{

}

Produs::Produs(const Produs& m)
{
	strcpy(nume, m.nume);
	pret = m.pret;
	d.zi = m.d.zi;
	d.luna = m.d.luna;
	d.an = m.d.an;

}

Produs::Produs(const char* n, data dat, double p)
{
	strcpy(nume, n);
	d.zi = dat.zi;
	d.luna = dat.luna;
	d.an = dat.an;
	pret = p;
}

const char* Produs::getNume() const
{
	return nume;
}

Produs::data Produs::getData() const
{
	return d;
}

double Produs::getPret() const
{
	return pret;
}

void Produs::setNume(const char* other)
{
	strcpy(nume, other);
}

void Produs::setData(data other)
{
	d.zi = other.zi;
	d.luna = other.luna;
	d.an = other.an;
}

void Produs::setPret(double other)
{
	pret = other;
}

bool Produs::operator==(Produs& other)
{
	return (pret == other.getPret() && strcmp(nume, other.getNume()) == 0 && d.an == other.getData().an && d.luna == other.getData().luna && d.zi == other.getData().zi);
}

Produs& Produs::operator=(const Produs& other)
{
	pret = other.getPret();
	strcpy(nume, other.getNume());
	d.an = other.getData().an;
	d.zi = other.getData().zi;
	d.luna = other.getData().luna;
	return *this;
}

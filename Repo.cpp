#include "Repo.h"

Repo::Repo()
{
	lg = 0;
}

Repo::~Repo()
{

}

Repo::Repo(Produs p[51], int ct)
{
	for (int i = 0; i < ct; i++)
		v[i] = p[i];
	lg = ct;
}

Repo::Repo(const Repo& r)
{
	lg = r.lg;
	for (int i = 0; i < r.lg; i++)
		v[i] = r.v[i];
}

Produs Repo::getProd(int poz)
{
	if (poz < 0 || poz >= lg)
	{
		std::cout << "Out of range";
		return Produs();
	}
	return v[poz];
}

void Repo::addProd(const Produs& other)
{
	v[lg] = other;
	lg++;
}

int Repo::getSize() const
{
	return lg;
}

void Repo::Reducere(const Produs::data& other)
{
	int ok;
	for (int i = 0; i < lg; i++)
	{
		ok = 0;
		if (v[i].getData().an < other.an)
			ok = 1;
		else if (v[i].getData().an == other.an)
		{
			if (v[i].getData().luna < other.luna)
				ok = 1;
			else if (v[i].getData().luna == other.luna)
				if (v[i].getData().zi < other.zi)
					ok = 1;
		}
		if (ok)
			v[i].setPret(v[i].getPret() - 0.1 * v[i].getPret());
	}
}

void Repo::getAll()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	for (int i = 0; i < lg; i++)
		if (v[i].getData().an == (now->tm_year + 1900) && v[i].getData().luna == (now->tm_mon + 1) && v[i].getData().zi == now->tm_mday)
			std::cout << v[i].getNume() << " ";
	std::cout << '\n';
}

void Repo::print()
{
	for (int i = 0; i < lg; i++)
		std::cout << v[i].getNume() << " " << v[i].getData().zi << " " << v[i].getData().luna << " " << v[i].getData().an << " " << v[i].getPret() << '\n';
}


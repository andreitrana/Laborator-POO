#pragma once
#include <string.h>
#include <iostream>
class Produs
{
public:
	struct data {
		int zi, luna, an;
		data() { zi = luna = an = 0; }
		data(int z, int l, int a) :zi(z), luna(l), an(a) {}
	};
	Produs();
	~Produs();
	Produs(const Produs&);
	Produs(const char*, data, double);
	bool operator==(Produs&);
	Produs& operator=(const Produs&);
	const char* getNume() const;
	data getData() const;
	double getPret() const;
	void setNume(const char*);
	void setData(data);
	void setPret(double);
private:
	char nume[20];
	data d;
	double pret;
};


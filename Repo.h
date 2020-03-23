#pragma once
#include "Produs.h"
#include <ctime>

class Repo
{
private:
	Produs v[51];
	int lg;
public:
	Repo();
	~Repo();
	Repo(Produs[51], int);
	Repo(const Repo&);
	Produs getProd(int);
	void addProd(const Produs&);
	int getSize() const;
	void Reducere(const Produs::data&);
	void getAll();
	void print();
};


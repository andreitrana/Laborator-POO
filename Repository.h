#pragma once
#include "Entity.h"
#include <deque>

class Repo
{
private:
	std::deque<Carte>* v;
public:
	Repo();
	Repo(std::deque<Carte>*);
	Repo(Repo&);
	~Repo();
	Repo& operator=(Repo&);
	void addItem(const Carte&);
    std::deque<Carte>& getAll();
	void setAll(std::deque<Carte>&);
};
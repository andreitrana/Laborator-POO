#pragma once
#include "Repository.h"

class Service
{
private:
	Repo* r;
public:
	Service();
	Service(Repo*);
	Service(Service&);
	~Service();
	Service& operator=(Service&);
	size_t find(const char*);
	void del(const char*);
	void add(const Carte&);
	void imprumut(const char*);
	void print();
	void update_title(const char*, const char*);
	void update_autor(const char*, const char*);
	void update_status(const char*, bool);
	Repo& getRepo();
};
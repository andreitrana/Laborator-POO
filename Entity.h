#pragma once
#include <iostream>
#include <string.h>
class Carte
{
private:
	char* titlu;
	char* autor;
	bool status;
public:
	Carte();
	Carte(const char*,const char*, bool);
	Carte(const Carte&);
	~Carte();
	Carte& operator=(const Carte&);
	bool operator==(const Carte&);
	void setTitlu(const char*);
	void setAutor(const char*);
	void setStatus(bool);
	const char* getTitlu() const;
	const char* getAutor() const;
	const bool& getStatus() const;
};
#pragma once
#include "Service.h"
class UI
{
private:
	Service* s;
public:
	UI();
	UI(Service*);
	UI(UI&);
	~UI();
	Service& getService();
	void setService(Service*);
	void print_menu();
	void run();
};
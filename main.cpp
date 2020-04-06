#include "tests.h"

int main()
{
	TestAll();
	UI* u = new UI();
	u->run();
	delete u;
	return 0;
}
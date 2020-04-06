#include "UserInterface.h"

UI::UI()
{
	s = new Service();
}

UI::UI(Service* r)
{
	s = new Service();
	*s = *r;
}

UI::UI(UI& other)
{
	s = new Service();
	*s = other.getService();
}

UI::~UI()
{
	delete s;
}

Service& UI::getService()
{
	return *s;
}

void UI::setService(Service* s)
{
	*this->s = *s;
}

void UI::print_menu()
{
	std::cout << "1. Adauga carte\n";
	std::cout << "2. Sterge carte\n";
	std::cout << "3. Imprumuta o carte\n";
	std::cout << "4. Schimba numele unei carti\n";
	std::cout << "5. Schimba autorului unei carti\n";
	std::cout << "6. Schimba statusul unei carti\n";
	std::cout << "7. Afiseaza toate cartile\n";
	std::cout << "8. Iesire\n";
}

void UI::run()
{
	print_menu();
	unsigned optiune;
	bool exit = false;
	while (!exit)
	{
		char titlu[51], autor[51], titlu_nou[51];
		size_t i;
		std::cout << "\nAlege o optiune: ";
		std::cin >> optiune;
		std::cin.get();
		switch (optiune)
		{
		case 1:	
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
			i = s->find(titlu);
			if (i != -1)
				std::cout << "Cartea exista deja.\n";
			else
			{
				std::cout << "Autor: ";
				std::cin.get(autor, 50);
				std::cin.get();
				Carte c(titlu, autor, false);
				s->add(c);
			}
			break;
		case 2:
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
			if (s->find(titlu) == -1)
				std::cout << "Nu exista aceasta carte\n";
			else
				s->del(titlu);
			break;
		case 3:
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
			i=s->find(titlu);
			if (i == -1)
				std::cout << "Nu exista aceasta carte\n";
			else if (s->getRepo().getAll()[i].getStatus() == true)
				std::cout << "Aceasta carte este imprumutata\n";
			else
				s->getRepo().getAll()[i].setStatus(true);
			break;
		case 4:
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
			i = s->find(titlu);
			if (i == -1)
				std::cout << "Nu exista aceasta carte\n";
			else
			{
				std::cout << "Titlul nou: ";
				std::cin.get(titlu_nou, 50);
				std::cin.get();
				s->getRepo().getAll()[i].setTitlu(titlu_nou);
			}
			break;
		case 5:
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
			i = s->find(titlu);
			if (i == -1)
				std::cout << "Nu exista aceasta carte\n";
			else
			{
				std::cout << "Autor nou: ";
				std::cin.get(autor, 50);
				std::cin.get();
				s->getRepo().getAll()[i].setAutor(autor);
			}
			break;
		case 6:
			std::cout << "Titlu: ";
			std::cin.get(titlu, 50);
			std::cin.get();
		    i = s->find(titlu);
			if (i == -1)
				std::cout << "Nu exista aceasta carte\n";
			else
				s->getRepo().getAll()[i].setStatus(!s->getRepo().getAll()[i].getStatus());
			break;
		case 7:
			s->print();
			break;
		case 8:
			exit = true;
			break;
		default:
			std::cout << "Optiune invalida\n";
			break;
		}
	}
}

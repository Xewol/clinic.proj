#include <iostream>
#include "Dane.h"
#include <fstream>
#include <algorithm>
#include "Global.h"
using namespace Global;

void Dane::zapisz(std::vector<Pacjent*> vec)
{
	size_t i = 0;
	std::ofstream outFile("baza.txt");
	auto lamb = [&](Pacjent*& ptr) {
		i++;
		outFile << "Imie: " << ptr->get_imie() << std::endl;
		outFile << "Nazwisko: " << ptr->get_nazwisko() << std::endl;
		outFile << "Pesel: " << ptr->get_pesel() << std::endl;
		outFile << "Wiek: " << ptr->get_wiek() << std::endl;
		outFile << "Id: " << ptr->get_id() << std::endl;
		outFile << "Sala: " << int_to_sala(ptr);
		if (i < vec.size()) {
			outFile << "\n";
		}

	};
	for_each(vec.begin(), vec.end(), lamb);

	std::cout << "Baza danych zapisana." << std::endl;
	Sleep(2000);
}
Dane dane;
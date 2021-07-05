#include <iostream>
#include "Sala.h"
#include "Global.h"
using namespace Jednostka_lecznicza;


void Sala::dodaj(Pacjent*& ptr)
{
	if (lozka.size() == ilosc_lozek)

		std::cout << "\nSala jest pelna\n";

	else
		lozka.push_back(ptr);
}

void Sala::wyswietl()
{
	int nr = 1;
	if (lozka.size() == 0)
		std::cout << "Sala pusta.\n\n";
	else
		for (auto& i : lozka) {
			std::cout << "---------------------\n";
			std::cout << "Lozko nr: " << nr << std::endl;
			std::cout << i;
			nr++;
		}

}

void Sala::usun(const int nr)
{

	lozka.erase(lozka.begin() + nr);
}

void Sala::sprawdz()
{
	std::cout << "Sala " << Sala::get_nazwa() << ": " << Sala::sala_size() << std::endl;

}

size_t Sala::sala_size()
{
	return lozka.size();
}

Sala::Sala(std::string nazwa)
	:Pomieszczenie(nazwa) {}


void Sala::czysc_lozka()
{
	lozka.clear();
}



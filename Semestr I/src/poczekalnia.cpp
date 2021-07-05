#include <iostream>
#include "Poczekalnia.h"
#include <algorithm>

using namespace Jednostka_lecznicza;

void Poczekalnia::sprawdz()
{
	std::cout << Poczekalnia::get_nazwa() << ": " << rejestr_numerkow.size() << std::endl;
}

void Poczekalnia::sprawdz_poczekalnie() {

	auto lambda = [](const auto& map) {
		std::cout << map.first << std::endl;

	};
	std::for_each(rejestr_numerkow.begin(), rejestr_numerkow.end(), lambda);
}

Poczekalnia::Poczekalnia(std::string nazwa)
	:Pomieszczenie(nazwa) {}


void Poczekalnia::dodaj(std::string rodzaj_kolejki)
{

	rodzaj_kolejki += std::to_string(rand() % 100 + 1);
	rejestr_numerkow[rodzaj_kolejki] = std::make_unique<Pacjent>();
	q.push(rodzaj_kolejki);

}

void Poczekalnia::wywolaj()
{
	if (q.size() != 0) {
		std::cout << "Wywolany numerek: " << q.front() << std::endl;
		rejestr_numerkow.erase(q.front());
		q.pop();

	}
	else {
		std::cout << "Kolejka pusta.\n";
	}

}

size_t Poczekalnia::wielkosc_poczkekalni()
{
	return rejestr_numerkow.size();
}





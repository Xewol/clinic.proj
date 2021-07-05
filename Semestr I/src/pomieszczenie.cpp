#include <iostream>
#include "Pomieszczenie.h"
using namespace Jednostka_lecznicza;
Pomieszczenie::Pomieszczenie(std::string nazwa) { nazwa_pomieszczenia = nazwa; }

std::string Pomieszczenie::get_nazwa() const
{
	return nazwa_pomieszczenia;
}

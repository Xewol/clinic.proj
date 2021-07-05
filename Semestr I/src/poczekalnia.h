#ifndef POCZEKALNIA_H
#define POCZEKALNIA_H
#include "Pomieszczenie.h"
#include <unordered_map>
#include "Pacjent.h"
#include <queue>
#include <string>



using namespace Jednostka_lecznicza;
namespace Jednostka_lecznicza {

	class Poczekalnia : public Pomieszczenie {

	public:
		void sprawdz();
		void sprawdz_poczekalnie();
		Poczekalnia(std::string);
		void dodaj(std::string);
		void wywolaj();
		size_t wielkosc_poczkekalni();

	private:
		std::unordered_map<std::string, std::unique_ptr<Pacjent>>rejestr_numerkow;
		std::queue<std::string>q;



	};
}
static auto poczekalnia = std::make_unique<Poczekalnia>("Poczekalnia");
#endif // !POCZEKALNIA_H


#ifndef SALA_H
#define SALA_H
#include "Pacjent.h"
#include "Pomieszczenie.h"
using namespace Jednostka_lecznicza;
namespace Jednostka_lecznicza {



	class Sala : public Pomieszczenie {
	public:
		void dodaj(Pacjent*& ptr);
		void wyswietl();
		void usun(const int nr);
		void sprawdz();
		size_t sala_size();
		Sala(std::string);
		void czysc_lozka();



	private:
		std::vector<Pacjent*>lozka;
	protected:
		int ilosc_lozek = 5;




	};
}


static auto A1 = std::make_unique<Sala>("A1");
static auto A2 = std::make_unique<Sala>("A2");


#endif // !SALA_H

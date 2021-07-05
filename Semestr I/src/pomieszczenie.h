#ifndef POMIESZCZENIE_H
#define POMIESZCZENIE_H
namespace Jednostka_lecznicza {


	class Pomieszczenie {
	public:
		virtual void sprawdz() = 0;
		Pomieszczenie(std::string);
		std::string get_nazwa()const;

	private:
		std::string nazwa_pomieszczenia;
	};
}


#endif // !POMIESZCZENIE_H


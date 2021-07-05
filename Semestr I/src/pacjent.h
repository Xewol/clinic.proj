#ifndef PACJENT_H
#define PACJENT_H
#include <vector>

class Pacjent {
	class Lekarstwa {
		friend class Pacjent;
		const std::string tablica_lekow[4] = { "Ibuprofen","Paracetamol","Kodeina","Morfina" };
		std::vector<std::string>vec;
	public:
		void sprawdz_(Pacjent*& ptr);
		std::string zwroc_lek(const int);//return ^
		void podaj_lek();
		void spis_lekow();
	};

	std::string pesel;
	std::string imie;
	std::string nazwisko;
	int wiek{ 0 };
	int id{ 0 };
	Lekarstwa* leki_ptr{ nullptr };
	bool czy_sala{ false };
	bool czy_kolejka{ false };
	int nr_w_bazie{ 0 };
	int nazwa_sala{ 0 };



public:


	Pacjent(std::string pesel, std::string imie, std::string nazwisko, int wiek_);
	~Pacjent();


	Pacjent(std::string imie) {

		this->imie = imie;
	}
	Pacjent() { leki_ptr = new Lekarstwa(); };
	void set_imie(std::string);
	void set_nazwisko(std::string);
	void set_pesel(std::string);
	void set_wiek(int);
	void set_id(int);
	void set_sala(bool);
	void set_kolejka(bool);
	void set_nr_baza(const int);
	void set_nr_sala(const int);
	void dodaj_lek();
	void lista_lekarstw();

	std::string get_imie()const;
	std::string get_nazwisko()const;
	std::string get_pesel()const;
	const int get_wiek();
	const int get_id();
	bool get_sala()const;
	void get_dane()const;
	bool get_kolejka()const;
	int get_nr_baza()const;
	int get_nr_sala()const;


	friend std::ostream& operator<<(std::ostream& os, const Pacjent* pac);

};



#endif


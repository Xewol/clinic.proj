#include <iostream>
#include "Pacjent.h"
#include "Global.h"

void Pacjent::Lekarstwa::sprawdz_(Pacjent*& ptr)
{
	if (ptr->get_wiek() < 20) {

		std::cout << "!Maksymalna ilosc lekow to 1200mg!\n\n";
	}
}

std::string Pacjent::Lekarstwa::zwroc_lek(const int arg) { return tablica_lekow[arg]; }

void Pacjent::Lekarstwa::podaj_lek()
{
	vec.push_back("paracetamol");
}

void Pacjent::Lekarstwa::spis_lekow()
{
	int nr = 0;
	if (vec.size() == 0) {
		std::cout << "Pusta kartka." << std::endl;
	}
	else {
		std::cout << "Spis lekow pacjenta:\n\n";
		for (auto& i : vec) {
			nr++;
			std::cout << nr << ")" << i << std::endl;
		}
	}

}









std::ostream& operator<<(std::ostream& os, const Pacjent* pac)
{

	os << "Imie pacjenta: " << pac->imie << std::endl;
	os << "Nazwisko pacjenta: " << pac->nazwisko << std::endl;
	os << "Pesel pacjenta: " << pac->pesel << std::endl;
	os << "Wiek pacjenta: " << pac->wiek << std::endl;
	os << "Numer id pacjenta: " << pac->id << std::endl;

	return os;
}




Pacjent::Pacjent(std::string pesel, std::string imie, std::string nazwisko, int wiek_)

{

	this->pesel = pesel;
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wiek = wiek_;
	this->id = rand() % 1000 + 1;
	this->leki_ptr = new Lekarstwa;

}
Pacjent::~Pacjent()
{
	delete leki_ptr;
}




void Pacjent::set_imie(std::string imie_) { imie = imie_; }

void Pacjent::set_nazwisko(std::string nazwisko_) { nazwisko = nazwisko_; }

void Pacjent::set_pesel(std::string pesel_) { pesel = pesel_; }

void Pacjent::set_wiek(int wiek_) { wiek = wiek_; }

void Pacjent::set_id(int id_) { id = id_; }




void Pacjent::set_sala(bool arg) { czy_sala = arg; }

void Pacjent::set_kolejka(bool arg) { czy_kolejka = arg; }

void Pacjent::set_nr_baza(const int nr) { nr_w_bazie = nr; }

void Pacjent::set_nr_sala(const int nr)
{
	nazwa_sala = nr;
}

void Pacjent::dodaj_lek()
{
	system("cls");
	auto nr = 0;
	std::cout << "\t\t Dostepne leki: \n\n";
	for (auto& i : leki_ptr->tablica_lekow) {
		nr++;
		std::cout << nr << ")" << i << "\t";
	}
	std::cout << "\n\n";
	auto odp = 0;
	std::cin >> odp;
	if (odp >= 0 && odp < 5)
		leki_ptr->vec.push_back(leki_ptr->zwroc_lek(odp - 1));
	else {
		std::cout << "Bledny lek";
		Sleep(2000);
		dodaj_lek();
	}
}

void Pacjent::lista_lekarstw()
{
	leki_ptr->spis_lekow();
}



std::string Pacjent::get_imie() const { return imie; }

std::string Pacjent::get_nazwisko() const { return nazwisko; }

std::string Pacjent::get_pesel() const { return pesel; }

const int Pacjent::get_wiek() { return wiek; }

const int Pacjent::get_id() { return id; }


bool Pacjent::get_sala()const { return czy_sala; }



void Pacjent::get_dane() const
{

	std::cout << "Imie: " << imie << std::endl;
	std::cout << "Nazwisko: " << nazwisko << std::endl;
	std::cout << "Pesel: " << pesel << std::endl;
	std::cout << "Wiek: " << wiek << std::endl;
	std::cout << "Id: " << id << std::endl;
}

bool Pacjent::get_kolejka() const { return czy_kolejka; }

int Pacjent::get_nr_baza()const
{
	return nr_w_bazie;
}

int Pacjent::get_nr_sala() const
{
	return nazwa_sala;
}




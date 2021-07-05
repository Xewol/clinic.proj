#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "menu.h"
#include "Dane.h"
#include "Poczekalnia.h"
#include <algorithm>

using namespace Global;



void pacjent_tworz(Pacjent*&);
void menu_baza_danych();
void findby_menu(Pacjent*&);
void edit_pacjent(Pacjent*&);
void sala_menu(Pacjent*&);
void sala_z_menu_id();
int validate_sala(Pacjent*&);
void nr_to_sala(const int, Pacjent*&);
void sala_spis();
void dodaj_do_sali_z_menu();
int pesel_wiek(std::string);
void karta_lekow(Pacjent*&);
void obiekt();
void poczekalnia_();



//<---------------Sale---------->

void sala_A1_zwolnij() {
	system("cls");
	int odp;
	A1->wyswietl();

	std::cout << "\n\nKtore lozko zwolnic ?:" << std::endl;
	std::cin >> odp;
	odp = odp - 1;
	A1->usun(odp);
	pacjenci[odp]->set_nr_sala(0);
	pacjenci[odp]->set_sala(false);
}

void sala_A2_zwolnij() {
	system("cls");
	int odp;
	A2->wyswietl();

	std::cout << "\n\nKtore lozko zwolnic ?:" << std::endl;
	std::cin >> odp;
	odp = odp - 1;
	A2->usun(odp);
	pacjenci[odp]->set_nr_sala(0);
	pacjenci[odp]->set_sala(false);
}

int validate_sala(Pacjent*& arg) {

	system("cls");
	int odp;
	std::cout << arg << std::endl;
	std::cout << "Do jakiej sali chcesz dodac pacjenta:\n";
	std::cout << "1)Sala A1.\n";
	std::cout << "2)Sala A2.\n";
	std::cout << "0)Powrot.\n";
	std::cout << "Odpowiedz: \n";
	std::cin >> odp;
	switch (odp) {

	case 1:
		return 1;
		break;

	case 2:
		return 2;
		break;

	case 0:
		sala_z_menu_id();
		break;

	default:
		std::cout << "Bledny numer sali";

		break;
	}
	return false;
}

void nr_to_sala(const int nr, Pacjent*& ptr) {

	if (nr == 1) {
		A1->dodaj(ptr);
		ptr->set_sala(true);
		ptr->set_nr_sala(nr);
	}

	else if (nr == 2) {
		A2->dodaj(ptr);
		ptr->set_sala(true);
		ptr->set_nr_sala(nr);
	}

	std::cout << "\nPacjent dodany do sali.\n";
	Sleep(1000);
	sala_spis();
}

void sala_z_menu_id() {
	system("cls");
	int id;
	int nr_sala;
	Pacjent* ptr_found;
	std::cout << "Podaj id pacjenta: \n";
	std::cin >> id;
	ptr_found = find_in_db(id);
	if (ptr_found != nullptr) {

		if (ptr_found->get_sala() == true) {
			std::cout << "Pacjent jest juz zarajestrowany w sali " << int_to_sala(ptr_found) << std::endl;
			Sleep(1000);
		}
		else {
			nr_sala = validate_sala(ptr_found);
			nr_to_sala(nr_sala, ptr_found);
		}
	}



}


void sala_z_menu_pesel() {

	system("cls");
	std::string pesel;
	int nr_sala;
	Pacjent* ptr_found;
	std::cout << "Podaj pesel pacjenta: \n";
	std::cin >> pesel;
	ptr_found = find_in_db(pesel);
	if (ptr_found != nullptr) {

		if (ptr_found->get_sala() == true) {
			std::cout << "Pacjent jest juz zarajestrowany w sali " << int_to_sala(ptr_found) << std::endl;
			Sleep(1000);
		}
		else {
			nr_sala = validate_sala(ptr_found);
			nr_to_sala(nr_sala, ptr_found);
		}
	}


}

void zwolnij_lozko() {
	system("cls");
	int odp;
	std::cout << "Wybierz sale:\n";
	std::cout << "1)Sala A1:\n";
	std::cout << "2)Sala A2:\n";
	std::cout << "0)Powrot:\n";
	std::cin >> odp;
	switch (odp) {

	case 1:
		sala_A1_zwolnij();
		break;

	case 2:
		sala_A2_zwolnij();
		break;

	case 0:
		sala_spis();
	}
}

void dodaj_do_sali_z_menu() {

	system("cls");
	int odp = 0;
	std::cout << "1)Dodaj po numerze id.\n";
	std::cout << "2)Dodaj po numerze pesel.\n";
	std::cout << "0)Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{
	case 1:
		sala_z_menu_id();
		break;

	case 2:
		sala_z_menu_pesel();
		break;

	case 0:
		sala_spis();
		break;

	}

}
void sala_spis() {

	system("cls");
	std::cout << "Sala A1:\n";
	A1->wyswietl();
	std::cout << "\nSala A2:\n";
	A2->wyswietl();

	int odp = 0;
	std::cout << "\n1)Dodaj do sali.\n";
	std::cout << "2)Zwolnij lozko.\n";
	std::cout << "0)Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{

	case 1:
		dodaj_do_sali_z_menu();
		break;

	case 2:
		zwolnij_lozko();
		break;

	case 0:
		menu();
		break;
	}

}

//<!---------Sale------------>


//<------Baza Pacjentow--------->


void edit_imie(Pacjent*& ptr) {
	std::string new_imie;
	std::cout << "Podaj nowe imie: \n";
	std::cin >> new_imie;
	ptr->set_imie(new_imie);


}

void edit_nazwisko(Pacjent*& ptr) {

	std::string new_nazwisko;
	std::cout << "Podaj nowe nazwisko: \n";
	std::cin >> new_nazwisko;
	ptr->set_nazwisko(new_nazwisko);

}

void edit_wiek(Pacjent*& ptr) {

	int new_wiek;
	std::cout << "Podaj nowe wiek: \n";
	std::cin >> new_wiek;
	ptr->set_wiek(new_wiek);


}

void edit_pesel(Pacjent*& ptr) {


	std::string new_pesel;
	std::cout << "Podaj nowy pesel: \n\n";
	std::cin >> new_pesel;
	ptr->set_pesel(new_pesel);
	ptr->set_wiek(Global::pesel_wiek(new_pesel));


}

void sala_spis(Pacjent*& ptr) {
	system("cls");
	std::cout << "Sala A1:\n";
	A1->wyswietl();
	std::cout << "Sala A2:\n\n";
	A2->wyswietl();

	int odp = 0;
	std::cout << "0)Powrot.\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{
	case 0:
		sala_menu(ptr);
		break;
	}
}

void sala_menu(Pacjent*& ptr) {
	system("cls");
	int odp = 0;
	std::cout << "1)Sala A1.\n";
	std::cout << "2)Sala A2.\n";
	std::cout << "3)Spis Sali.\n";
	std::cout << "0)Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{
	case 1:
		if (ptr->get_sala() == true) {
			std::cout << "Osoba jest juz w sali " << int_to_sala(ptr) << std::endl;
			Sleep(1000);
		}

		else {
			A1->dodaj(ptr);
			ptr->set_nr_sala(1);
			ptr->set_sala(true);
		}
		menu_baza_danych();
		break;
	case 2:
		if (ptr->get_sala() == true) {
			std::cout << "Osoba jest juz w sali" << int_to_sala(ptr) << std::endl;
			Sleep(1000);
		}
		else {
			A2->dodaj(ptr);
			ptr->set_nr_sala(2);
			ptr->set_sala(true);
		}
		menu_baza_danych();
		break;

	case 3:
		sala_spis(ptr);
		break;

	case 0:
		menu_baza_danych();
		break;

	}

}
void podaj_lek(Pacjent*& ptr) {
	system("cls");
	ptr->dodaj_lek();
	karta_lekow(ptr);
}

void karta_lekow(Pacjent*& ptr) {

	int odp = 0;
	system("cls");
	ptr->lista_lekarstw();
	std::cout << "\n1)Podaj lek.\n";
	std::cout << "0) Powrot.\n";
	std::cin >> odp;
	switch (odp) {

	case 1:
		podaj_lek(ptr);
		break;

	case 0:
		findby_menu(ptr);

	}

}



void edit_pacjent(Pacjent*& ptr) {
	while (true) {
		int odp = 0;
		system("cls");
		std::cout << ptr << std::endl;
		std::cout << "\n1)Zmien imie.\n";
		std::cout << "2)Zmien nazwisko.\n";
		std::cout << "3)Zmien pesel(Wiek zmieni sie automatycznie na podstawie peselu).\n";
		std::cout << "4)Zmien wiek.\n";
		std::cout << "0)Zatwierdz/Wyjdz.\n\n";
		std::cout << "Odpowiedz: ";
		std::cin >> odp;
		switch (odp)
		{
		case 1:
			edit_imie(ptr);

			break;
		case 2:
			edit_nazwisko(ptr);
			break;
		case 3:
			edit_pesel(ptr);
			break;

		case 4:
			edit_wiek(ptr);
			break;

		case 0:
			menu_baza_danych();
			break;

		}
	}
}

void delete_pacjent(Pacjent*& ptr) {

	if (ptr->get_sala() == true) {
		std::cout << "Pacjent jest w sali, zwolnij wpierw jego lozko" << std::endl;
		Sleep(3000);

	}
	else {
		pacjenci.erase(pacjenci.begin() + ptr->get_nr_baza());
		delete ptr;
		menu_baza_danych();
	}

}

void findby_menu(Pacjent*& arg) {
	system("cls");

	std::cout << arg << std::endl;
	int odp = 0;
	std::cout << "\n\n1)Edytuj pacjenta.\n";
	std::cout << "2)Usun pacjenta.\n";
	std::cout << "3)Dodaj do sali.\n";
	std::cout << "4)Karta pacjenta.\n";
	std::cout << "0)Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{
	case 1:
		edit_pacjent(arg);
		break;
	case 2:
		delete_pacjent(arg);
		break;

	case 3:
		sala_menu(arg);
		break;

	case 4:
		karta_lekow(arg);
		break;
	case 0:
		menu_baza_danych();
		break;

	}
}

Pacjent* find_in_db(const int id) {
	int nr = 0;
	for (auto& i : pacjenci) {

		if (i->get_id() == id) {
			if (i->get_nr_baza() == 0)
			{
				i->set_nr_baza(nr);
				return i;
			}
			else
				return i;

		}
		else
			nr++;

	}

	std::cout << "\nNumeru id nie znaleziono w bazie danych.\n";
	Sleep(1000);
	return nullptr;
}

Pacjent* find_in_db(const std::string pesel)
{
	int nr = 0;
	for (auto& i : pacjenci) {
		if (i->get_pesel().compare(pesel) == 0) {

			if (i->get_nr_baza() == 0)
			{
				i->set_nr_baza(nr);
				return i;
			}
			else
				return i;
		}

		else
			nr++;
	}

	std::cout << "Nie znaleziono pacjenta o podanym numerze pesel.\n";
	Sleep(1000);
	return nullptr;

}

void search_pesel() {

	std::string pesel;
	Pacjent* ptr_found;
	std::cout << "Podaj pesel pacjenta: " << std::endl;
	std::cin >> pesel;
	ptr_found = find_in_db(pesel);
	if (ptr_found != nullptr)
		findby_menu(ptr_found);


}

void search_id()
{
	int id;
	Pacjent* ptr_found;
	std::cout << "Podaj id pacjenta: " << std::endl;
	std::cin >> id;
	ptr_found = find_in_db(id);
	if (ptr_found != nullptr)
		findby_menu(ptr_found);


}

void wyszukaj_pacjent_menu() {
	int odp = 0;
	system("cls");
	std::cout << "1)Wyszukaj po numerze pacjenta.\n";
	std::cout << "2)Wyszukaj po numerze pesel.\n";
	std::cout << "0)Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp)
	{
	case 1:
		search_id();
		break;
	case 2:
		search_pesel();
		break;

	case 0:
		menu_baza_danych();
		break;

	}


}

void menu_baza_danych() {
	int odp = 0;
	system("cls");

	pokaz_pacjentow();

	std::cout << "\n\n1) Wyszukaj pacjenta.\n";
	std::cout << "0) Powrot.\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp) {


	case 1:
		wyszukaj_pacjent_menu();
		break;

	case 0:
		menu();

	default:
		break;
	}
}
//<!-----Baza Pacjentow--------->




//<--------Rejestracja---------->

bool check_db(const std::string pesel) {

	for (auto& i : pacjenci)
		if (i->get_pesel().compare(pesel) == 0)
			return 0;

	return 1;
}

std::string pesel_check() {
	std::string pesel;
	std::cout << "Podaj pesel:" << std::endl;
	std::cin >> pesel;

	if (pesel.length() != 11) {
		std::cout << "\nNiepoprawna dlugosc peselu\n" << std::endl;
		pesel = pesel_check();
	}

	else {
		for (int i = 0; i < int(pesel.length()); i++) {
			if (!isdigit(pesel[i])) {
				std::cout << "w peselu wystêpuje litera badz znak" << std::endl;
				pesel = pesel_check();
			}


		}
	}
	return pesel;
}

int Global::pesel_wiek(std::string pesel) {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::string a = pesel.substr(0, 2);
	int b = std::stoi(a);
	int c = ltm->tm_year - 100;
	int wiek = b - c;
	if (wiek > 0) {

		wiek = abs(wiek - 100);
	}
	else {
		wiek = abs(b - c);
	}
	return wiek;
}

void tworzenie_imie(Pacjent*& arg) {
	std::string imie;
	std::cout << "Podaj imie:" << std::endl;
	std::cin >> imie;
	arg->set_imie(imie);

}

void tworzenie_nazwisko(Pacjent*& arg) {
	std::string nazwisko;
	std::cout << "Podaj nazwisko:" << std::endl;
	std::cin >> nazwisko;
	arg->set_nazwisko(nazwisko);

}

void pacjent_zatwierdz(Pacjent*& arg) {
	powieksz_baze(arg);
	std::cout << "Dodano pacjenta do bazy danych";
	Sleep(3000);
	menu();

}

void pacjent_tworz(Pacjent*& arg) {
	while (true) {
		int odp;
		system("cls");
		std::cout << "Tworzenie Pacjenta\n\n";
		std::cout << arg << std::endl;
		std::cout << "1) Wprowadz/Edytuj imie" << std::endl;
		std::cout << "2) Wprowadz/Edytuj nazwisko" << std::endl;
		std::cout << "3) Zatwierdz pacjenta i wroc" << std::endl;
		std::cout << "0) Przerwij tworzenie pacjenta" << std::endl << std::endl;
		std::cout << "Odpowiedz: ";
		std::cin >> odp;
		switch (odp) {

		case 1:
			tworzenie_imie(arg);
			break;

		case 2:
			tworzenie_nazwisko(arg);
			break;

		case 3:
			pacjent_zatwierdz(arg);
			break;

		case 0:
			delete arg;
			menu();

		}
	}
}

void rejestracja()
{
	srand((int)time(0));
	std::string pesel_ret;
	pesel_ret = pesel_check();
	Pacjent* _ptr_ = new Pacjent;
	_ptr_->set_id(rand() % 1000 + 1);
	if (check_db(pesel_ret)) {

		_ptr_->set_pesel(pesel_ret);
		_ptr_->set_wiek(Global::pesel_wiek(_ptr_->get_pesel()));
		pacjent_tworz(_ptr_);


	}
	else
	{
		std::cout << "\nPacjent istnieje w bazie danych\n";
		Sleep(3000);
		delete _ptr_;
	}



}

//<!---------Rejestracja--------->

void wczytaj() {

	A1->czysc_lozka();
	A2->czysc_lozka();
	zamknij_system();
	file_to_vector();

}
auto baza()
{
	int odp = 0;
	system("cls");
	std::cout << "1: Wczytaj baze pacjentow" << std::endl;
	std::cout << "2: Zapisz do bazy pacjentow" << std::endl;
	std::cout << "0: Powrot" << std::endl;
	std::cout << "\nOdpowiedz: ";
	std::cin >> odp;
	switch (odp) {
		while (true) {
	case 1:
		wczytaj();
		break;

	case 2:
		dane.zapisz(pacjenci);
		break;

	case 0:
		menu();
		break;

	default:

		break;
		}


	}

}

auto wyjscie()
{

	int odp = 0;
	system("cls");
	std::cout << "1: Wyjdz bez zapisywania do bazy." << std::endl;
	std::cout << "2: Zapisz, a nastepnie wyjdz z programu" << std::endl;
	std::cout << "0: Powrot" << std::endl;
	std::cout << "\nOdpowiedz: ";
	std::cin >> odp;
	switch (odp) {
		while (true) {
	case 1:
		zamknij_system();
		exit(0);
		break;

	case 2:
		dane.zapisz(pacjenci);
		zamknij_system();
		exit(0);
		break;

	case 0:
		menu();
		break;

	default:

		break;
		}


	}


}
void start()
{
	system("cls");
	std::cout << "Przychodnia:" << std::endl;
	std::cout << "\n1) Przychodnia." << std::endl;
	std::cout << "2) Rejestracja." << std::endl;
	std::cout << "\n0) Zamknij." << std::endl;
	int odp;
	std::cin >> odp;
	switch (odp) {


	case 1:
		menu();
		break;

	case 2:
		poczekalnia_();
		break;



	case 0:
		exit(0);
		break;





	}
}




void sprawdzanie() {
	system("cls");
	if (poczekalnia->wielkosc_poczkekalni() == 0) {
		std::cout << "Poczekalnia pusta.\n\n";
	}
	else {
		std::cout << "Poczekalnia: \n\n";
		poczekalnia->sprawdz_poczekalnie();
	}
	int odp;
	std::cout << "\n0) Powrot: " << std::endl;
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	if (odp == 0) {
		poczekalnia_();
	}

}

void wywolaj() {

	system("cls");
	poczekalnia->wywolaj();
	Sleep(2000);

}
void poczekalnia_()
{
	while (true) {
		int odp = 0;
		system("cls");
		std::cout << "1: Wgraj przykladowa poczekalnie" << std::endl;
		std::cout << "2: Pokaz poczekalnie" << std::endl;
		std::cout << "3: Wywolaj kolejny numerek" << std::endl;
		std::cout << "0: Powrot" << std::endl;
		std::cout << "\nOdpowiedz: ";
		std::cin >> odp;

		switch (odp) {

		case 1:
			imituj_poczekalnie();
			break;

		case 2:
			sprawdzanie();
			break;


		case 3:
			wywolaj();
			break;


		case 0:
			start();
			break;
		default:

			break;
		}

	}


}

void spis() {

	std::cout << "\n\t\t Pojemnosc obiektow:" << std::endl << std::endl;
	std::cout << "Wszystkich pacjentow: " << pacjenci.size() << "\n";
	poczekalnia->sprawdz();
	A1->sprawdz();
	A2->sprawdz();
	int odp = 0;
	std::cout << "\n\n0: Powrot\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;

	if (odp == 0) {
		obiekt();
	}
}
void obiekt() {

	int odp = 0;
	system("cls");
	std::cout << "1: Spis pojemnosci pomieszczen obiektu." << std::endl;
	std::cout << "0: Powrot\n\n";
	std::cout << "Odpowiedz: ";
	std::cin >> odp;
	switch (odp) {


	case 1:
		spis();
		break;

	case 0:
		menu();
	}

}


void menu()
{

	while (true) {

		int odp = 0;
		system("cls");
		std::cout << "1: Rejestracja" << std::endl;
		std::cout << "2: Baza pacjentow" << std::endl;
		std::cout << "3: Sale" << std::endl;
		std::cout << "4: Operacje na pliku baza.txt" << std::endl;
		std::cout << "5: Zarzadzanie obiektem." << std::endl;
		std::cout << "0: Wyjscie\n\n";
		std::cout << "Odpowiedz: ";
		std::cin >> odp;  
		switch (odp) {
			while (true) {
		case 1:
			rejestracja();
			break;

		case 2:
			menu_baza_danych();
			break;

		case 3:
			sala_spis();
			break;

		case 4:
			baza();
			break;
		case 5:
			obiekt();
			break;

		case 0:
			wyjscie();
			break;

		default:

			break;
			}


		}

	}

}


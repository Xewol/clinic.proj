#ifndef GLOBAL_H
#define GLOBAL_H
#include "Sala.h"
#include <fstream>
#include <Windows.h>
#include "Poczekalnia.h"
#include <ctime>
#include <random>
namespace Global {




	int pesel_wiek(std::string);



	inline std::string int_to_sala(Pacjent*& ptr)
	{
		std::string sala;
		if (ptr->get_sala() == true) {
			if (ptr->get_nr_sala() == 1) {
				sala = "A1";
				return sala;
			}
			else {
				sala = "A2";
				return sala;
			}

		}
		else {
			sala = "Brak";
			return sala;
		}


	}

	inline auto imituj_poczekalnie() {
		srand((int)time(0));
		poczekalnia->dodaj("A");
		poczekalnia->dodaj("B");
		poczekalnia->dodaj("C");
		poczekalnia->dodaj("C");
		poczekalnia->dodaj("B");
		poczekalnia->dodaj("A");
		poczekalnia->dodaj("B");
		poczekalnia->dodaj("C");
		poczekalnia->dodaj("C");
		poczekalnia->dodaj("A");


	}

	static std::vector<Pacjent*> pacjenci;


	inline void powieksz_baze(Pacjent* pac_) { pacjenci.push_back(pac_); }



	inline void zamknij_system() {
		for (auto i : pacjenci)
			delete i;

		pacjenci.clear();
	}

	inline void pokaz_pacjentow() {
		int nr = 1;
		if (pacjenci.size() == 0)
			std::cout << "Brak pacjentow.\n";
		else {
			for (auto& i : pacjenci) {
				std::cout << "---------------------\n";
				std::cout << "Pacjent nr " << nr << std::endl << std::endl;
				std::cout << i;
				nr++;

			}
		}


	}

	inline auto save_to_file() {

		if (pacjenci.size() == 0) {
			std::cout << "Brak pacjentow do zapisania do bazy danych\n";
			Sleep(2000);
		}
		else {
			std::ofstream outFile("baza.txt");
			int iterator = 0;
			for (auto& e : pacjenci) {
				iterator++;
				outFile << "Imie: " << e->get_imie() << std::endl;
				outFile << "Nazwisko: " << e->get_nazwisko() << std::endl;
				outFile << "Pesel: " << e->get_pesel() << std::endl;
				outFile << "Wiek: " << e->get_wiek() << std::endl;
				outFile << "Id: " << e->get_id() << std::endl;
				outFile << "Sala: " << int_to_sala(e);
				if (iterator < int(pacjenci.size())) {
					outFile << "\n";
				}
			}
			std::cout << "Baza danych zapisana." << std::endl;
			Sleep(2000);
		}

	}

	inline auto file_to_vector() {

		std::string line;
		std::fstream file;
		file.open("baza.txt");
		int cnt = 0;
		Pacjent* pac = new Pacjent;

		while (std::getline(file, line))
		{
			auto index = line.find(":");
			switch (cnt)
			{
			case 0:

				pac->set_imie(line.substr(index + 2));
				break;
			case 1:

				pac->set_nazwisko(line.substr(index + 2));
				break;
			case 2:

				pac->set_pesel(line.substr(index + 2));

				break;
			case 3:

				pac->set_wiek(stoi(line.substr(index + 2)));
				break;
			case 4:

				pac->set_id(stoi(line.substr(index + 2)));
				break;
			case 5:

				if (line.substr(index + 2).compare("A1") == 0) {
					pac->set_sala(true);
					pac->set_nr_sala(1);
					A1->dodaj(pac);
				}
				else if (line.substr(index + 2).compare("A2") == 0) {
					pac->set_sala(true);
					pac->set_nr_sala(2);
					A2->dodaj(pac);
				}
				else if (line.substr(index + 2).compare("Brak") == 0) {

				}
				break;
			}
			if (cnt == 5)
			{
				cnt = -1;
				pacjenci.push_back(pac);
				pac = new Pacjent;
			}
			cnt++;
		}
		delete pac;
	}

}

#endif // !GLOBAL_H


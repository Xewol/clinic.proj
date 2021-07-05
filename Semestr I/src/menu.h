#ifndef MENU_H
#define MENU_H
#include "Global.h"
void menu();

using namespace Global;

void rejestracja();

std::string pesel_check();

bool check_db(const std::string pesel);

Pacjent* find_in_db(const int id);

Pacjent* find_in_db(const std::string pesel);

int pesel_wiek(std::string);

std::string pesel_check();

auto baza();

auto wyjscie();

void poczekalnia_();

void start();



#endif // !MENU_H


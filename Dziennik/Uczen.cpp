#include "stdafx.h"
#include "Uczen.h"

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

Uczen::Uczen()
{
	nazwisko = "braknazwiska";
	nr = stanklasy;
	obecnosc = false;
	//osize = 0;
}

Uczen::Uczen(string nazw)
{
	nazwisko = nazw;
	obecnosc = true;
	nr = stanklasy;
	//osize = 0;
}

Uczen::Uczen(const Uczen &ucopy)
{
	nazwisko = ucopy.nazwisko;
	nr = ucopy.nr;
	obecnosc = ucopy.obecnosc;
	//osize = ucopy.osize;
	ocenki = ucopy.ocenki;
	//oceny = new Ocena[osize];
	//for (int i = 0;i < osize;i++) {
	//	oceny[i] = ucopy.oceny[i];
	//}
}

string Uczen::GetNazwisko()
{
	return nazwisko;
}

int Uczen::GetNr()
{
	return nr;
}

bool Uczen::GetObecnosc()
{
	return obecnosc;
}
/*
void Uczen::AddOcena(Ocena nowa)
{
	if(oceny == NULL) {
		oceny = new Ocena[1];
		oceny[0] = nowa;
		osize = 1;
	}
	else {
		Ocena* oceny_nowa = new Ocena[osize + 1];
		for (int i = 0;i<osize;i++) {
			oceny_nowa[i] = oceny[i];
		}
		oceny_nowa[osize] = nowa;
		oceny = oceny_nowa;
		osize++;
	}
}
*/

void Uczen::AddO(string aprzedmiot)
{
	int value = 0;
	do {
		printf("Podaj ocene:\n");
		cin >> value;
		if (Errr.GradeValue(value) == true)
			break;
	} while (Errr.GradeValue(value) == false);

	int gtype;
	do {
		printf("Za co uczen otrzymal ocene (1 = Sprawdzian 2 = Kartkowka 3 = Aktywnosc \n");
		cin >> gtype;
		if (Errr.GradeType(gtype) == true)
			break;
	} while (Errr.GradeType(gtype) == false);
	if (gtype == 1) {
		//Ocena* nowa = new Sprawdzian(value, aprzedmiot);
		Ocena *nowa = new Sprawdzian(value, aprzedmiot);
		ocenki.push_back(nowa);
	}
	else if (gtype == 2) {
		//Ocena* nowa = new Kartkowka(value, aprzedmiot);
		Ocena *nowa = new Kartkowka(value, aprzedmiot);
		ocenki.push_back(nowa);
	}
	else if (gtype == 3) {
		//Ocena* nowa = new Aktywnosc(value, aprzedmiot);
		Ocena *nowa = new Aktywnosc(value, aprzedmiot);
		ocenki.push_back(nowa);
	}
}

Ocena Uczen::GetOcena(int index)
{
	return Ocena();// oceny[index];
}

int Uczen::GetIloscOcen()
{
	//return osize;
	return ocenki.size();
}


void Uczen::SetNazwisko(string nzw)
{
	nazwisko = nzw;
}

void Uczen::SetNr(int nr2)
{
	nr = nr2;
}

void Uczen::SetObecnosc(int o)
{
	if (o == 1) {
		obecnosc = true;
	}
	else {
		obecnosc = false;
	}
}

void Uczen::PrintOceny()
{
	int siz = ocenki.size();
	for (int i = 0;i< siz ;i++) {
		ocenki.at(i)->Print();
		cout << endl;
	}
	printf("\n\n");
}


void Uczen::Print()
{
	string presence;
	if (obecnosc == true)
		presence = "TAK";
	else
		presence = "NIE";

	cout << "Nr: " << nr << ", Nazwisko: " << nazwisko << ". Czy jest teraz obecny: " << presence << "\n";
	PrintOceny();
}

Uczen& Uczen::operator=(const Uczen& student)
{
	this->nazwisko = student.nazwisko;
	this->obecnosc = student.obecnosc;
	this->nr = student.nr;
	//this->osize = student.osize;
	this->ocenki = student.ocenki;
	//oceny = new Ocena[osize];
	//for (int i = 0;i < osize;i++) {
	//	oceny[i] = student.oceny[i];
	//}
	return *this;
}

Uczen::~Uczen()
{
	//delete[] oceny;
	//oceny = NULL;
	ocenki.clear();
}

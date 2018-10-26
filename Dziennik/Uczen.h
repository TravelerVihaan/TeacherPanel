#pragma once
#include "stdafx.h"
#include "Ocena.h"
#include "Errors.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <vector>

using namespace std;

class Uczen{
protected:
	//int osize;
	string nazwisko;
	bool obecnosc;
	int nr;
	//Ocena* oceny;
	Errors Errr;
	vector<Ocena*> ocenki;
public:
	// KONSTRUKTORY
	Uczen();
	Uczen(string nazw);
	// POBIERANIE DANYCH KLASY
	string GetNazwisko();
	int GetNr();
	bool GetObecnosc();
	void EditOcena(int index)
	{
		//oceny[index].Print();
		cout << endl;
		int value;
		do {
			printf("Na jaki stopien ocena zostala poprawiona?\n");
			cin >> value;
			if (Errr.GradeValue(value) == true)
				break;
		} while (Errr.GradeValue(value) == false);
		ocenki.at(index)->Poprawa(value);
		//oceny[index].Poprawa(value);
	}
	//void AddOcena(Ocena nowa);
	void AddO(string aprzedmiot);
	Ocena GetOcena(int index);
	int GetIloscOcen();
	// FUNKCJE DO ZMIANY DANYCH
	void SetNazwisko(string nzw);
	void SetNr(int nr2);
	void SetObecnosc(int o);
	void PrintOceny();
	void Print();
	// STATYCZNA ZMIENNA
	static int stanklasy;
	Uczen& operator=(const Uczen& student);
	Uczen(const Uczen& ucopy);
	~Uczen();
};




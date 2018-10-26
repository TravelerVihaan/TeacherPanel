#pragma once
#include "stdafx.h"

#include "Przedmiot.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Lekcja : 
	public Przedmiot
{
	string tematlekcji;
	int nrlekcji;
public:
	//KONSTRUKTORY
	Lekcja();
	Lekcja(string prz) : Przedmiot(prz) { 
		nrlekcji = numerlekcji; 
		tematlekcji.clear();
	}
	// POBIERANIE ELEMENTOW
	string GetTemat();
	int GetNr();
	string GetSubject();
	Lekcja & operator=(const Lekcja& lesson);
	void SetTemat();
	void PrintL();
	void SetTemat(string topic);
	void Export();
	// STATYCZNA ZMIENNA
	static int numerlekcji;
	string PrintSubject();
	//DESTRUKTOR
	~Lekcja();
};

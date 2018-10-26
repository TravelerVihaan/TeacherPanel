#pragma once
#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

class Przedmiot
{
protected:
	string przedm;
public:
	Przedmiot();
	string GetSubject() { return przedm; };
	Przedmiot(string prz);
	void SetPrzedmiot(string prz);
	Przedmiot& operator=(const Przedmiot& subject);
	virtual ~Przedmiot();
};


#include "stdafx.h"
#include "Ocena.h"

#include <iostream>
#include <stddef.h>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

Sprawdzian::Sprawdzian(const Sprawdzian & oc)
{
		value = oc.value;
		t = oc.t;
		przedmiot = oc.przedmiot;
}

Sprawdzian & Sprawdzian::operator=(Sprawdzian & oc)
{
		this->value = oc.value;
		this->t = oc.t;
		this->przedmiot = przedmiot;
		return *this;
}

void Sprawdzian::Poprawa(int p)
{
	this->SetValue(p);
}

void Sprawdzian::Print()
{
	cout << "Ocena: " << value << " ze sprawdzianu. Przedmiot: " << przedmiot << "\n";
}

bool Sprawdzian::operator==(const Sprawdzian & oc)
{
	if (this->value == oc.value && this->t == oc.t)
		return true;
	else
		return false;
}

bool Sprawdzian::operator<(const Sprawdzian & oc)
{
	if (this->value < oc.value)
		return true;
	else
		return false;
}

bool Sprawdzian::operator>(const Sprawdzian & oc)
{
	if (this->value > oc.value)
		return true;
	else
		return false;
}

bool Sprawdzian::operator<=(const Sprawdzian & oc)
{
	if (this->value <= oc.value)
		return true;
	else
		return false;
}

bool Sprawdzian::operator>=(const Sprawdzian & oc)
{
	if (this->value >= oc.value)
		return true;
	else
		return false;
}

bool Sprawdzian::operator!=(const Sprawdzian & oc)
{
	if (this->value != oc.value && this->t != oc.t)
		return true;
	else
		return false;
}

Sprawdzian::~Sprawdzian()
{
}

void Ocena::SetValue(int v)
{
	value = v;
}

void Ocena::SetType(int tt)
{
	// t=1 sprawdzian
	// t=2 kartkowka
	// t=3 aktywnosc
	t = tt;
}

bool Ocena::operator==(const Ocena & oc)
{
	if (this->value == oc.value && this->t == oc.t)
		return true;
	else
		return false;
}

bool Ocena::operator<(const Ocena & oc)
{
	if (this->value < oc.value)
		return true;
	else
		return false;
}

bool Ocena::operator>(const Ocena & oc)
{
	if (this->value > oc.value)
		return true;
	else
		return false;
}

bool Ocena::operator<=(const Ocena & oc)
{
	if (this->value <= oc.value)
		return true;
	else
		return false;
}

bool Ocena::operator>=(const Ocena & oc)
{
	if (this->value >= oc.value)
		return true;
	else
		return false;
}

bool Ocena::operator!=(const Ocena & oc)
{
	if (this->value != oc.value && this->t != oc.t)
		return true;
	else
		return false;
}

Ocena::Ocena(Ocena & oc)
	{
		value = oc.value;
		t = oc.t;
		przedmiot = przedmiot;
	}

Ocena & Ocena::operator=(const Ocena & oc)
{
	this->value = oc.value;
	this->t = oc.t;
	this->przedmiot = przedmiot;
	return *this;
}

Ocena::~Ocena()
{
}


Kartkowka::Kartkowka(const Kartkowka & oc)
{
	value = oc.value;
	t = oc.t;
	przedmiot = oc.przedmiot;
}

Kartkowka & Kartkowka::operator=(const Kartkowka & oc)
{
		this->value = oc.value;
		this->t = oc.t;
		this->przedmiot = przedmiot;
		return *this;
}

void Kartkowka::Poprawa(int p)
{
	this->SetValue(p);
}

void Kartkowka::Print()
{
	cout << "Ocena: " << value << " z kartkowki. Przedmiot: " << przedmiot << "\n";
}

bool Kartkowka::operator==(const Kartkowka & oc)
{
	if (this->value == oc.value && this->t == oc.t)
		return true;
	else
		return false;
}

bool Kartkowka::operator<(const Kartkowka & oc)
{
	if (this->value < oc.value)
		return true;
	else
		return false;
}

bool Kartkowka::operator>(const Kartkowka & oc)
{
	if (this->value > oc.value)
		return true;
	else
		return false;
}

bool Kartkowka::operator<=(const Kartkowka & oc)
{
	if (this->value <= oc.value)
		return true;
	else
		return false;
}

bool Kartkowka::operator>=(const Kartkowka & oc)
{
	if (this->value >= oc.value)
		return true;
	else
		return false;
}

bool Kartkowka::operator!=(const Kartkowka & oc)
{
	if (this->value != oc.value && this->t != oc.t)
		return true;
	else
		return false;
}

Kartkowka::~Kartkowka()
{
}

Aktywnosc::Aktywnosc(const Aktywnosc & oc)
{
	value = oc.value;
	t = oc.t;
	przedmiot = oc.przedmiot;
}

Aktywnosc & Aktywnosc::operator=(const Aktywnosc & oc)
{
	//this->value = oc.value;
	//this->t = oc.t;
	//this->przedmiot = przedmiot;
	Ocena::operator=(oc);
	return *this;
}

void Aktywnosc::Poprawa()
{
	printf("Niestety oceny z aktywnosci nie mozna poprawiac. \n");
}

void Aktywnosc::Print()
{
	cout << "Ocena: " << value << " z aktywnosci. Przedmiot: " << przedmiot << "\n";
}

bool Aktywnosc::operator==(const Aktywnosc & oc)
{
	if (this->value == oc.value && this->t == oc.t)
		return true;
	else
		return false;
}

bool Aktywnosc::operator<(const Aktywnosc & oc)
{
	if (this->value < oc.value)
		return true;
	else
		return false;
}

bool Aktywnosc::operator>(const Aktywnosc & oc )
{
	if (this->value > oc.value)
		return true;
	else
		return false;
}

bool Aktywnosc::operator<=(const Aktywnosc & oc)
{
	if (this->value <= oc.value)
		return true;
	else
		return false;
}

bool Aktywnosc::operator>=(const Aktywnosc & oc)
{
	if (this->value >= oc.value)
		return true;
	else
		return false;
}

bool Aktywnosc::operator!=(const Aktywnosc & oc)
{
	if (this->value != oc.value && this->t != oc.t)
		return true;
	else
		return false;
}

Aktywnosc::~Aktywnosc()
{
}
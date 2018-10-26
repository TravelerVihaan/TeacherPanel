#pragma once
#include "stdafx.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Ocena {
protected:
	int value;
	int t;
	string przedmiot;
public:
	Ocena() { value = 0; t = 0; };
	Ocena(int v, string przed) { value = v; przedmiot = przed; };
	Ocena(int v, string przed, int typ) { value = v; przedmiot = przed; t = typ; };
	void SetValue(int v);
	void SetType(int tt);
	int GetValue() { return value; };
	int GetType() { return t; };
	virtual void Print() {
	}
	virtual void Poprawa(int p) {
	}
	bool operator ==(const Ocena &);
	bool operator <(const Ocena &);
	bool operator >(const Ocena &);
	bool operator <=(const Ocena &);
	bool operator >=(const Ocena &);
	bool operator !=(const Ocena &);
	Ocena(Ocena& oc);
	Ocena& operator=(const Ocena& oc);
	virtual ~Ocena();
};

class Sprawdzian : public Ocena
{
public:
	Sprawdzian(int v, string przed) : Ocena(v, przed) { 
		Ocena::t = 1; 
	}
	Sprawdzian(const Sprawdzian& oc);
	Sprawdzian& operator=(Sprawdzian& oc);
	void Poprawa(int p);
	void Print();
	bool operator ==(const Sprawdzian &);
	bool operator <(const Sprawdzian &);
	bool operator >(const Sprawdzian &);
	bool operator <=(const Sprawdzian &);
	bool operator >=(const Sprawdzian &);
	bool operator !=(const Sprawdzian &);
	~Sprawdzian();
};

class Kartkowka : public Ocena
{
public:
	Kartkowka(int v, string przed) : Ocena(v, przed) { 
		Ocena::t = 2;
	}
	Kartkowka(const Kartkowka& oc);
	Kartkowka& operator=(const Kartkowka& oc);
	void Poprawa(int p);
	void Print();
	bool operator ==(const Kartkowka &);
	bool operator <(const Kartkowka &);
	bool operator >(const Kartkowka &);
	bool operator <=(const Kartkowka &);
	bool operator >=(const Kartkowka &);
	bool operator !=(const Kartkowka &);
	~Kartkowka();
};

class Aktywnosc : public Ocena {
public:
	Aktywnosc(int v, string przed) : Ocena(v, przed) { 
		Ocena::t = 3; 
	}
	Aktywnosc(const Aktywnosc& oc);
	Aktywnosc& operator=(const Aktywnosc& oc);
	void Poprawa();
	void Print();
	bool operator ==(const Aktywnosc &);
	bool operator <(const Aktywnosc &);
	bool operator >(const Aktywnosc &);
	bool operator <=(const Aktywnosc &);
	bool operator >=(const Aktywnosc &);
	bool operator !=(const Aktywnosc &);
	~Aktywnosc();
};
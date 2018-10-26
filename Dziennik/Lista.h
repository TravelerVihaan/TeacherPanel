#pragma once
#include "stdafx.h"

#include "Uczen.h"

#include <iostream>
#include <string>

using namespace std;

template < class Typ>
class Lista
{
protected:
	int size;
	Typ * list;
public:
	//KONSTRUKTORY
	Lista()
	{
		list = NULL;
		size = 0;
	}
	Lista(Typ abc)
	{
		size = 1;
		list = new Typ[size];
		list[0] = abc;
	}
	// DODAWANIE NOWEGO ELEMENTU
	void Add(Typ& nowy) {
		if (list == NULL) {
			list = new Typ[size+1];
			list[0] = nowy;
			size = 1;
		}
		else {
			Typ *list_nowa = new Typ[size+1];
			for (int i = 0;i<size;i++) {
				list_nowa[i] = list[i];
			}
			list_nowa[size] = nowy;
			list = list_nowa;
			size++;
		}
	}
	// EDYCJA ELEMENTU
	void Edit(Typ nowy, int index) {
		list[index] = nowy;
	}
	// USUWANIE ELEMENTU UCZNIA
	template <class Typ = Uczen >
	void Delete(int index) {
		if (index < 0 || index >= size) {
			printf("Blad: nieprawidlowy indeks elementu na liscie\n");
		}
		else {
			int realindex = index - 1;
			bool flag = false;
			Typ *list_nowa = new Typ[size - 1];
			for (int i = 0;i < size - 1;i++) {
				if (i != realindex || flag == false) {
					list_nowa[i] = list[i];
					i++;
				}
				else if (i != realindex || flag == true) {
					list_nowa[i] = list[i];
					list_nowa[i].SetNr(i);
					i++;
				}
				else {
					// tu usuwany uczen zostaje pomijany oraz i nie zostaje zwiekszone
					flag = true;
				}
			}
			list = list_nowa;
			Uczen::stanklasy--;
			delete[] list_nowa;
			list = NULL;
		}
	}
	// FUNKCJE DLA UCZNIA
	template <class Typ = Uczen >
	void AddOc(int nru, string aprzedmiot) {
		list[nru].AddO(aprzedmiot);
	}
	template <class Typ = Uczen >
	void SetO(int nru, int ob) {
		list[nru].SetObecnosc(ob);
	}
	// FUNKCJE DLA LEKCJI
	template <class Typ = Lekcja >
	void TypeTopic(int nrl) {
		list[nrl].SetTemat();
	}
	template <class Typ = Lekcja >
	void GTopic(int nrl, string temat) {
		list[nrl].SetTemat(temat);
	}
	template <class Typ = Lekcja >
	void PrintLesson(int nrl) {
		list[nrl].PrintL();
	}
	template <class Typ = Lekcja >
	void ExportL(int nrl) {
		list[nrl].Export();
	}
	// KONSTRUKTOR KOPIUJACY
	Lista(Lista& lcopy) {
		size = lcopy.size;
		list = new Typ[size];
		for (int i = 0;i < size;i++) {
			list[i] = lcopy.list[i];
		}
	}

	// POBIERANIE ROZMIARU LISTY
	int GetSize() { return size; };
	// OPERATOR PRZYPISANIA
	Lista<Typ> & operator=(const Lista<Typ>& clista)
	{
		this->size = clista.size;
		this->list = new Typ[size];
		for (int i = 0;i < size;i++) {
			this->list[i] = clista.list[i];
		}
		return *this;
	}
	// OPERATOR WYPISANIA
	//friend ostream& operator<<(ostream&, const Lista<Typ>&);
	Typ EList(int x) {
		return list[x];
	}
	Typ Llist(int x) {
		return list[x];
	}
	// DESTRUKTOR
	~Lista()
	{
		delete [] list;
		list = NULL;
	}
};


#include "stdafx.h"
#include "Lista.h"

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>
#include <stddef.h>

using namespace std;

/*
template<class Typ>
void Lista<Typ>::Print() {
	for (int i = 0;i < GetSize();i++)
		cout << i << ". " << list[i] << "\n";
}
*/

/*
template<class Typ>
void Lista<Typ>::Add(Typ nowy)
{
	if (list == NULL) {
		list = new Typ[1];
		list[0] = nowy;
		size = 1;
	}
	else {
		Typ *list_nowa = new Typ[size + 1];
		for (int i = 0;i<size + 1;i++) {
			list_nowa[i] = list[i];
		}
		list_nowa[size] = nowy;
		list = list_nowa;
		size++;
	}
}
*/


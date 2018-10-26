#include "stdafx.h"
#include "Przedmiot.h"

#include <string>
#include <iostream>

Przedmiot::Przedmiot()
{
}

Przedmiot::Przedmiot(string prz)
{
	przedm = prz;
}

void Przedmiot::SetPrzedmiot(string prz)
{
	przedm = prz;
}

Przedmiot & Przedmiot::operator=(const Przedmiot & subject)
{
	this->przedm = subject.przedm;
	return *this;
}

Przedmiot::~Przedmiot()
{
}


//Przedmiot::Przedmiot(string prz)
//{
//	przedm = prz;
//	tabsize = 1;
//	lekcje = new string[tabsize];
//	cout << "Prosze wpisac do dziennika temat pierwszej lekcji z przedmiotu " << przedm << "\n";
//	cin.sync();
//	getline(cin, lekcje[0]);	
//}

//void Przedmiot::WpiszTemat()
//{
//	tabsize = tabsize + 1;
//	string *lk = new string[tabsize];
//	for (int i = 0;i < tabsize;i++) {
//		lk[i] = lekcje[i];
//	}
//	lekcje = lk;
//	delete[] lk;
//	cout << "Lekcja nr. " << tabsize << ". Przedmiot: " << przedm << "\n";
//	cout << "Prosze wpisac do dziennika temat lekcji: \n";
//	cin.sync();
//	getline(cin, lekcje[tabsize]);
//}

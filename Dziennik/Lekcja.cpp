#include "stdafx.h"

#include "Lekcja.h"
#include "Przedmiot.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Lekcja::Lekcja()
{
	nrlekcji = numerlekcji;
}

string Lekcja::GetTemat()
{
	cout << tematlekcji;
	return tematlekcji;
}

int Lekcja::GetNr()
{
	return nrlekcji;
}

string Lekcja::GetSubject()
{
	return Przedmiot::przedm;
}

Lekcja & Lekcja::operator=(const Lekcja & lesson)
	{
		this->Przedmiot::operator=(lesson.przedm);
		this->nrlekcji = lesson.nrlekcji;
		this->tematlekcji = lesson.tematlekcji;
		return *this;
	}

void Lekcja::SetTemat()
{
	printf("Prosze podac temat, ktory ma byc wpisany jako temat biezacej lekcji:\n");
	//string tmt;
	cin.ignore();
	cin.sync();
	getline(cin, tematlekcji);
	//cout << tmt;
}

void Lekcja::PrintL()
{
	cout << "Lekcja nr. " << numerlekcji << ". Przedmiot: " << przedm << ". Temat: " << tematlekcji << "\n";
}

void Lekcja::SetTemat(string topic)
{
	tematlekcji = topic;
	if (tematlekcji == topic)
		printf("Udalo sie wpisac temat lekcji!\n");
}

void Lekcja::Export()
{
	ofstream file1("zapis.txt");
	//file1.open("zapis.txt");
	//, ios::in | ios::out
	if (file1.is_open() == true) {
		//Lekcja *temp = NULL;
		//*temp = lekcje.Llist(Lekcja::numerlekcji - 1);
		file1 << tekst;
		file1<< "Lekcja nr: ";
		file1<< numerlekcji;
		file1<< ". Przedmiot: ";
		file1<< przedm;
		file1<< ". Temat: ";
		file1<< tematlekcji;
		file1<< "\n";
		//delete temp;
		file1.close();
	}
	else {
		printf("Nie udalo sie otworzyc pliku!\n");
	}
}


string Lekcja::PrintSubject()
{
	if (Przedmiot::przedm == "polski")
		return "Jezyk Polski";
	else if (Przedmiot::przedm == "matematyka")
		return "Matematyka";
	else if (Przedmiot::przedm == "historia")
		return "Historia";
	else if (Przedmiot::przedm == "przyroda")
		return "Przyroda";
	else if (Przedmiot::przedm == "angielski")
		return "Jezyk Angielski";
	else if (Przedmiot::przedm == "fizyka")
		return "Fizyka";
	else
		return "nn";
}

Lekcja::~Lekcja()
{
}

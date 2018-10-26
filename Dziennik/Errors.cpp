#include "stdafx.h"
#include "Errors.h"
#include "Uczen.h"

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

Errors::Errors()
{
	//NIC NIE ROBI!!
	//JEST TO ZBIÓR FUNKCJI DO OBSLUGI BLEDOW!!
}

bool Errors::MainMenu1(char choice)
{
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '0') {
		return true;
	}
	else {
		printf("Twoj wybor nie odpowiada zadnej z dostepnych opcji! Prosze dokonac wlasciwego wyboru.\n");
		return false;
	}
}

bool Errors::MainMenu2(char choice)
{
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' || choice == '0')
		return true; 
	else {
		printf("Twoj wybor nie odpowiada zadnej z dostepnych opcji! Prosze dokonac wlasciwego wyboru.\n");
		return false;
	}
}

bool Errors::MenuStudent(char choice)
{
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '0')
		return true;
	else {
		printf("Blad! Twoj wybor nie pasuje do zadnej z powyzszych opcji!!\n");
		return false;
	}
}

bool Errors::MenuLesson(char choice)
{
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' || choice == '0')
		return true;
	else {
		printf("Blad! Twoj wybor nie pasuje do zadnej z powyzszych opcji!!\n");
		return false;
	}
}

bool Errors::SubjectMenu(char choice)
{
	if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '0')
		return true;
	else {
		printf("Blad! Twoj wybor nie pasuje do zadnej z powyzszych opcji!!\n");
		return false;
	}
}

bool Errors::LiczbaLekcji(int liczbal)
{
	if (liczbal < 1) {
		cout << "Niestety jeszcze ani jedna lekcja nie zostala rozpoczeta. \n";
		return false;
	}
	else
		return true;
}

bool Errors::LiczbaUczniow(int liczbau)
{
	if (liczbau < 1) {
		printf("Niestety nie ma nikogo na liscie uczniow \n");
		return false;
	}
	else
		return true;
}

bool Errors::CheckPresence(int liczbau){
		if (liczbau > 0)
			return true;
		else {
			printf("Blad: Nie ma w klasie zadnych uczniow \n");
			return false;
		}
	}
bool Errors::SearchType(char choice)
{
	if (choice == '1' || choice == '2')
		return true;
	else {
		printf("Prosze wybrac odpowiednia opcje wyszukiwania!\n");
		return false;
	}
}
bool Errors::SearchingNr(int snr)
{
	if (snr > Uczen::stanklasy || snr < 1) {
		printf("\nUczen o podanym numerze nie istnieje!\n");
		return false;
	}
	else {
		return true;
	}
}
bool Errors::GradeValue(int value)
{
	if (value < 0 || value > 6) {
		printf("Podales zla wartosc oceny! Prosze podac odpowiednia wartosc z przedzialu 1-6");
		return false;
	}
	else
		return true;	
}
bool Errors::GradeType(int gtype)
{
	if (gtype == 1 || gtype == 2 || gtype == 3)
		return true;
	else {
		printf("Prosze wybrac odpowiednia opcje!\n");
		return false;
	}
}
bool Errors::GradeNr(int index, int grades)
{
	if (index > grades || index < 0) {
		printf("Nie ma takiej oceny, podaj poprawna wartosc!\n");
		return false;
	}
	else
		return true;
}

Errors::~Errors()
{
	//NIC NIE ROBI!!
}

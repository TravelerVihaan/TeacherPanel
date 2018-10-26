// Dziennik.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"

#include "Lekcja.h"
#include "Uczen.h"
#include "Lista.h"
#include "Errors.h"
#include "Ocena.h"
#include "Przedmiot.h"

#include <string>
#include <cstdlib>
#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <typeinfo>
#include <vector>

using namespace std;

int Lekcja::numerlekcji = 0;
int Uczen::stanklasy = 0;

//DEKLARACJE FUNKCJI PROGRANU GLOWNEGO
void Powitanie();
void Pozegnanie();
void PrintClass(Lista<Uczen>& students);
void AddStudent(Lista<Uczen> & uczniowie);
void DeleteStudent(Lista<Uczen>& uczniowie);
void AddLesson(Lista<Lekcja> & lekcje);
int SearchingType();
//bool SearchCompare(Uczen& sprawdzany, int type, int snr, string nazwisko="brak");
void PrintStudent(Uczen& wypis);
void SearchByNr(Lista<Uczen> & uczniowie);
void SearchByName(Lista<Uczen> & uczniowie);
void CheckPresence(Lista<Uczen> & uczniowie);
void EnterLessonTopic(Lista<Lekcja>& lekcje);
void LessonToFile(Lista<Lekcja> & lekcje);
void EnterLessonFile(Lista<Lekcja>& lekcje);
void PrintAllLessons(Lista<Lekcja>& lekcje);
void PrintSubject(Lista<Lekcja>& lekcje);
void PrintThisLesson(Lista<Lekcja>& lekcje);
void ExportLessons(Lista<Lekcja>& lekcje);
void ExportStudents(Lista<Uczen>& uczniowie);
//void PrintThisLesson(Lekcja& aktualna);
template < class O1 , class O2 >
bool CompareGrades(O1 ocena1, O2 ocena2);
//////// DEKLARACJE FUNKCJI OD MENU
void Menu1();
void Menu2();
void MenuLesson();
void MenuStudent();
int TypeStudentNumber();
int TypeGrade();
Ocena CreatedGrade();
string JakiPrzedmiot();

string aprzedmiot;

//utworzenie globalnego obiektu klasy przeznaczonej do obslugi bledow
Errors Err;

//MAIN ******************************************************************************
int main(void){
	Lista<Lekcja> *lekcje = new Lista<Lekcja>;
	Lista<Uczen> *uczniowie = new Lista<Uczen>;
	char choice;
	do {
		//PRZED PIERWSZA LEKCJA
		if (Lekcja::numerlekcji == 0) {
			Powitanie();
			Menu1();
			cin >> choice;
			if (Err.MainMenu1(choice) == true) {
				switch (choice) {
					//////////// case 1 - add 1st lesson
				case '1': AddLesson(*lekcje);
					break;
					//////////// case2 - print info about durning lesson
				case '2': PrintThisLesson(*lekcje);
					break;
					////////// case 3 - add new student
				case '3': AddStudent(*uczniowie);
					break;
					///////// case 4 - print all studets
				case '4': PrintClass(*uczniowie);
					break;
					//////////////////////// case 5 - type topic from keyboard
				case '5': EnterLessonTopic(*lekcje);
					break;
					//////////////////////// case 0 = exit
				case '0': Pozegnanie();
					break;
					//////////////////////// case default
				default: break;
				}
			}
		}
		else {
			//PIERWSZA I KOLEJNE LEKCJE
			Menu2();
			cin >> choice;
			if (Err.MainMenu2(choice) == true) {
				switch (choice) {
					//////////// case 1 - add next lesson
				case '1': AddLesson(*lekcje);
					break;
					//////////// case2 - print info about durning lesson
				case '2': PrintThisLesson(*lekcje);
					break;
					////////// case 3 - add new student
				case '3': AddStudent(*uczniowie);
					break;
					///////// case 4 - print all studets
				case '4': PrintClass(*uczniowie);
					break;
					//////////////////////// case 5 - type lesson topic from keyboard
				case '5': EnterLessonTopic(*lekcje);
					break;
					//////////////////////// case 6 - enter to students menu
				case '6': {
					char st;
					do{
						MenuStudent();
					cin >> st;
					switch (st) {
						//// check presence of class
					case '1': CheckPresence(*uczniowie); // check all students status
						break;
					case '2': {
						int searcht = SearchingType();
						//// search student by nr/name
						if (searcht == 1)
							SearchByNr(*uczniowie);
						else if (searcht == 2)
							SearchByName(*uczniowie);
						break;
					}
							  //// erase student from class
					case '3': DeleteStudent(*uczniowie);
						break;
						///////////// add grade to student
					case '4': {
						int student_nr = TypeStudentNumber();
						//uczniowie->Llist(student_nr).AddOcena(CreatedGrade());
						//uczniowie->Llist(student_nr).AddO(aprzedmiot);
						uczniowie->AddOc(student_nr, aprzedmiot);
						//oceniany->AddOcena(CreatedGrade());
						//delete oceniany;
						//oceniany = NULL;
						break;
					}
					case '5': {
						int student_nr = TypeStudentNumber();
						uczniowie->Llist(student_nr).PrintOceny();
						printf("Ktora ocene chcesz popawic temu uczniowi?\n");
						int index;
						int grades;
						grades = uczniowie->Llist(student_nr).GetIloscOcen();
						do {
							cin >> index;
							if (Err.GradeNr(index, grades) == true)
								uczniowie->Llist(student_nr).EditOcena(index);
						} while (Err.GradeNr(index, grades) == false);
					}
							  ///////////// export students list to file
					case '6': ExportStudents(*uczniowie);
						break;
					case '0':
						///////////// exit students menu
						break;
					default: break;
					}
					} while (Err.MenuStudent(st) == false);
					break;
				}
						  //////////////////////// case 6 - enter to lessons menu
				case '7': {
					char lkc;
					do {
						MenuLesson();
					cin >> lkc;
					switch (lkc) {
						//// print topic of durning lesson
					case '1': PrintThisLesson(*lekcje);
						break;
						//// enter topic from keyboard
					case '2': EnterLessonTopic(*lekcje);
						break;
						//// enter topic from file
					case '3': EnterLessonFile(*lekcje);
						break;
						//// save topic to file
					case '4': LessonToFile(*lekcje);
						break;
						//// print all lessons on screen
					case '5': PrintAllLessons(*lekcje);
						break;
						//// print one subject
					case '6': PrintSubject(*lekcje);
						break;
						//// export all lessons to file
					case '7': ExportLessons(*lekcje);
						break;
						//// exit lessons menu
					case '0':
						break;
					default: break;
					}
					} while (Err.MenuLesson(lkc) == false);
					break;
				}
				//////////////// EXIT 		 
				case '0':
					Pozegnanie();
					break;
					//////////////////////// case default
				default:
					printf("Twoj wybor nie odpowiada zadnej z dostepnych opcji! Prosze dokonac wlasciwego wyboru.\n");
					break;
				}
			}
		}
	}while(choice != '0');

	delete uczniowie;
	delete lekcje;
	
	system("PAUSE");
    return 0;
};
/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////FUKCJA Z POWITANIEM
void Powitanie()
{
	if (Lekcja::numerlekcji == 0) {
		printf("Witaj w dzienniku elektronicznym nauczycielu!\nNajwyzszy czas rozpoczac pierwsza lekcje \n");
	}
	else {
		printf("\nLekcja nr. %d \n", Lekcja::numerlekcji);
	}
}

void Pozegnanie() {
	printf("\n Do zobaczenia, nauczycielu!\n");
	Sleep(1200);
	//exit(1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNKCJA MENU1
void Menu1()
{
	printf("\n1. Rozpocznij pierwsza lekcje \n");
	printf("2. Wyswietl temat aktualnej lekcji \n");
	printf("3. Dodaj ucznia \n");
	printf("4. Wyswietl informacje o calej klasie\n");
	printf("5. Wpisz temat lekcji z klawiatury \n");
	printf("0 = Zamknij dziennik.\n");
}
////////////////////////////////////////////////////////////////   FUNKCJA MENU2
void Menu2()
{
	printf("\n1. Rozpocznij nowa lekcje \n");
	printf("2. Wyswietl temat aktualnej lekcji \n");
	printf("3. Dodaj ucznia \n");
	printf("4. Wyswietl informacje o calej klasie\n");
	printf("6. Zarzadzanie uczniami \n");
	printf("7. Zarzadzanie lekcjami \n");
	printf("0 - Zamknij dziennik\n");
}
/////////////////////////////// MENU LEKCJI ///////////////////////////////////
void MenuLesson() {
	printf("\n Jaka operacje chcesz wykonac?\n");
	printf("1. Wyswietl temat aktualnej lekcji \n");
	printf("2. Wpisz/Edytuj temat lekcji z klawiatury\n");
	printf("3. Wczytaj temat lekcji z pliku\n");
	printf("4. Zapisz temat lekcji do pliku\n");
	printf("5. Wypisz wszystke lekcje\n");
	printf("6. Wyszukaj lekcje z wybranego przedmiotu \n");
	printf("7. Eksportuj liste wszystkich odbytych zajec do pliku\n");
	printf("0 - Wstecz\n");
}
//////////////////////////////////////////////////////////////////////////
////////////////////////// PODMENU CASE 1 ///////////////////////////////////
string JakiPrzedmiot() {	
	string subject;
	printf("\n Z jakiego przedmiotu chcesz prowadzic lekcje?\n");
	printf("1. Jezyk Polski\n2. Matematyka\n3. Historia\n4. Przyroda\n5. Jezyk Angielski\n6. Fizyka\n");
	char p;
	do {
		cin >> p;
		if (Err.SubjectMenu(p) == true) {
			switch (p) {
			case '1': subject = "polski";
				break;
			case '2': subject = "matematyka";
				break;
			case '3': subject = "historia";
				break;
			case '4': subject = "przyroda";
				break;
			case '5':subject = "angielski";
				break;
			case '6':subject = "fizyka";
				break;
			case '0':break;
			default:
				break;
			}
		}
	}while(Err.SubjectMenu(p) == false);
	return subject;
}
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////CASE 1 - FUNKCJA DODAJACA NOWA LEKCJE
void AddLesson(Lista<Lekcja>& lekcje) {
	string aprzed;
	aprzed = JakiPrzedmiot();
	//cout << aprzed;
	Lekcja::numerlekcji++;
	Lekcja plekcja(aprzed);

	lekcje.Add(plekcja);
	printf("\n Nowa lekcja rozpoczeta!\n");
	aprzedmiot = aprzed;
}
//////////////////////////////////////////CASE 2 MENU GLOWNE
void PrintThisLesson(Lista<Lekcja>& lessons) {
	if (Err.LiczbaLekcji(Lekcja::numerlekcji) == true) {
		//Lekcja *aktualna = NULL;
		//*aktualna = lessons.Llist(Lekcja::numerlekcji - 1);
		int nrlesson;
		nrlesson = Lekcja::numerlekcji - 1;
		lessons.PrintLesson(nrlesson);
		//delete aktualna;
		//aktualna = NULL;
	}
};
////////////////////////////////////////////////
///////////////////////// CASE 3 /////////////////////// FUNKCJA DODAJACA UCZNIA DO LISTY UCZNIOW
void AddStudent(Lista<Uczen>& uczniowie) {
	Uczen::stanklasy++;
	string nazw;
	printf("Podaj nazwisko nowego ucznia:\n");
	cin >> nazw;
	Uczen nowy(nazw);
	uczniowie.Add(nowy);
	/*
	if(Err.NewStudent(*uczniowie)==true)
		printf("\nUczen dodany do klasy.\n");
		*/
	cout << "OK";
	//delete nowy;
	//nowy = NULL;
}
//////////////////////  CASE 4 ////////// FUNKCJA DO WYPISYWANIA DANYCH O UCZNIU   //////////////////// 
void PrintClass(Lista<Uczen>& students) {
	if (Err.LiczbaUczniow(Uczen::stanklasy) == true) {
		cout << "\nLICZBA UCZNIOW : " << students.GetSize() << "\n";
		for (int i = 0;i < students.GetSize();i++) {
			students.Llist(i).Print();
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
///////////////////////////// MENU UCZNIOW ///////////////////////////////////
void MenuStudent() {
		printf("\nJaka operacje chcesz wykonac:\n");
		printf("1. Sprawdz obecnosc klasy \n");
		printf("2. Wyszukaj ucznia \n");
		printf("3. Wyrzuc ucznia ze szkoly\n");
		printf("4. Wystaw uczniowi ocene\n");
		printf("5. Popraw uczniowi ocene\n");
		printf("6. Eksportuj liste uczniow do pliku\n");
		printf("0 - Wstecz\n");
}
//////////////////////////////////////////////////////////////// FUNKCJA DO SPRAWDZANIA OBECNOSCI  
////////////////////////////////////////////////////////////////////////////////
void CheckPresence(Lista<Uczen> & uczniowie) {
	if (Err.CheckPresence(Uczen::stanklasy) == true) {
		int o;
		//Uczen *sprawdzany = NULL;
		for (int i = 0;i < Uczen::stanklasy;i++) {
			//*sprawdzany = uczniowie.Llist(i);
			cout << "\nCzy uczen z numerem " << uczniowie.Llist(i).GetNr() << ": " << uczniowie.Llist(i).GetNazwisko() << " jest obecny? (1 - tak, 0 - nie).\n";
			do {
				cin >> o;
				if (o == 1)
					uczniowie.SetO(i,1);
				else if (o == 0)
					uczniowie.SetO(i, 0);
				else
					printf("Twoj wybor jest nieprawidlowy! Sprobuj ponownie!\n");
			} while (o != 0 && o != 1);
			//delete sprawdzany;
		}
		//delete sprawdzany;
		//sprawdzany = NULL;
	}
}
/////////////////////////////// WYSZUKIWANIE UCZNIA //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// kryterium wyszukiwania
int SearchingType() {
	printf("\n Chcesz wyszukac ucznia po nazwisku, czy numerze? 1 - numer / 2 - nazwisko \n");
	char answer;
	do {
		cin >> answer;
		if (Err.SearchType(answer) == true) {
			if (answer == '1') {
				return 1;
			}
			else if (answer == '2') {
				return 2;
			}
			else {
				printf("\nTwoja odpowiedz jest nieprawidlowa!\n");
				return 0;
			}
		}
	} while(Err.SearchType(answer) == false);
	///// zwracany int: 1 = nazwisko, 2 = numer
}
/////////////// WYSZUKIWANIE UCZNIA PO NUMERZE ////////////////////////////////
void SearchByNr(Lista<Uczen>& uczniowie) {
	//Uczen *stud = NULL;
	int s_nr;
	printf("\nPodaj zatem numer ucznia, o ktorym informacje maja byc wyswietlone\n");
	cin >> s_nr;
	if(Err.SearchingNr(s_nr)==true){
		bool s_flag = false;
		for (int i = 0;i < Uczen::stanklasy;i++) {
			//if (stud) {
			//	delete stud;
			//	stud = NULL;
			//}
			//*stud = uczniowie.EList(i);
			if (uczniowie.EList(i).GetNr() == s_nr) {
				printf("Oto uczen pasujacy do kryterow wyszukiwania:\n");
				PrintStudent(uczniowie.EList(i));
				s_flag = true;
				//delete stud;
				break;
			}
		}
		if (s_flag == false) {
			printf("\n Niestety zaden z uczniow nie pasuje do podanych przez Ciebie kryteriow\n");
		}
	}
	//delete stud;
	//stud = NULL;
}
/////////////// WYSZUKIWANIE UCZNIA PO NAZWISKU ////////////////////////////////
void SearchByName(Lista<Uczen>& uczniowie) {
	//Uczen *stud = NULL;
	string nazwisko;
	printf("\nPodaj zatem nazwisko ucznia, o ktorym informacje maja byc wyswietlone\n");
	cin >> nazwisko;
	bool s_flag = false;
	for (int i = 0;i < Uczen::stanklasy;i++) {
			//if (stud) {
			//	delete stud;
			//	stud = NULL;
			//}
			//*stud = uczniowie.EList(i);
			if (uczniowie.EList(i).GetNazwisko() == nazwisko) {
				printf("Oto uczen pasujacy do kryterow wyszukiwania:\n");
				PrintStudent(uczniowie.EList(i));
				s_flag = true;
				break;
			}
		}
		if (s_flag == false) {
			printf("\n Niestety zaden z uczniow nie pasuje do podanych przez Ciebie kryteriow\n");
		}
	//delete stud;
	//stud = NULL;
}
//////////////////////////////////////////////// FUNKCJA WYPISUJACA INFO O UCZNIU
void PrintStudent(Uczen& wypis) {
	string presence;
	cout << "Nazwisko: " << wypis.GetNazwisko() << "\n";
	cout << "Numer w dzienniku: " << wypis.GetNr() << "\n";
	if (wypis.GetObecnosc() == true)
		presence = "TAK";
	else
		presence = "NIE";

	cout << "Nr: " << wypis.GetNr() << ", Nazwisko: " << wypis.GetNazwisko() << ". Czy jest teraz obecny: " << presence << "\n";	// TODO OCENY
}
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////// USUWANIE UCZNIA Z KLASY //////////////////////////////////////
void DeleteStudent(Lista<Uczen>& uczniowie) {
	PrintClass(uczniowie);
	int nr;
	printf("Podaj numer ucznia, ktorego chcesz wyrzucic ze szkoly:\n");
	cin >> nr;
	if (Err.SearchingNr(nr) == true)
		uczniowie.Delete(nr - 1);
}
////////////////////// WYSTAWIANIE I POPRAWIANIE OCENY    //////////////////////////////////////////
////////////////////////////////////////////// TYPE STUDENT NUMBER  ////////////////////////////
int TypeStudentNumber() {
	int snr;
	do {
		printf("Podaj numer ucznia:\n");
		cin >> snr;
		if (Err.SearchingNr(snr) == true)
			return snr;
		} while (Err.SearchingNr(snr) == false);
}

Ocena CreatedGrade() {
	int value=0;
	do {
		printf("Podaj ocene:\n");
		cin >> value;
		if (Err.GradeValue(value) == true)
			break;
	} while (Err.GradeValue(value) == false);

	int gtype;
	do {
		printf("Za co uczen otrzymal ocene (1 = Sprawdzian 2 = Kartkowka 3 = Aktywnosc \n");
		cin >> gtype;
		if (Err.GradeType(gtype) == true)
			break;
	} while(Err.GradeType(gtype) == false);
	if (gtype == 1) {
		//Ocena* nowa = new Sprawdzian(value, aprzedmiot);
		Ocena nowa(value, aprzedmiot, 1);
		return nowa;
	}
	else if (gtype == 2) {
		 //Ocena* nowa = new Aktywnosc(value, aprzedmiot);
		Ocena nowa(value, aprzedmiot, 2);
		return nowa;
	}
	else if (gtype == 3) {
		//Ocena* nowa = new Aktywnosc(value, aprzedmiot);
		Ocena nowa(value, aprzedmiot, 3);
		return nowa;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// z klawiatury
void EnterLessonTopic(Lista<Lekcja>& lekcje) {
	if (Lekcja::numerlekcji == 0) {
		cout << "ERROR\n";
		return;
	}
	else {
		//printf("Prosze podac temat, ktory ma byc wpisany jako temat biezacej lekcji:\n");
		int nrlkc;
		nrlkc = Lekcja::numerlekcji - 1;
		lekcje.TypeTopic(nrlkc);
	}
}

// z pliku
void EnterLessonFile(Lista<Lekcja>& lekcje) {
	if (Lekcja::numerlekcji == 0) {
		cout << "ERROR\n";
		return;
	}
	fstream file1;
	file1.open("odczyt.txt", ios::in | ios::out);
	if (file1.is_open() == true) {
		string topic;
		getline(file1, topic);
		//Lekcja *temp = NULL;
		//*temp = lekcje.Llist(lekcje.GetSize() - 1);
		lekcje.GTopic(Lekcja::numerlekcji - 1, topic);
		//lekcje.Llist(lekcje.GetSize() - 1).SetTemat(topic);
		//temp->SetTemat(topic);
		//lekcje.Edit(*temp, lekcje.GetSize() - 1);
		//delete temp;
		file1.close();
	}
	else {
		printf("Nie udalo sie otworzyc pliku!\n");
	}
	
}
// do pliku
void LessonToFile(Lista<Lekcja>& lekcje) {
	if (Lekcja::numerlekcji == 0) {
		cout << "ERROR\n";
		return;
	}
	/*
	fstream file1("zapis.txt");
	int lnr = Lekcja::numerlekcji - 1;
	file1.open("zapis.txt", ios::in | ios::out);
	if (file1.is_open() == true) {
		string topic;
		string subject;
		//Lekcja *temp = NULL;
		//*temp = lekcje.Llist(Lekcja::numerlekcji - 1);
		topic = lekcje.Llist(lnr).GetTemat();
		subject = lekcje.Llist(lnr).GetSubject();
		file1 << "Lekcja nr: ";
		file1 << lnr+1;
		file1 << ". Przedmiot: ";
		file1 << subject;
		file1 << ". Temat: ";
		file1 << topic;
		file1 << "\n";
		//delete temp;
		file1.close();
	}
	else {
		printf("Nie udalo sie otworzyc pliku!\n");
	}
	*/
	int lnr = Lekcja::numerlekcji - 1;
	lekcje.ExportL(lnr);
}
//////////// wypisanie wszystkich
void PrintAllLessons(Lista<Lekcja>& lekcje) {
	cout << "LICZBA LEKCJI : " << Lekcja::numerlekcji << "\n";
	//Lekcja *wypis = NULL;
	for (int i = 0;i < Lekcja::numerlekcji;i++) {
		//*wypis = lekcje.Llist(i);
		lekcje.PrintLesson(i);
		//delete wypis;
	}
}
////////// wypisanie z danego przedmiotu
void PrintSubject(Lista<Lekcja>& lekcje) {
	printf("\nZ jakiego przedmiotu chcesz wypisac lekcje?\n");
	string subject;
	printf("1. Jezyk Polski\n2. Matematyka\n3. Historia\n4. Przyroda\n5. Jezyk Angielski\n6. Fizyka\n");
	int p;
	cin >> p;
	switch (p) {
	case 1:
		subject = "polski";
		break;
	case 2:
		subject = "matematyka";
		break;
	case 3:
		subject = "historia";
		break;
	case 4:
		subject = "przyroda";
		break;
	case 5:
		subject = "angielski";
		break;
	case 6:
		subject = "fizyka";
		break;
	default:
		printf("Wybrales niewlasciwa opcje!\n");
		break;
	}
	//Lekcja *wypis = NULL;
	for (int i = 0;i < Lekcja::numerlekcji;i++) {
		//*wypis = lekcje.Llist(i);
		if (lekcje.Llist(i).GetSubject() == subject) {
			cout << "Lekcja nr. " << lekcje.Llist(i).GetNr() << ". Przedmiot: " << lekcje.Llist(i).GetSubject() << ". Temat: " << lekcje.Llist(i).GetTemat() << "\n";
		}
		//delete wypis;
	}
}
///////////////////// FUNKCJE EKSPORTUJACE DO PLIKOW ////////////////////////////////
void ExportLessons(Lista<Lekcja>& lekcje) {
	if (Lekcja::numerlekcji == 0) {
		cout << "ERROR\n";
		return;
	}
	fstream file1("listalekcji.txt");
	file1.open("listalekcji.txt", ios::in | ios::out);
	if (file1.good() == true) {
		string topic;
		string subject;
		//Lekcja *temp = NULL;
		for (int i=0;i < Lekcja::numerlekcji;i++) {
			//*temp = lekcje.Llist(i);
			topic = lekcje.Llist(i).GetTemat();
			subject = lekcje.Llist(i).GetSubject();
			file1 << "Lekcja nr: ";
			file1 << i + 1;
			file1 << ". Przedmiot: ";
			file1 << subject;
			file1 << ". Temat: ";
			file1 << topic;
			file1 << "\n";
			//delete temp;
		}
		file1.close();
	}
	else {
		printf("Nie udalo sie otworzyc pliku!\n");
	}
	
}

void ExportStudents(Lista<Uczen>& uczniowie) {
	if (uczniowie.GetSize() == 0) {
		cout << "ERROR\n";
		return;
	}
	string presence;
	fstream file1("listauczniow.txt");
	file1.open("listauczniow.txt", ios::in | ios::out);
	if (file1.good() == true) {
		//Uczen *temp = NULL;
		for (int i=0;i < Uczen::stanklasy;i++) {
			//*temp = uczniowie.Llist(i);
			if (uczniowie.Llist(i).GetObecnosc() == true)
				presence = "TAK";
			else
				presence = "NIE";
			file1 << "Nr. " << uczniowie.Llist(i).GetNr() << " : Nazwisko: " << uczniowie.Llist(i).GetNazwisko() << ". Czy obecny? :" << presence << "\n";
			file1 << "Jego oceny to: \n";
			uczniowie.Llist(i).PrintOceny();
			//delete temp;
		}
		file1.close();
	}
	else {
		printf("Nie udalo sie otworzyc pliku!\n");
	}
	
}
// porownanie ocen
template < class O1, class O2 >
bool CompareGrades(O1 ocena1, O2 ocena2) {
	if (typeid(ocena1) == typeid(ocena2)) {
		if (ocena1 == ocena2)
			return true;
		else
			return false;
	}
	else {
		Ocena *oc1, *oc2;
		oc1 = dynamic_cast<Ocena*>ocena1;
		oc2 = dynamic_cast<Ocena*>ocena2;
		if (oc1 == oc2)
			return true;
		else
			return false;
	}
}

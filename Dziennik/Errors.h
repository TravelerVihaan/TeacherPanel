#pragma once
#include "stdafx.h"

#include <fstream>
#include <iostream>

using namespace std;

class Errors{	
public:
	Errors();
	bool MainMenu1(char choice);
	bool MainMenu2(char choice);
	bool MenuStudent(char choice);
	bool MenuLesson(char choice);
	bool SubjectMenu(char choice);
	bool LiczbaLekcji(int liczbal);
	bool LiczbaUczniow(int liczbau);
	bool CheckPresence(int liczbau);
	bool SearchType(char choice);
	bool SearchingNr(int snr);
	bool GradeValue(int value);
	bool GradeType(int gtype);
	bool GradeNr(int index, int grades);
	~Errors();
};


#pragma once
#include <iostream>
#include <windows.h>
#include <synchapi.h>
#include <cstdio>
#include <string>

using namespace std;
int cnt = -1;


int main_menu(char* x[]);
void programm_exit();

char m1[] = { "1. Ввести данные студента\n" };
char m2[] = { "2. Изменение данных студента по его id\n" };
char m3[] = { "3. Печать данных о студентах\n" };
char m4[] = { "4. Вывести данные по варианту 83\n" };
char m5[] = { "5. Очистка консоли\n" };
char m6[] = { "6. Выход\n" };
char* menu[] = { m1, m2, m3, m4, m5, m6 };


int main_menu(char* x[]) {
	string q;
	cout << "-------------------------DB STUDENTS-------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << x[i]; 
	}

	while (true)
	{
		try 
		{
			fflush(stdin);
			getline(cin, q);
			if (stoi(q))
			{
				return stoi(q);
			}
		}
		catch (...) { 
			system("cls");
			cout << "-------------------------DB STUDENTS-------------------------" << endl;
			cout << "Введите дейтсвительное значение из меню" << endl;
			cout << "-------------------------------------------------------------" << endl;
			for (int i = 0; i < 6; i++)
			{
				cout << x[i];
			}
		}
		
	}
}



void programm_exit() { cout << endl << "Exit..." << endl;  exit(0); }





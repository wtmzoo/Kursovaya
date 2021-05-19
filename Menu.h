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
int change_studend_data_menu(char* x[]);

char m1[] = { "1. Ввести данные студента\n" };
char m2[] = { "2. Изменение данных студента по его id\n" };
char m3[] = { "3. Печать данных о студентах\n" };
char m4[] = { "4. Печать студента по его id\n" };
char m5[] = { "5. Очистка консоли\n" };
char m6[] = { "6. Выход\n" };
char* menu[] = { m1, m2, m3, m4, m5, m6 };


char mm0[] = { "0. Выход\n" };
char mm1[] = { "1. ФИО\n" };
char mm2[] = { "2. День рождения\n" };
char mm3[] = { "3. Месяц рождения\n" };
char mm4[] = { "4. Год рождения\n" };
char mm5[] = { "5. Год поступления\n" };
char mm6[] = { "6. Факультет / Кафедра\n" };
char mm7[] = { "7. Группа\n" };
char mm8[] = { "8. Номер зачетки\n" };
char mm9[] = { "9. Пол\n" };
char mm10[] = { "10. Предметы и оценки за семестр\n" };
char mm11[] = { "11. Оценки\n" };
char mm12[] = { "12. Выход в верхнее меню\n " };

char* change_menu[] = { mm0, mm1, mm2, mm3, mm4, mm5, mm6, mm7, mm8, mm9, mm10, mm11, mm12 };


int main_menu(char* x[]) {
	string q;
	cout << "-------------------------DB STUDENTS-------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << x[i]; // вывод пунктов меню
	}

	while (true)
	{
		try 
		{
			fflush(stdin);
			getline(cin, q);
			if (stoi(q))
			{
				return stoi(q); // возвращается пункт меню
			}
		}
		catch (...){}
		
	}
}


int change_studend_data_menu(char* x[]) {
	string q;
	cout << endl << "----------------Изменение записей о студентах----------------" << endl;
	for (int i = 0; i < 13; i++)
		cout << x[i]; // вывод пунктов меню
	while (true)
	{
		try
		{
			fflush(stdin);
			getline(cin, q);
			if (stoi(q))
			{
				return stoi(q); // возвращается пункт меню
			}
		}
		catch (...){}

	}
}


void programm_exit() { cout << endl << "Exit..." << endl;  exit(0); }





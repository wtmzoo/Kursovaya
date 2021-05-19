#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Menu.h"


// Условие на то, что студент еще не сдавал сессии


using namespace std;
class File_reader 
{
public:
    string path;
    string str;

    int counter = 0; // Подсчет поличиства символов /
    string index; // Number of student

    string surname;
    string name;
    string patronymic;

    // Birthday Date/Mounth/Year
    string day;
    string mounth;
    string year;

    string entrance_year; // Year of entrance

    string faq_kaf;
    string group;
    string gradebook;
    string gender;

    string object; // University objects (math, bio...)


    string value; // Ratings

    // Переменные для сравнения
    string men;
    string woomen;


    File_reader()
    {
        path = "db_students.txt";
    }
    
    ~File_reader() {};


    void split_data()
    {
        fstream f_out_test(path);

        if (!(f_out_test.is_open())) {
            cout << "Не удалось открыть файл!\n";
            f_out_test.close();
        }
        else
        {

            fstream f_text(path);
            while (getline(f_text, str)) { 
                if (!(size(str) == 1))
                {
                    if (str.find("Сессия")) // Пишет строки с сессией (? не понятно почему)
                    {
                        istringstream ss(str);
                        ss >> index >> surname >> name >> patronymic >> day >> mounth >> year >> entrance_year >> faq_kaf >> group >> gradebook >> gender;
                        ws(ss);
                        cout << index << endl << surname << endl << name << endl << patronymic << endl << day << endl << mounth << endl << year << endl 
                            << entrance_year << endl << faq_kaf << endl << group 
                            << endl << gradebook << endl << gender << endl;
                    }
                }
            }

            f_text.close();

        }
    }


    int idValidInput()
    {
        string id_for_search;
        while (true)
        {
            try
            {
                cout << "Введите id студента: ";
                getline(cin, id_for_search);
                return stoi(id_for_search);
            }
            catch (...)
            {
                cout << endl << "-----------Введите действительное значение (число)-----------" << endl;
            }
        }
    }

    int idIsValid(int id_for_search) 
    {
        fstream f_text(path);
        while (getline(f_text, str)) {
            if (!(size(str) == 1))
            {
                istringstream ss(str);
                ss >> index >> surname >> name >> patronymic >> day >> mounth >> year >> entrance_year >> faq_kaf >> group >> gradebook >> gender;
                ws(ss);

                if (stoi(index) == id_for_search) // Пишет строки с сессией (? не понятно почему)
                {

                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }

        f_text.close();
    }


    void menu()
    {
        system("cls");
        cout << "----------------Изменение записей о студентах----------------" << endl;
        int flag = 0;
        int id_for_search;
        while (true)
        {
            try
            {
                id_for_search = idValidInput(); // Индекс студента для поиска
                flag = idIsValid(id_for_search);
                if (flag == 1)
                {
                    break;
                }
                else
                {
                    cout << endl << "Нет студента с таким ID. Введите заново" << endl;
                }
            }
            catch (...)
            {
                cout << endl << "Нет студента с таким ID. Введите заново" << endl;
            }
        }


        string choice;
        for (;;)
        {
            system("cls");
            int flag_for = 0;
            cout << "----------------Изменение записей о студентах----------------";
            cout << endl << "Введённый ID: " << id_for_search;
            istringstream ss(str);
            ss >> index >> surname >> name >> patronymic >> day >> mounth >> year >> entrance_year >> faq_kaf >> group >> gradebook >> gender;
            ws(ss);
            cout << endl << "Данные о студенте: " << surname << ' ' << name << ' ' << patronymic << ' ' << day << '.' << mounth << '.' << year << ' '
                << entrance_year << ' ' << faq_kaf << ' ' << group
                << ' ' << gradebook << ' ' << gender << endl;
            cout << "-------------------------------------------------------------";
            cout << endl << "1.  Фамилия";
            cout << endl << "2.  Имя";
            cout << endl << "3.  Отчество";
            cout << endl << "4.  День рождения";
            cout << endl << "5.  Месяц рождения";
            cout << endl << "6.  Год рождения";
            cout << endl << "7.  Год поступления";
            cout << endl << "8.  Факультет / Кафедра";
            cout << endl << "9.  Группа";
            cout << endl << "10. Номер зачетки";
            cout << endl << "11. Пол";
            cout << endl << "12. Предметы и оценки за семестр";
            cout << endl << "13. Оценки";
            cout << endl << "14. Выход в верхнее меню" << endl;

            while (true)
            {
                try
                {
                    fflush(stdin);
                    getline(cin, choice);
                    if (stoi(choice))
                    {
                        break;
                    }
                }
                catch (...)
                {
                    cout << endl << "Ошибка, введите действительный пункт меню (число)" << endl;
                }

            }
            switch (stoi(choice))
            {
                case 1: break;
                case 2: break;
                case 3: break;
                case 4: break;
                case 5: break;
                case 6: break;
                case 7: break;
                case 8: break;
                case 9: break;
                case 10: break;
                case 11: break;
                case 12: break;
                case 13: break;
                case 14: system("cls"); flag_for++; break;

                default: break;
            }
            if (flag_for != 0) break;
        }
    }


};

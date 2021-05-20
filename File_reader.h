#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Utilities.h"


// Условие на то, что студент еще не сдавал сессии


using namespace std;
class File_reader 
{
public:
    string path;
    string str;
    string marks;

    int counter = 0; // Подсчет поличиства символов /
    string index; // Number of student

    string name;

    string date;
    string day; 
    string mounth;
    string year;

    string entrance_year; // Year of entrance

    string faq;
    string kaf; 
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
        men = "м";
        woomen = "ж";
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
                    if (str.find("Сессия")) // Пишет строки без сессий (? не понятно почему)
                    {
                        istringstream ss(str);
                        ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
                        ws(ss);
                        cout << index << endl << name << endl << date << endl << entrance_year << endl << faq 
                            << endl << kaf << endl << group 
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
                ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
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
        int id_for_search = 0;
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
            cout << endl << index << ' ' << name << ' ' << date << ' ' << entrance_year << ' ' << faq
                << ' ' << kaf << ' ' << group
                << ' ' << gradebook << ' ' << gender << endl;


            cout << "-------------------------------------------------------------";
            cout << endl << "1.  ФИО";
            cout << endl << "2.  Дата рождения";
            cout << endl << "3.  Год поступления";
            cout << endl << "4.  Факультет";
            cout << endl << "5.  Кафедра";
            cout << endl << "6.  Группа";
            cout << endl << "7.  Номер зачетки";
            cout << endl << "8.  Пол";
            cout << endl << "9.  Предметы и оценки за семестр";
            cout << endl << "10. Оценки";
            cout << endl << "11. Выход в верхнее меню" << endl;

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
                catch (...) {}

            }
            switch (stoi(choice))
            {
                case 1: change_name();  break;
                case 2: change_date();  break;
                case 3: change_entrance_year();  break;
                case 4: change_faq(); break;
                case 5: change_kaf(); break;
                case 6: change_group();  break;
                case 7: change_gradebook();  break;
                case 8: change_gender(); break;
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

    void change_name()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новое ФИО:" << endl;
        fflush(stdin);
        getline(cin, this->name);
        fflush(stdin);
        name = replace_spaces(name);
    }

    void change_date(){
        while (true) {
            try {
                system("cls");
                cout << "----------------Изменение записи о студенте------------------" << endl;
                fflush(stdin);
                cout << "Дата Месяц Год рождения (через пробел)" << endl;
                cin >> this->day >> this->mounth >> this->year;
                fflush(stdin);
                stoi(day); stoi(mounth); stoi(year);
                day = replace_spaces(day);
                mounth = replace_spaces(mounth);
                year = replace_spaces(year);
                date = day + '.' + mounth + '.' + year;

                if ((stoi(day) <= 31) && (stoi(mounth) <= 12) && (stoi(year) > 0) && (stoi(day) > 0) && (stoi(mounth) > 0) && (stoi(year) < 9999) && (stoi(entrance_year) > 0) && (stoi(entrance_year) > stoi(year))) {
                    break;
                }
            }
            catch (...) {}
        }
    }

    void change_entrance_year()
    {    
        while (true) {
            try {
                system("cls");
                cout << "----------------Изменение записи о студенте------------------" << endl;
                fflush(stdin);
                cout << "Год поступления" << endl;
                //cin.get();
                getline(cin, entrance_year);

                if ( stoi(entrance_year) > stoi(year)) {
                    break;
                }
            }
            catch (...) {}
        }

    }

    void change_faq()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новый факультет:" << endl;
        fflush(stdin);
        getline(cin, faq);
        fflush(stdin);
    }

    void change_kaf()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую кафедру:" << endl;
        fflush(stdin);
        getline(cin, kaf);
        fflush(stdin);
    }

    void change_group()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую группу:" << endl;
        fflush(stdin);
        getline(cin, group);
        fflush(stdin);
    }

    void change_gradebook()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую зачетку:" << endl;
        fflush(stdin);
        getline(cin, gradebook);
        fflush(stdin);
    }

    void change_gender()
    {
        while (true) {
            system("cls");
            cout << "----------------Изменение записи о студенте-----------------" << endl;
            fflush(stdin);
            cout << "Пол (м/ж):" << endl;
            cin >> this->gender; 
            if (gender == men || gender == woomen) // Есть возможность добавить перегрузку
            {
                break;
            }
        }
    }
};

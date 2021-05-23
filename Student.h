﻿#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "File.h"
#include "File_reader.h"
#include "Utilities.h"


using namespace std;
class Student : public File {
private:
    int index;

    string name;

    string day;
    string mounth;
    string year;

    string entrance_year;
    string entrance_year_copy;

    string faq;
    string kaf;

    string group;
    string gradebook;
    string gender;
    string gender2;

    string object;


    string value;

    string str;

    string men;
    string woomen;

public:
    Student() {
        this->index = 0;
        this->name = "0";
        this->faq = "0";
        this->kaf = "0";
        this->group = "0";
        this->gradebook = "0";
        this->object = "0";
        this->value = "0";

        this->men = "м";
        this->woomen = "ж";

    }

    ~Student() {}


    //void operator =(int cnt) { index = index + cnt; };


    void set_variables(int cnt) 
    {
        this->index = index + cnt;
        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        cout << "Введите ФИО:" << endl;
        getline(cin, this->name);
        name = replace_spaces(name);

        while (true) {
            try {
                system("cls");
                cout << "----------------Добавление записи о студенте-----------------" << endl;
                fflush(stdin); 
                cout << "Дата Месяц Год рождения (через пробел)" << endl;
                cin >> this->day >> this->mounth >> this->year;
                stoi(day); stoi(mounth); stoi(year);
                day = replace_spaces(day);
                mounth = replace_spaces(mounth);
                year = replace_spaces(year);

                system("cls");
                cout << "----------------Добавление записи о студенте-----------------" << endl;
                fflush(stdin); 
                cout << "Год поступления" << endl;
                cin.get();
                getline(cin, entrance_year);


                if ((stoi(day) <= 31) && (stoi(mounth) <= 12) && (stoi(year) > 0) && (stoi(day) > 0) && (stoi(mounth) > 0) && (stoi(year) < 9999) && (stoi(entrance_year) > 0) && (stoi(entrance_year) > stoi(year))) {
                    break;
                }
            }
            catch (...) {}
        }

        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); 
        cout << "Факультет" << endl;
        getline(cin, faq);
        faq = replace_spaces(faq);

        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin);
        cout << "Кафедра" << endl;
        getline(cin, kaf);
        kaf = replace_spaces(kaf);

        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); 
        cout << "Группа:" << endl;
        getline(cin, group);
        group = replace_spaces(group);


        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); 
        cout << "Номер зачётной книжки:" << endl;
        getline(cin, gradebook);
        gradebook = replace_spaces(gradebook);

        while (true) {
            system("cls");
            cout << "----------------Добавление записи о студенте-----------------" << endl;
            fflush(stdin); 
            cout << "Пол (м/ж):" << endl;
            cin >> this->gender;
            fflush(stdin);
            if (gender == men || gender == woomen)
            {
                break;
            }
        }
    }


    void print_student_data() {
        cout << endl << index << " " << name << " " << day << " " << mounth << " " << year << " " << entrance_year << " " << faq << " " << kaf << " " << group << " " << gradebook 
            << " " << gender << endl;
    }


    string return_values() {
        return to_string(index) + ' ' + name + ' ' + day + '.' + mounth + '.' + year + ' ' + to_string(stoi(entrance_year)) + ' ' +
            faq + ' ' + kaf + ' ' + group + ' ' + gradebook + ' ' + gender;
    }
};

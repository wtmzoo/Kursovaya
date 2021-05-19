#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "File.h"
#include "File_reader.h"


// Добавить проверку на ввод имени с максимум 2 пробелами (Если меньше, то замена данных на NONE)
// Удаление лишних пробелов из некоторых данных 

using namespace std;
class Student : public File {
private:
    int index; // Number of student

    string name; // ФИО

    // Birthday Date/Mounth/Year
    string day;
    string mounth;
    string year;

    string entrance_year; // Year of entrance

    string faq_kaf;
    string group;
    string gradebook;
    string gender;
    string gender2;

    string object; // University objects (math, bio...)


    string value; // Ratings

    string str;

    // Переменные для сравнения
    string men;
    string woomen;

public:
    Student() {
        this->index = 0;
        this->name = "0";
        this->faq_kaf = "0";
        this->group = "0";
        this->gradebook = "0";
        this->object = "0";
        this->value = "0";

        this->men = "м";
        this->woomen = "ж";

    }

    ~Student() {}


    //void operator =(int cnt) { index = index + cnt; };


    void set_variables(int cnt) {
        //setlocale(LC_ALL, "ru_RU.utf-8");
        this->index = index + cnt;
        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        cout << "Введите ФИО:" << endl;
        //cin.get();
        getline(cin, name);

        while (true) {
            try {
                system("cls");
                cout << "----------------Добавление записи о студенте-----------------" << endl;
                fflush(stdin); //Очистить буфер ввода
                cout << "Дата Месяц Год рождения (через пробел)" << endl;
                cin >> this->day >> this->mounth >> this->year;
                stoi(day); stoi(mounth); stoi(year);

                system("cls");
                cout << "----------------Добавление записи о студенте-----------------" << endl;
                fflush(stdin); //Очистить буфер ввода
                cout << "Год поступления" << endl;
                cin >> this->entrance_year;
                stoi(entrance_year);
                if ((stoi(day) <= 31) && (stoi(mounth) <= 12) && (stoi(year) > 0) && (stoi(day) > 0) && (stoi(mounth) > 0) && (stoi(year) < 9999) && (stoi(entrance_year) > 0) && (stoi(entrance_year) > stoi(year))) {
                    break;
                }
                else {
                    cout << endl << "Введены некорректные данные, попробуйте еще раз" << endl;
                }
            }
            catch (...) {
                cout << endl << "Ошибка при вводе, попробуйте еще раз" << endl;
            }
        }

        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); //Очистить буфер ввода
        cout << "Факультет, кафедра" << endl;
        cin.get();
        getline(cin, faq_kaf);

        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); //Очистить буфер ввода
        cout << "Группа" << endl;
        getline(cin, group);


        system("cls");
        cout << "----------------Добавление записи о студенте-----------------" << endl;
        fflush(stdin); //Очистить буфер ввода
        cout << "Номер зачётной книжки" << endl;
        getline(cin, gradebook);

        while (true) {
            system("cls");
            cout << "----------------Добавление записи о студенте-----------------" << endl;
            fflush(stdin); //Очистить буфер ввода
            cout << "Пол (м/ж)" << endl;
            cin >> this->gender;
            if (gender == men || gender == woomen) {
                break;
            }
            else {
                cout << endl << "Введите корректные данные - м/ж";
            }
        }
    }


    void print_student_data() {
        cout << endl << index << " " << name << " " << day << " " << mounth << " " << year << " " << entrance_year << " " << faq_kaf << " " << group << " " << gradebook 
            << " " << gender << endl;
    }


    string return_values() {
        return to_string(index) + ' ' + name + ' ' + day + ' ' + mounth + ' ' + year + ' ' + entrance_year + ' ' +
            faq_kaf + ' ' + group + ' ' + gradebook + ' ' + gender;
    }

    friend class File_reading;
};

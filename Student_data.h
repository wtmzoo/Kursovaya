#pragma once

#include <iostream>
#include "Student.h"
#include "Var83.h"

class Student;
class File_reader;


class StudentData{
private:
    int index;

    string name;

    string day;
    string mounth;
    string year;

    string entrance_year;

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


    StudentData()
    {
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

    ~StudentData() {}

private:

    virtual string return_values() 
    {
        return to_string(index) + ' ' + name;
    }

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
        while (true)
        {
            getline(cin, gradebook);
            gradebook = "20Б02" + replace_spaces(gradebook);
            if (numStudentBookIsValid(gradebook)) break;
        }

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

    int numStudentBookIsValid(string st_book)
    {
        string date;
        string path = "db_students.txt";
        fstream f_out_test(path);

        if (!(f_out_test.is_open()))
        {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            f_out_test.close();
            return 0;
        }
        else
        {
            fstream f_text(path);
            while (getline(f_text, str)) {
                f_out_test.close();
                if (!(size(str) == 1))
                {
                    if (str.find("Сессия"))
                    {
                        istringstream ss(str);
                        ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
                        ws(ss);

                        if (gradebook == st_book)
                        {
                            cout << "Студент с такой зачеткой уже присутствует в БД" << endl;
                            return 0;
                        }
                    }
                }
            }
            f_text.close();
            return 1;
        }
    }

    friend Student;
    friend File_reader;
};

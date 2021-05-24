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

        this->men = "�";
        this->woomen = "�";
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
        cout << "----------------���������� ������ � ��������-----------------" << endl;
        cout << "������� ���:" << endl;
        getline(cin, this->name);
        name = replace_spaces(name);

        while (true) {
            try {
                system("cls");
                cout << "----------------���������� ������ � ��������-----------------" << endl;
                fflush(stdin);
                cout << "���� ����� ��� �������� (����� ������)" << endl;
                cin >> this->day >> this->mounth >> this->year;
                stoi(day); stoi(mounth); stoi(year);
                day = replace_spaces(day);
                mounth = replace_spaces(mounth);
                year = replace_spaces(year);

                system("cls");
                cout << "----------------���������� ������ � ��������-----------------" << endl;
                fflush(stdin);
                cout << "��� �����������" << endl;
                cin.get();
                getline(cin, entrance_year);


                if ((stoi(day) <= 31) && (stoi(mounth) <= 12) && (stoi(year) > 0) && (stoi(day) > 0) && (stoi(mounth) > 0) && (stoi(year) < 9999) && (stoi(entrance_year) > 0) && (stoi(entrance_year) > stoi(year))) {
                    break;
                }
            }
            catch (...) {}
        }

        system("cls");
        cout << "----------------���������� ������ � ��������-----------------" << endl;
        fflush(stdin);
        cout << "���������" << endl;
        getline(cin, faq);
        faq = replace_spaces(faq);

        system("cls");
        cout << "----------------���������� ������ � ��������-----------------" << endl;
        fflush(stdin);
        cout << "�������" << endl;
        getline(cin, kaf);
        kaf = replace_spaces(kaf);

        system("cls");
        cout << "----------------���������� ������ � ��������-----------------" << endl;
        fflush(stdin);
        cout << "������:" << endl;
        getline(cin, group);
        group = replace_spaces(group);


        system("cls");
        cout << "----------------���������� ������ � ��������-----------------" << endl;
        fflush(stdin);
        cout << "����� �������� ������:" << endl;
        getline(cin, gradebook);
        gradebook = replace_spaces(gradebook);

        while (true) {
            system("cls");
            cout << "----------------���������� ������ � ��������-----------------" << endl;
            fflush(stdin);
            cout << "��� (�/�):" << endl;
            cin >> this->gender;
            fflush(stdin);
            if (gender == men || gender == woomen)
            {
                break;
            }
        }
    }

    friend Student;
    friend File_reader;
};

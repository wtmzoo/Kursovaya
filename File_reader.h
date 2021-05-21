#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Utilities.h"


using namespace std;
class File_reader 
{
public:
    int counter_sessions = 0;
    
    string path;
    string str;
    string str_marks;

    string index;

    string name;

    string date;
    string day; 
    string mounth;
    string year;

    string entrance_year;

    string faq;
    string kaf; 
    string group;
    string gradebook;
    string gender;

    string session;
    string object;
    string value;

    char sessions[90][200];
    char objects[90][200];
    char values[90][200];

    string men;
    string woomen;


    File_reader()
    {
        for (int i = 0; i < 90; i++)
        {
            for (int j = 0; j < 200; j++)
            {
                sessions[i][j] = 0;
                objects[i][j] = 0;
                values[i][j] = 0;
            }
        }

        path = "db_students.txt";
        men = "м";
        woomen = "ж";
    }
    
    ~File_reader() {};



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

    int idIsValid(int id_for_search, int mode)
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
                    if (str.find("Сессия"))
                    {
                        istringstream ss(str);
                        ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
                        ws(ss);

                        if (stoi(index) == id_for_search)
                        {
                            if (mode == 1)
                            {
                                int i = 0;
                                while (getline(f_text, str_marks))
                                {
                                    if (size(str_marks) == 1)
                                    {
                                        break;
                                    }
                                    istringstream ss2(str_marks);
                                    ss2 >> session >> object >> value;
                                    ws(ss2);
                                    cout << endl << session << " " << object << " " << value;
                                    strcpy_s(sessions[i], session.c_str());
                                    strcpy_s(objects[i], object.c_str());
                                    strcpy_s(values[i], value.c_str());
                                    i++;
                                    counter_sessions++;
                                }
                            }
                            return 1;
                        }
                    }
                }
            }
            f_text.close();

        }
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
                id_for_search = idValidInput();
                flag = idIsValid(id_for_search, 0);
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
        flag = 0;
        for (;;)
        {
            system("cls");
            int flag_for = 0;
            cout << "----------------Изменение записей о студентах----------------";
            cout << endl << "Введённый ID: " << id_for_search;
            cout << endl << "-------------------------------------------------------------";
            cout << endl << index << ' ' << name << ' ' << date << ' ' << entrance_year << ' ' << faq
                << ' ' << kaf << ' ' << group
                << ' ' << gradebook << ' ' << gender;
            if (flag == 0)
            {
                idIsValid(id_for_search, 1);
                flag++;
            }
            else
            {
                cout << endl;
                for (int i = 0; i < counter_sessions; i++)
                {
                    cout << sessions[i] << " " << objects[i] << " " << values[i] << endl;
                }
            }
            


            cout << endl << "-------------------------------------------------------------";
            cout << endl << "1.  Изменить: ФИО";
            cout << endl << "2.  Изменить: Дата рождения";
            cout << endl << "3.  Изменить: Год поступления";
            cout << endl << "4.  Изменить: Факультет";
            cout << endl << "5.  Изменить: Кафедра";
            cout << endl << "6.  Изменить: Группа";
            cout << endl << "7.  Изменить: Номер зачетки";
            cout << endl << "8.  Изменить: Пол";
            cout << endl << "9.  Изменить: Предметы и оценки за семестр";
            cout << endl << "10. Выход:    Выход в главное меню" << endl;

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
                case 9: if (counter_sessions != 0) { change_object_marks(id_for_search); } break;
                case 10: system("cls"); flag_for++; break;

                default: break;
            }
            if (flag_for != 0) break;
        }
    }

    void change_object_marks(int id_for_search)
    {
        string num_session;
        string new_num_sess;
        string new_object;
        string new_value;

        while (true)
        {
            try
            {
                system("cls");
                cout << "----------------Изменение записи о студенте-----------------" << endl;
                cout << "Введите номер строки (в данных о сессиях студента), которую хотите изменить: ";
                getline(cin, num_session);
                if (stoi(num_session) > 0 && stoi(num_session) <= counter_sessions)
                {
                    break;
                }
            }
            catch (...) {}
        }
        string name_session = "Сессия#" + num_session;

        while (true)
        {
            int flag_while = 0;
            try
            {
                system("cls");
                cout << "----------------Изменение записи о студенте-----------------" << endl;
                cout << sessions[stoi(num_session)-1] << " " << objects[stoi(num_session)-1] << " " << values[stoi(num_session)-1];
                cout << endl << "-------------------------------------------------------------";
                cout << endl << "1.  Изменить номер сесии";
                cout << endl << "2.  Изменить название предмета";
                cout << endl << "3.  Изменить оценку";
                cout << endl << "4.  Выйти на уровень вверх" << endl;

                string choice;
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
                    case 1: 
                    {
                        while (true)
                        {
                            system("cls");
                            cout << "----------------Изменение записи о студенте-----------------" << endl;
                            cout << "Новый номер сесии: " << endl;
                            try 
                            {
                                fflush(stdin);
                                getline(cin, new_num_sess);
                                if (stoi(new_num_sess))
                                {
                                    strcpy_s(sessions[stoi(num_session)-1], ("Сессия#" + new_num_sess + ":").c_str());
                                    break;
                                }
                            }
                            catch (...) { cout << "что-то пошло не по плану)))";  }
                        }
                        break;
                    }
                    case 2:
                    {
                        while (true)
                        {
                            system("cls");
                            cout << "----------------Изменение записи о студенте-----------------" << endl;
                            cout << "Новое название предмета: " << endl;
                            try
                            {
                                fflush(stdin);
                                getline(cin, new_object);
                                strcpy_s(objects[stoi(num_session)-1], new_object.c_str());
                                break;
                            }
                            catch (...) { cout << "что-то пошло не по плану)))"; }
                        }
                        break;
                    }
                    case 3: 
                    {
                        while (true)
                        {
                            system("cls");
                            cout << "----------------Изменение записи о студенте-----------------" << endl;
                            cout << "Новая оценка: " << endl;
                            try
                            {
                                fflush(stdin);
                                getline(cin, new_value);
                                strcpy_s(values[stoi(num_session) - 1], new_value.c_str());
                                break;
                            }
                            catch (...) { cout << "что-то пошло не по плану)))"; }
                        }
                        break;
                    }
                    case 4: flag_while++; break;
                }
                if (flag_while != 0) break;
            }
            catch (...) {}
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

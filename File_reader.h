#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Utilities.h"
#include "Student_data.h"


using namespace std;
class File_reader : public StudentData
{
public:
    int counter_sessions = 0;
    
    int num_lines_start = 0;
    int num_lines_end = 0;

    string main_string;
    string main_data;

    string mod_file;
    string path;
    string str;
    string str_marks;

    string index;

    string date;

    string session;
    string object;
    string value;

    char sessions[90][200];
    char objects[90][200];
    char values[90][200];

    char sessions_cop[90][200];
    char objects_cop[90][200];
    char values_cop[90][200];

    File_reader()
    {
        for (int i = 0; i < 90; i++)
        {
            for (int j = 0; j < 200; j++)
            {
                sessions[i][j] = 0;
                sessions_cop[i][j] = 0;
                objects[i][j] = 0;
                objects_cop[i][j] = 0;
                values[i][j] = 0;
                values_cop[i][j] = 0;
            }
        }

        mod_file = "db_modified.txt";
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
            catch (...){}
        }
    }

    int idIsValid(int id_for_search, int mode)
    {
        fstream f_out_test(path);

        if (!(f_out_test.is_open())) {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            f_out_test.close();
            return 0;
        }
        else
        {
            int lines = 0;
            int start = 0;
            int end = 0;
            fstream f_text(path);
            while (getline(f_text, str)) {
                f_out_test.close();
                start++;

                if (!(size(str) == 1))
                {
                    if (str.find("Сессия"))
                    {
                        istringstream ss(str);
                        ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
                        ws(ss);

                        if (stoi(index) == id_for_search)
                        {
                            main_string = str;
                            if (num_lines_start == 0) num_lines_start = start;
                            int i = 0;
                            counter_sessions = 0;
                            while (getline(f_text, str_marks))
                            {
                                if (size(str_marks) == 1)
                                {
                                    break;
                                }
                                istringstream ss2(str_marks);
                                ss2 >> session >> object >> value;
                                ws(ss2);
                                if (mode == 1)
                                {
                                    cout << endl << session << " " << object << " " << value;
                                }
                                strcpy_s(sessions[i], session.c_str());
                                strcpy_s(objects[i], object.c_str());
                                strcpy_s(values[i], value.c_str());
                                i++;
                                counter_sessions++;
                                }
                            
                            return 1;
                        }
                    }
                }
            }
            f_text.close();
            return 1;
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

        flag = 0;
        for (;;)
        {
            system("cls");
            int flag_for = 0;
            cout << "----------------Изменение записей о студентах----------------";
            cout << endl << "Введённый ID: " << id_for_search << endl;
            cout << "-----------------------Данные о студенте---------------------";
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
                    if (i == counter_sessions-1)
                    {
                        cout << sessions[i] << " " << objects[i] << " " << values[i];
                    }
                    else
                    {
                        cout << sessions[i] << " " << objects[i] << " " << values[i] << endl;
                    }
                }
            }
            

            cout << endl << "----------------Изменение записей о студентах----------------";
            cout << endl << "1.  ФИО";
            cout << endl << "2.  Дата рождения";
            cout << endl << "3.  Год поступления";
            cout << endl << "4.  Факультет";
            cout << endl << "5.  Кафедра";
            cout << endl << "6.  Группа";
            cout << endl << "7.  Номер зачетки";
            cout << endl << "8.  Пол";
            cout << endl << "9.  Предметы и оценки за семестр";
            cout << endl << "10. Запись данных в файл";
            cout << endl << "11. Добавить запись о сессии";
            cout << endl << "12. Удалить данные о студенте";
            cout << endl << "13. Удалить данные об одной из сессий";
            cout << endl << "14. Выход в главное меню" << endl;

            switch (ValidMenuInput())
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
                case 10: replace_lines(0); break;
                case 11: add_session(); break;
                case 12: del_student(id_for_search); replace_lines(1);  replace_end(); flag_for++ ; break;
                case 13: del_session(); replace_lines(1); replace_end();  flag_for++;  break;
                case 14: system("cls"); flag_for++; break;

                default: break;
            }
            if (flag_for != 0) break;
        }
    }


    void del_student(int id_for_search)
    {
        string all_text;
        string modified_student;

        try
        {
            remove("db_modified.txt");
        }
        catch (...) {}

        ofstream create(mod_file);
        create.close();

        fstream overwriting_file(path);
        fstream modified_file(mod_file);

        if (!(overwriting_file.is_open()) || !(modified_file.is_open())) {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            overwriting_file.close();
            modified_file.close();
        }
        else
        {
            int i = 0;
            int flag = 0;
            while (getline(overwriting_file, str))
            {
                i++;
                if (str.length() != 1)
                {
                    if (i < num_lines_start || i > (num_lines_start + counter_sessions))
                    {
                        modified_file << str << endl;
                    }
                }
                else
                {
                    if (stoi(str) != id_for_search)
                    {
                        modified_file << str << endl;
                    }
                }
            }
            modified_file.close();

            overwriting_file.close();

            try
            {
                remove("db_students.txt");
            }
            catch (...) {}

            ofstream create(path);
            create.close();

            fstream overwriting_file(path);
            fstream modified_file(mod_file);

            while (getline(modified_file, str))
            {
                overwriting_file << str << endl;
            }
            modified_file.close();

            try
            {
                remove("db_modified.txt");
            }
            catch (...) {}
        }
    }


    void del_session2()
    {
        while (true)
        {
            try
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

                break;
            }
            catch (...) {}
        }
    }

    int del_session()
    {
        string IsValid;
        string q;
        while (true)
        {
            try
            {
                system("cls");
                cout << "Введите номер строки для удаления: " << endl;
                fflush(stdin);
                getline(cin, q);
                if (stoi(q) && stoi(q) <= counter_sessions && stoi(q) > 0)
                {
                    for (int j = 0; j < 200; j++)
                    {
                        sessions[stoi(q) - 1][j] = 0;
                        objects[stoi(q) - 1][j] = 0;
                        values[stoi(q) - 1][j] = 0;
                    }
                    counter_sessions -= 1;
                    break;
                }
            }
            catch (...) {}
        }
        return stoi(q);
    }

    void add_session()
    {
        string q;
        while (true)
        {
            try
            {
                system("cls");
                cout << "Введите номер сессии: " << endl;
                fflush(stdin);
                getline(cin, q);
                if (stoi(q) && stoi(q) < 10 && stoi(q) > 0)
                {
                    q = "Сессия#" + q + ":";
                    strcpy_s(sessions[counter_sessions], q.c_str());
                    break;
                }
            }
            catch (...) {}
        }
        while (true)
        {
            try
            {
                system("cls");
                cout << "Введите предмет: " << endl;
                fflush(stdin);
                getline(cin, q);
                strcpy_s(objects[counter_sessions], q.c_str());
                break;
            }
            catch (...) {}
        }
        while (true)
        {
            try
            {
                system("cls");
                cout << "Введите оценку за предмет: " << endl;
                fflush(stdin);
                getline(cin, q);
                if (stoi(q) && stoi(q) > 0 && stoi(q) < 6)
                {
                    strcpy_s(values[counter_sessions], q.c_str());
                    break;
                }
            }
            catch (...) {}
        }
        counter_sessions++;
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

                switch (ValidMenuInput())
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
                                if (stoi(new_num_sess) && stoi(new_num_sess) > 0 && stoi(new_num_sess) <= 9)
                                {
                                    strcpy_s(sessions[stoi(num_session)-1], ("Сессия#" + new_num_sess + ":").c_str());
                                    break;
                                }
                            }
                            catch (...) {}
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
                                strcpy_s(objects[stoi(num_session) - 1], new_object.c_str());
                                break;
                            }
                            catch (...) {}
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
                                if (stoi(new_value) > 0 && stoi(new_value) <= 5)
                                {
                                    strcpy_s(values[stoi(num_session) - 1], new_value.c_str());
                                    break;
                                }
                            }
                            catch (...) {}
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
        faq= replace_spaces(faq);
        fflush(stdin);
    }

    void change_kaf()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую кафедру:" << endl;
        fflush(stdin);
        getline(cin, kaf);
        kaf = replace_spaces(kaf);
        fflush(stdin);
    }

    void change_group()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую группу:" << endl;
        fflush(stdin);
        getline(cin, group);
        group = replace_spaces(group);
        fflush(stdin);
    }

    void change_gradebook()
    {
        system("cls");
        cout << "----------------Изменение записи о студенте-----------------" << endl;
        cout << "Введите новую зачетку:" << endl;
        fflush(stdin);
        getline(cin, gradebook);
        gradebook = replace_spaces(gradebook);
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
            if (gender == men || gender == woomen)
            {
                break;
            }
        }
    }
    

    void replace_lines(int mod)
    {
        string all_text;
        string modified_student;
        modified_student = index + " " + name + " " + date + " " + entrance_year + " " + faq + " " + kaf + " " + group + " " + gradebook + " " + gender;
         
        try
        {
            remove("db_modified.txt");
        }
        catch (...) {}

        ofstream create(mod_file);
        create.close();

        fstream overwriting_file(path);
        fstream modified_file(mod_file);

        if (!(overwriting_file.is_open()) || !(modified_file.is_open())) {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            overwriting_file.close();
            modified_file.close();
        }
        else
        {
            string IsValid;
            int i = 0;
            int flag = 0;
            while (getline(overwriting_file, str))
            {
                i++;
                if (str.length() != 1)
                {
                    if (mod == 0)
                    {
                        if (i >= num_lines_start && i <= (num_lines_start + counter_sessions) && flag == 0)
                        {
                            modified_file << modified_student << endl;
                            for (int j = 0; j < (counter_sessions); j++)
                            {
                                IsValid += sessions[j];
                                if (sessions[j] != 0 && sessions[j] != "0" && IsValid.length() != 0)
                                {
                                    modified_file << sessions[j] << " " << objects[j] << " " << values[j] << endl;
                                }
                            }
                            flag = 1;
                        }
                        else
                        {
                            if (i > (num_lines_start + counter_sessions) || i < num_lines_start)
                            {
                                modified_file << str << endl;
                            }
                        }
                    }
                    else
                    {
                        int line_del = 0;
                        if (line_del != 0)
                        {
                            line_del = del_session();
                        }
                        if (i >= num_lines_start && i <= (num_lines_start + counter_sessions) && flag == 0)
                        {
                            modified_file << str << endl;
                            for (int j = 0; j < (counter_sessions); j++)
                            {
                                IsValid += sessions[j];
                                if (sessions[j] != 0 && sessions[j] != "0" && IsValid.length() != 0)
                                {
                                    modified_file << sessions[j] << " " << objects[j] << " " << values[j] << endl;
                                }
                            }
                            flag = 1;
                        }
                        else
                        {
                            if (i > (num_lines_start + counter_sessions) || i < num_lines_start)
                            {
                                modified_file << str << endl;
                            }
                        }
                    }
                    
                }
                else
                {
                    modified_file << str << endl; 
                }
            }
            modified_file.close();

            overwriting_file.close();

            try
            {
                remove("db_students.txt");
            }
            catch (...) {}

            ofstream create(path);
            create.close();

            fstream overwriting_file(path);
            fstream modified_file(mod_file);

            while (getline(modified_file, str))
            {
                overwriting_file << str << endl;
            }
            modified_file.close();
            overwriting_file.close();

            try
            {
                remove("db_modified.txt");
            }
            catch (...) {}

        }
        replace_end();
    }
    
    void replace_end()
    {
        string all_text;
        string str_end;

        try
        {
            remove("db_modified.txt");
        }
        catch (...) {}

        fstream overwriting_file(path);
        fstream modified_file(mod_file);

        if (!(overwriting_file.is_open())) {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            overwriting_file.close();
            modified_file.close();
        }
        else
        {
            while (getline(overwriting_file, str_end))
            {
                if (str_end.length() != 0)
                {
                    modified_file << str << endl;
                }
            }


            overwriting_file.close();
            modified_file.close();
        }
    }
};


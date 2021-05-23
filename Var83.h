#pragma once
#include <iostream>
#include <string>
#include "Utilities.h"
#include "File_reader.h"
#include "Student_data.h"

using namespace std;


class Var83
{
public: 

    Var83() {};

    ~Var83() {};


	void menu()
	{
        system("cls");
        for (;;)
        {
            int break_flag = 0;
            cout << "--------------------Задание по варианту 83-------------------";
            cout << endl << "1.  Не ни одной оценки 3";
            cout << endl << "2.  Не ни одной оценки 3 и 4";
            cout << endl << "3.  Не ни одной оценки 5";
            cout << endl << "4.  Указать интервал года рождения";
            cout << endl << "5.  Выход в главное меню" << endl;

            switch (ValidMenuInput())
            {
                case 1: return_students_for_var(1); break;
                case 2: return_students_for_var(2); break;
                case 3: return_students_for_var(3); break;
                case 4: break;
                case 5: break_flag = 1; break;
            }
            if (break_flag == 1) system("cls");  break;
        }
	}

    int return_students_for_var(int mode)
    {
        string path = "db_students.txt";
        string str;
        string str_marks;
        string session;
        string object;
        string value;

        string index;
        string name;
        string date;
        string entrance_year;
        string faq;
        string kaf;
        string group;
        string gradebook;
        string gender;
        fstream f_out_test(path);

        if (!(f_out_test.is_open())) {
            cout << "Не удалось открыть файл!\n";
            Sleep(4000);
            f_out_test.close();
            return 0;
        }
        else
        {
            int values[11];
            f_out_test.close();
            fstream f_text(path);
            while (getline(f_text, str))
            {
                for (int i = 0; i < 11; i++)
                {
                    values[i] = 0;
                }

                if (!(size(str) == 1))
                {
                    if (str.find("Сессия"))
                    {
                        istringstream ss(str);
                        ss >> index >> name >> date >> entrance_year >> faq >> kaf >> group >> gradebook >> gender;
                        ws(ss);

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

                            values[i] = stoi(value);
                            i++;
                        }

                        if (mode == 1)
                        {
                            int flag1 = 0;
                            for (int m = 0; m < 11; m++)
                            {
                                if (values[m] == 3)
                                {
                                    flag1 = 1;
                                };
                            }
                            if (flag1 == 0)
                            {
                                cout << index << ' ' << name << ' ' << date << ' ' << entrance_year << ' ' << faq
                                    << ' ' << kaf << ' ' << group
                                    << ' ' << gradebook << ' ' << gender << endl;
                            }
                        }
                        if (mode == 2)
                        {
                            int flag2 = 0;
                            for (int m = 0; m < 11; m++)
                            {
                                if (values[m] == 3 || values[m] == 4)
                                {
                                    flag2 = 1;
                                }
                            }
                            if (flag2 == 0)
                            {
                                cout << index << ' ' << name << ' ' << date << ' ' << entrance_year << ' ' << faq
                                    << ' ' << kaf << ' ' << group
                                    << ' ' << gradebook << ' ' << gender << endl;
                            }
                        }
                        if (mode == 3)
                        {
                            int flag3 = 0;
                            for (int m = 0; m < 11; m++)
                            {
                                if (values[m] == 5)
                                {
                                    flag3 = 1;
                                }
                            }
                            if (flag3 == 0)
                            {
                                cout << index << ' ' << name << ' ' << date << ' ' << entrance_year << ' ' << faq
                                    << ' ' << kaf << ' ' << group
                                    << ' ' << gradebook << ' ' << gender << endl;
                            }
                        }

                    }
                }
            }
            f_text.close();
        }
    }

};
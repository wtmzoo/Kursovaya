#pragma once
#include <string>
#include <algorithm>
#include <fstream>

string replace_spaces(string data);
string replace_dash(string data);
int numStudentBookIsValid(string st_book);
int ValidMenuInput();


using namespace std;

string replace_spaces(string data)
{
    replace(begin(data), end(data), ' ', '-');
    return data;
}

string replace_dash(string data)
{
    replace(begin(data), end(data), '-', ' ');
    return data;
}

int ValidMenuInput()
{
	string q;
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
		catch (...) {}
	}
}

int numStudentBookIsValid(string st_book)
{
    string str;
    string index;
    string name;
    string date;
    string entrance_year;
    string faq;
    string kaf;
    string group;
    string gradebook;
    string gender;
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

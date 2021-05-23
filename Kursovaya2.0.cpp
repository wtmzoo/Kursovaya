#include <iostream>
#include <string>
#include "Student.h"
#include "Menu.h"
#include "File.h"
#include "File_reader.h"
#include <string>


using namespace std; 

int main()
{
    int cnt = 0;
    int id_for_search;
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локализации
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    string str;

    for (;;) {
        Student* Current = new Student;
        File* Cur = new File;
        File_reader* work = new File_reader;


        switch (main_menu(menu))
        {
        case 1: 
        {
            cnt = Cur->return_value_index();
            Current->set_variables(cnt);
            Current->print_student_data();
            str = Current->return_values();
            Cur->write_file(str);
            Cur->write_objects_values_to_file();
            delete Current; // **
            delete Cur;     // **
            delete work;    // **
            break;
        }
        case 2: 
        {
            work->menu();
            delete work;
            break;
        }
        case 3: Cur->read_file(); delete Cur;  break;
        case 5: system("cls"); break;
        case 6: programm_exit();


        default: system("cls"); break;
        }
    }
};





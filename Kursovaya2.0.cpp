#include <iostream>
#include <string>
#include "Student.h"
#include "Menu.h"
#include "File.h"
#include "File_reader.h"
#include "Var83.h"


using namespace std; 

int main()
{
    int cnt = 0;
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локализации
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    string str;

    for (;;) {
        switch (main_menu(menu))
        {
        case 1: 
        {
            Student* Current = new Student;
            File* Cur = new File;
            File_reader* work = new File_reader;
            cnt = Cur->last_line() + 1;
            Current->make(cnt);
            Current->print_student_data();
            str = Current->return_values();
            Cur->write_file(str);
            Cur->write_objects_values_to_file();
            delete Current; 
            delete Cur;     
            delete work;    
            break;
        }
        case 2: 
        {
            File_reader* work = new File_reader;
            work->menu();    
            delete work;   
            break;
        }
        case 3: 
        {
            system("cls");
            File* Cur = new File;
            Cur->read_file(); 
            delete Cur;        
            break;
        }
        case 4: 
        {   
            Var83* worker = new Var83;
            worker->menu(); 
            break; 
        }
        case 5: 
        {
            system("cls");
            File* Cur = new File; 
            Cur->pull_data(); 
            delete Cur;
            cout << "Информация успешно импортирована" << endl;
            break;
        }
        case 6: system("cls"); break;
        case 7: programm_exit();

        default: system("cls"); break;
        }
    }
};





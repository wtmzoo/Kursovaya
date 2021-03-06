#include <iostream>
#include <string>
#include "Student.h"
#include "Menu.h"
#include "File.h"
#include "File_reader.h"
#include "Var83.h"
#include "Crypt.h"

using namespace std; 

int main()
{
    int cnt = 0;
    setlocale(LC_CTYPE, "rus"); 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str;

    for (;;) {
        switch (main_menu(menu))
        {
        case 1: 
        {
            Student* Current = new Student;
            File* Cur = new File;

            try
            {
                cnt = Cur->last_line() + 1;
            }
            catch (...)
            {
                cnt = 1;
            }

            Current->make(cnt);
            Current->print_student_data();
            str = Current->return_values();
            Cur->write_file(str);
            Cur->write_objects_values_to_file();

            delete Current; 
            delete Cur;       
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
        case 7: start_crypt(); system("cls"); break;
        case 8: programm_exit();

        default: system("cls"); break;
        }
    }
};





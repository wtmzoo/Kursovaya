#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class File {
public:
    int last_index;
    int line_index;
    string path;

    File()
    {
        path = "db_students.txt";
    }

    /*
    void bufferCleaner()
    {
        cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        cin.ignore('\n');
        //while (getchar() != '\n');
    }
    */

    void write_file(string str) {
        fstream f_out_test(path);

        if (!(f_out_test.is_open())) {
            cout << "Ошибка при открытии файла(1)!\n";
            f_out_test.close();
        }
        else
        {
            if (!(f_out_test.peek() == EOF)) {
                f_out_test.close();
                fstream f_out(path, ofstream::app);
                f_out.seekg(0);
                f_out << endl << str;
                f_out.close();
            }
            else {
                f_out_test.close();
                fstream f_out(path, ofstream::app);
                f_out << str;
                f_out.close();
            }
        }
    }

    void write_objects_values_to_file() {
        string str_values = "0";
        string kolich_sessiy = "0";
        string kolich_predm = "0";
        string object = "0";
        string val = "0";
        while (true) {
            system("cls");
            cout << "----------------Добавление записи о студенте-----------------" << endl;
            cout << "Введите количество сессий: ";
            cin >> kolich_sessiy;
            try {
                if (stoi(kolich_sessiy) <= 9 || stoi(kolich_sessiy) > 0) 
                {
                    break;
                }
            }
            catch (...) {
                cout << "Введены неправильные данные, попробуйте еще раз!";
            }
        }
        last_index = return_value_index();
        for (int i = 0; i < stoi(kolich_sessiy); i++) {
            while (true) {
                system("cls");
                cout << "----------------Добавление записи о студенте-----------------" << endl;
                cout << "Количество предметов за " <<  (i+1) << " сессию: ";
                cin >> kolich_predm;
                try {
                    if (stoi(kolich_predm) <= 10 || stoi(kolich_predm) > 0)
                    {
                        break;
                    }
                }
                catch (...) {
                    cout << "Введены неправильные данные, попробуйте еще раз!";
                }
            }
            for (int j = 0; j < stoi(kolich_predm); j++) {
                cin.clear();
                cin.ignore();
                object = obj_return();
                val = val_return();
                str_values = "Сессия#" + to_string(i + 1) + ": " + object + " " + val;
                write_file(str_values);
            }
            system("cls");
        }

        write_file(to_string(last_index - 1));

    }

    string obj_return() {
        string object;

        while (true) {
            cout << endl << "Введите предмет: ";
            try
            {
                getline(cin, object);
                return object;
            }
            catch (...)
            {
                cout << endl << "Ошибка при вводе предмета! Попробуйте еще раз" << endl;
            }
        }

        return object;
    }

    string val_return() {
        string value;

        while (true) {
            cout << "Введите оценку по предмету: ";
            try 
            {
                getline(cin, value);

                if (stoi(value) > 0 && stoi(value) <= 5) 
                {
                    return value;
                }
                else 
                {
                    cout << endl << "Введена неправильная оценка, попробуйте еще раз" << endl;
                }
            }
            catch (...) 
            {
                cout << endl << "Ошибка при вводе оценки, попробуйте еще раз" << endl;
            }
        }
    }

    void read_file() {
        string str;
        ifstream f_in;
        f_in.open(path);
        cout << endl << "READED FILE: " << endl << endl;

        if (!(f_in.is_open())) 
        {
            cout << "Ошибка при открытии файла!\n";
        }
        else 
        {
            while (getline(f_in, str)) {
                if (!(size(str) == 1))
                {
                    cout << str << endl;
                }
            }
            cout << endl;
        }
        f_in.close();
    }

    int return_value_index() {
        ifstream f_in;
        f_in.open(path);
        if (f_in.peek() == EOF) {
            f_in.close();
            return 1;
        }

        if (f_in.is_open()) {
            f_in.seekg(-1, ios_base::end);                // go to one spot before the EOF

            bool keepLooping = true;
            while (keepLooping) {
                char ch;
                f_in.get(ch);                            // Get current byte data
                if ((int)f_in.tellg() <= 1) {             // If the data was at or before the 0th byte
                    f_in.seekg(0);                       // The first line is the last line
                    keepLooping = false;                // So stop there
                }
                else if (ch == '\n') {                   // If the data was a newline
                    keepLooping = false;                // Stop at the current position.
                }
                else {                                  // If the data was neither a newline nor at the 0 byte
                    f_in.seekg(-2, ios_base::cur);        // Move to the front of that data, then to the front of the data before it
                }
            }

            char return_index;
            f_in.get(return_index);
            int i = (int)return_index - 48;
            f_in.close();
            try {
                return i + 1;
            }
            catch (...) {
                cout << "Ошибка в выводе последнего индекса из файла";
            }
        }
        return 0;
    };
};

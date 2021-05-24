#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>


using namespace std;

class File {
public:
    int last_index;
    int line_index;
    string path;
    string pull;

    File()
    {
        path = "db_students.txt";
        pull = "pull_data.txt";
    }

    void pull_data()
    {
        string str_copy;
        try
        {
            remove("db_students.txt");
        }
        catch (...) {}

        ofstream create(path);
        create.close();

        fstream main(path);
        fstream data(pull);

        while (getline(data, str_copy))
        {
            main << str_copy << endl;
        }
        main.close();
        data.close();
    }

    
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
        last_index = last_line();
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
        write_file(to_string(last_index));

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

    int last_line()
    {
        std::ifstream inp(path.c_str());
        if (!inp.is_open())
            throw std::exception();
        std::string str = "";
        std::string buf;
        while (std::getline(inp, buf, '\n'))
            str = buf;
        return stoi(str);
    }
};

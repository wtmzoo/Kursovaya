#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "File.h"
#include "File_reader.h"
#include "Utilities.h"
#include "Student_data.h"


using namespace std;
class Student : public StudentData
{
public:

    void make(int cnt)
    {
        set_variables(cnt);
    }

    void print_student_data() {
        cout << endl << index << " " << name << " " << day << " " << mounth << " " << year << " " << entrance_year << " " << faq << " " << kaf << " " << group << " " << gradebook 
            << " " << gender << endl;
    }


    virtual string return_values() {
        return to_string(index) + ' ' + name + ' ' + day + '.' + mounth + '.' + year + ' ' + to_string(stoi(entrance_year)) + ' ' +
            faq + ' ' + kaf + ' ' + group + ' ' + gradebook + ' ' + gender;
    }
};

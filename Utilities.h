#pragma once
#include <string>
#include <algorithm>

string replace_spaces(string data);

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

#pragma once
#include <string>
#include <algorithm>

string replace_spaces(string data);
string replace_dash(string data);



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

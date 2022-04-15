#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <regex>
#include <fstream>
#include <unordered_set>
const regex rgx(R"([+][7][-][(][9][0-9][0-9][)][-][0-9][0-9][0-9][-][0-9][0-9][-][0-9][0-9])");
int main()
{
	smatch m;
	int count = 0, kol = 0;
	setlocale(LC_ALL, "RUS");
	fstream file("file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "‘айл не может быть открыт!\n";
	}
	else
	{
		string line ="";
		unordered_set <string> uf;
		while (!file.eof())
		{
			while (getline(file, line))
			{
				if (regex_search(line, m, rgx))
				{
					for (int i = 0; i < m.size(); i++)
					{
						if (uf.find(m[i]) == uf.end())
						{
							uf.insert(m[i]);
							
						}
						else
						{
							count++;//количество повторений одного номера
							if (count == 1)
							{
								cout <<"ѕо номеру " << m[i] << " совершено наибольшее количество звонков." << endl;
							}
						}
					
					}
				}
				kol++;
			}
			cout <<"ќно равно " << count + 1 << endl;//выводит +1, так как в count помещаютс€ повторы данного номера.
		}
	}
	file.close();
	return 0;
}

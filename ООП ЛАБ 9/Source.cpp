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
		cout << "���� �� ����� ���� ������!\n";
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
							count++;//���������� ���������� ������ ������
							if (count == 1)
							{
								cout <<"�� ������ " << m[i] << " ��������� ���������� ���������� �������." << endl;
							}
						}
					
					}
				}
				kol++;
			}
			cout <<"��� ����� " << count + 1 << endl;//������� +1, ��� ��� � count ���������� ������� ������� ������.
		}
	}
	file.close();
	return 0;
}

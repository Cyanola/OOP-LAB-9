#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <thread>
using namespace std;
#include <chrono>
#include <windows.h>
#include <regex>
/*Шаблоны функций*/

template <typename T1, typename T2> //class = typename
T1 Sum(T2 a, T1 b)
{
	return a + b;
}

template <class T>
class MyClass {
public:
	MyClass(T value)
	{
		this->value = value;
	}
	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
	}
private:
	T value;

};


int main0()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");

	double a = 5.145;
	MyClass<double> c(a);
	c.DataTypeSize();
//	cout << Sum(5, 7.9139);
	return 0;
}

// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "RUS");

	int i, n;
	char a[255];
	Toy *newToy = new Toy();
	//��������� ����� ��� ������ ������ � ����
	ofstream f;
	//��������� ���� � ������ ������,
	//����� ios::out ��������������� �� ���������
	f.open("D:\\assortment.txt", ios::out);
	//������ ���������� �������
	cout << "���������� ������� = "; cin >> n;
	//���� ��� ����� �������
	//� ������ �� � ����
	for (i = 0; i<n; i++)
	{
		cout << "�������� �������: ";
		cin >> newToy->name;
		OemToCharA(newToy->name, newToy->name);
		cout << "����: ";
		cin >> newToy->price;
		cout << "����������: ";
		cin >> newToy->quant;
		cout << "�������: ";
		cin >> newToy->age;
		OemToCharA(newToy->age, newToy->age);
		f << newToy->name << "\t" << newToy->price << "\t" << newToy->quant << "\t" << newToy->age << "\t";
	}
	//�������� ������
	f.close();
	system("pause");
	ifstream c;
	c.open("D:\\assortment.txt", ios::in);
	char str[255];
	c >> str;
	//cout 
	return 0;
}

struct Toy
{
	char name[255];
	double price;
	int quant;
	char age[50];
};


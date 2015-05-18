// lab2.cpp : Defines the entry point for the console application.
//

//#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>

#include <string>
#include <windows.h>
using namespace std;


struct Toy
{
	char name[100];
	double price;
	int quant;
	int ageFrom;
	int ageTo;
};

void main()
{
	setlocale(LC_ALL, "RUS"); // ����������� ���������� � ������� ��������
	
	int n;
	Toy *newToy = new Toy();

	// ������ ������ � ����
	ofstream fout;
	fout.open("D:\\assortment.txt", ios::out);
	cout << "���������� ������� = "; cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "�������� �������: ";
		cin >> newToy->name;
		OemToCharA(newToy->name, newToy->name); // ��������������, ����� � ����� ���� ������������ ��������
		cout << "����: ";
		cin >> newToy->price;
		cout << "����������: ";
		cin >> newToy->quant;
		cout << "�������: ";
		scanf("%d%*c%d", &newToy->ageFrom, &newToy->ageTo);
		//cin >> newToy->ageFrom >> "-" >> newToy->ageTo;
		fout << newToy->name << "\t" << newToy->price << "\t" << newToy->quant << "\t" << newToy->ageFrom << "\t" << newToy->ageTo << "\n";
	}
	fout.close();
	system("pause");

	// ���������� ������ �� �����

	ifstream fin;
	fin.open("D:\\assortment.txt", ios::in);
	string str;
	getline(fin, str);   //���������� � str ������ ������.
	while (!fin.eof())    //���� �� ����� �����, �� ��������� ����.
	{
		cout << str << "\n";        //������� �� ����� ������ ������.
		getline(fin, str); //���������� ������.
	}
	fin.close();
	system("pause");

	// ����� �������

	// 1. �������� �����
	// 2. ���������� ������� � ������
	// 3. ����� � ������� ������ �������
	// 4. ����� �� �����

	fin.open("D:\\assortment.txt", ios::in);
	Toy *newToys[30];
	int m = 0;
	string str2;
	getline(fin, str2);
	while (!fin.eof())
	{
		string word[5];
		int pos = 0;
		for (int i = 0; i < 5; i++)
		{
			int t_pos = str2.find("\t", pos);
			word[i] = str2.substr(pos, (t_pos - pos));
			pos = t_pos + 1;
		}
		newToys[m] = new Toy();
		strcpy(newToys[m]->name, word[0].c_str());
		newToys[m]->price = atof(word[1].c_str());
		newToys[m]->quant = atoi(word[2].c_str());
		newToys[m]->ageFrom = atoi(word[3].c_str());
		newToys[m]->ageTo = atoi(word[4].c_str());

		getline(fin, str2);
		m++;
	}
	fin.close();
	system("pause");


	return;
}




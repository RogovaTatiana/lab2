// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
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
		cout << "���� (������ ����� 00.00): ";
		cin >> newToy->price;
		cout << "����������: ";
		cin >> newToy->quant;
		cout << "������� (������ ����� 0-0): ";
		scanf("%d%*c%d", &newToy->ageFrom, &newToy->ageTo);
		fout << newToy->name << "\t" << newToy->price << "\t" << newToy->quant << "\t" << newToy->ageFrom << "\t" << newToy->ageTo << "\n";
	}
	fout.close();
	system("pause");

	// ���������� ������ �� �����

	ifstream fin;
	fin.open("D:\\assortment.txt", ios::in);
	if (fin.is_open())
	{
		string str;
		getline(fin, str);   //���������� � str ������ ������.
		while (!fin.eof())    //���� �� ����� �����, �� ��������� ����.
		{
			cout << str << "\n";        //������� �� ����� ������ ������.
			getline(fin, str); //���������� ������.
		}
		fin.close();
	}
	else cout << "������ ��� �������� �����";
	system("pause");

	// ����� �������

	// 1. �������� �����
	// 2. ���������� ������� � ������
	// 3. ����� � ������� ������ �������
	// 4. ����� �� �����

	fin.open("D:\\assortment.txt", ios::in);
	if (fin.is_open())
	{
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
			int point_pos = word[1].find(".");
			word[1].replace(point_pos, 1, ",");
			newToys[m]->price = atof(word[1].c_str());
			newToys[m]->quant = atoi(word[2].c_str());
			newToys[m]->ageFrom = atoi(word[3].c_str());
			newToys[m]->ageTo = atoi(word[4].c_str());

			getline(fin, str2);
			m++;
		}
		fin.close();
		cout << "�������, ������� �������� ����� �� 1 �� 3: \n";
		for (int i = 0; i < m; i++)
		{
			if (newToys[i]->ageFrom <= 1 && newToys[i]->ageTo >= 3)
				cout << newToys[i]->name << " \n";
		}
		system("pause");
		cout << "����� ������� ������� � ������������: \n";
		double max = newToys[0]->price;
		int index = 0;
		for (int i = 1; i < m; i++)
		{
			if (newToys[i]->price > max)
			{
				max = newToys[i]->price;
				index = i;
			}
		}
		cout << newToys[index]->name << "\t" << newToys[index]->price << " \n";
		system("pause");

		double price;
		int ageFrom;
		int ageTo;

		cout << "������� ������� ������: \n";
		cout << "���� �� ";
		cin >> price;
		cout << "������� �� ";
		cin >> ageFrom;
		cout << "������� �� ";
		cin >> ageTo;

		for (int i = 0; i < m; i++)
		{
			if (newToys[i]->ageFrom <= ageFrom && newToys[i]->ageTo >= ageTo && newToys[i]->price <= price)
				cout << newToys[i]->name << " \n";
		}
	}
	else cout << "������ ��� �������� �����";

	system("pause");
	return;
}




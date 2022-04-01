#include "disk.h"
#include "cpu.h"
#include "ram.h"
#include "gpu.h"
#include "kbd.h"
#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int count = 0;
	string s = "";
	while (s != "exit") {
		cout << "\n�������� ��������:";
		cout << "\n     sum - ���������� �����";
		cout << "\n     save - ��������� � ����";
		cout << "\n     load - ��������� �� �����";
		cout << "\n     input - ������ � ����������";
		cout << "\n     display - ������� �� �����";
		cout << "\n     exit - ������� �� ���������.";
		cin >> s;
		if (s == "input") {
			count++;
			int i = 0, acceptVal = 0;
			ram(i, s, acceptVal);
			s = "";
		}
		else if (s == "display") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}
			gpu();
			s = "";
		}
		else if (s == "sum") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}
			cout << "\n���������: " << cpu();
			s = "";
		}
		else if (s == "save") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}
			disk(s);
			s = "";
		}
		else if (s == "load") {
			disk(s);
			count++;  // �����, ����� ����� �������� � ����������� ������ 
					   //����������� ���������� ��������.
			s = "";
		}
		else if (s == "exit") {
			break;
		}
	}
	return 0;
}

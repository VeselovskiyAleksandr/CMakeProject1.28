#include "cpu.h"
#include "ram.h"
#include "disk.h"
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
	string str = "";
	while (str != "exit") {
		cout << "\n�������� ��������:";
		cout << "\n     sum - ���������� �����";
		cout << "\n     save - ��������� � ����";
		cout << "\n     load - ��������� �� �����";
		cout << "\n     input - ������ � ����������";
		cout << "\n     display - ������� �� �����";
		cout << "\n     exit - ������� �� ���������.";
		cin >> str;
		if (str == "input") {
			count++;
			int i = 0, acceptVal = 0;
			ram(i, str, acceptVal);
			str = "";
		}
		else if (str == "display") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}
			gpu();
			str = "";
		}
		else if (str == "sum") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}
			cout << "\n���������: " << cpu();
			str = "";
		}
		else if (str == "save") {
			if (count == 0) {
				cout << "\n����������� ������ �� ���������.";
				break;
			}

			disk(str);
			str = "";
		}
		else if (str == "load") {
			disk(str);
			count++;  // �����, ����� ����� �������� � ����������� ������ 
					   //����������� ���������� ��������.
			str = "";
		}
		else if (str == "exit") {
			break;
		}
	}
	return 0;
}

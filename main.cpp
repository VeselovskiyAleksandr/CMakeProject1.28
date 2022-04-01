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
		cout << "\nВыберите действие:";
		cout << "\n     sum - вычисление суммы";
		cout << "\n     save - сохранить в файл";
		cout << "\n     load - загрузить из файла";
		cout << "\n     input - ввести с клавиатуры";
		cout << "\n     display - вывести на экран";
		cout << "\n     exit - выходит из программы.";
		cin >> s;
		if (s == "input") {
			count++;
			int i = 0, acceptVal = 0;
			ram(i, s, acceptVal);
			s = "";
		}
		else if (s == "display") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}
			gpu();
			s = "";
		}
		else if (s == "sum") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}
			cout << "\nРезультат: " << cpu();
			s = "";
		}
		else if (s == "save") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}
			disk(s);
			s = "";
		}
		else if (s == "load") {
			disk(s);
			count++;  // нужно, чтобы после загрузки в оперативную память 
					   //производить дальнейшие действия.
			s = "";
		}
		else if (s == "exit") {
			break;
		}
	}
	return 0;
}

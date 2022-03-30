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
		cout << "\nВыберите действие:";
		cout << "\n     sum - вычисление суммы";
		cout << "\n     save - сохранить в файл";
		cout << "\n     load - загрузить из файла";
		cout << "\n     input - ввести с клавиатуры";
		cout << "\n     display - вывести на экран";
		cout << "\n     exit - выходит из программы.";
		cin >> str;
		if (str == "input") {
			count++;
			int i = 0, acceptVal = 0;
			ram(i, str, acceptVal);
			str = "";
		}
		else if (str == "display") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}
			gpu();
			str = "";
		}
		else if (str == "sum") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}
			cout << "\nРезультат: " << cpu();
			str = "";
		}
		else if (str == "save") {
			if (count == 0) {
				cout << "\nОперативная память не заполнена.";
				break;
			}

			disk(str);
			str = "";
		}
		else if (str == "load") {
			disk(str);
			count++;  // нужно, чтобы после загрузки в оперативную память 
					   //производить дальнейшие действия.
			str = "";
		}
		else if (str == "exit") {
			break;
		}
	}
	return 0;
}

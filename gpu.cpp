#include "gpu.h"
#include "ram.h"
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

void gpu() {
	setlocale(LC_ALL, "rus");
	cout << "\nЗначения в оперативной памяти: ";
	int acceptVal = 0;
	string str = "display";
	for (int i = 0; i < 8; i++) {
		cout << ram(i, str, acceptVal) << " ";
	}
}
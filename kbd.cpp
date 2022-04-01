#include "kbd.h"
#include <iostream>
#include <locale.h>
#include <string> 
using namespace std;

int kbd() {
	setlocale(LC_ALL, "rus");
	int x = 0;
	cout << "\n¬ведите значение. ";
	cin >> x;
	return x;
}

#include "ram.h"
#include "kbd.h"
#include <string>
#include <locale.h>
using namespace std;

struct memory {
	int	x;
}
number[8];

void write(memory number[8]) {
	for (int i = 0; i < 8; i++) {
		number[i].x = kbd();
	}
}

int read(int i, memory number[8]) {
	return number[i].x;
}

int ram(int i, string str, int acceptVal) {
	if (str == "input") {
		write(number);
	}
	else if (str == "display") {
		return read(i, number);
	}
	else if (str == "sum") {
		return  read(i, number);
	}
	else if (str == "load") {	
		number[i].x = acceptVal;
	}
	else if (str == "save") {
		return read(i, number);
	}
	return 0;
}
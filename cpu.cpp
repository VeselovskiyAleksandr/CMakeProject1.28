#include "cpu.h"
#include "ram.h"
#include <iostream>

using namespace std;
int  cpu() {
	int sum = 0, acceptVal=0;
	string str = "sum";
	for (int i = 0; i < 8; i++) {
		sum += ram(i, str, acceptVal);
	}
	return sum;
}
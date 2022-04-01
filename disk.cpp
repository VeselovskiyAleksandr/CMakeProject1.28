#include "disk.h"
#include "ram.h"
#include "data.txt"
#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
using namespace std;

int save() {
	ofstream file("data.txt", ios::trunc);
    string str = "save";
    int z, acceptVal=0;
	if (file.is_open()) {
		cout << "\nФайл открыт для записи.";
	}
	else {
		cerr << "\nФайл не найден.";
		return 1;
	}
	for (int i = 0; i < 8; i++) {
		z = ram(i, str, acceptVal);
		file << z << " ";
	}
	return 0;
}

int load() {
	ifstream file;
	file.open("data.txt");
	if (file.is_open()) {
		cout << "\nФайл открыт для чтения.";
	}
	else {
		cerr << "\nФайл не найден. ";
		return 1;
	}
	int z;
	string str = "load";
	for (int i = 0; i < 8; i++) {
	file >> z;
		ram(i, str, z);
	}
	file.close();
	return 0;
}

int disk(string str) {
	if (str == "save") {
			save();
	}
	else if (str == "load") {
		int acceptVal = 0;
			load();
	}
	return 0;
}

#include "disk.h"
#include "ram.h"
#include "data.txt"
#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int save() {
	//ofstream file("C:\\Users\\Александр\\Documents\\text for program\\data.txt", ios::trunc);
	ofstream file("data.txt", ios::trunc);
	if (file.is_open()) {
		cout << "\nФайл открыт для записи.";
	}
	else {
		cerr << "\nФайл не найден.";
		return 1;
	}
	for (int i = 0; i < 8; i++) {
		string str = "save";
		int z, acceptVal;
		z = ram(i, str, acceptVal);
		file << z << " ";
		//file<< ram(i, str, acceptVal=0)<<" ";
	}
	return 0;
}

int load() {
	ifstream file;
	//file.open("C:\\Users\\Александр\\Documents\\text for program\\data.txt");
	file.open("data.txt");
	int num[8];
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
	return z;
}

int disk(string str) {
	if (str == "save") {
		int t, acceptVal = 0;
		for (int i = 0; i < 8; i++) {
			//t = ram(i, str, acceptVal);
			save();
		}
	}
	else if (str == "load") {
		int acceptVal = 0;
		for (int i; i < 8; i++) {
			load();
			acceptVal = load();
			ram(i, str, acceptVal);
		}
	}
	return 0;
}
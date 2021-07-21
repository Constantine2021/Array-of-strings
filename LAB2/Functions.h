#pragma once

#define BUF_SIZE 256
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


template<typename T>void giveMem(T*&, int, bool);
template<typename T>void giveMem(T*&, int);
template<typename T>void mySwap(T&, T&);
void getStr(istream&, char*&, int);
void setStr(char*&, char*);
template<typename T>T max(T, T);
template<typename T>T min(T, T);


void getStr(istream& stream, char*& str, int size) {
	while (1) {
		fflush(stdin);
		stream.getline(str, size);
		if (strlen(str)) break;
	}
}

void setStr(char*& dest, char* src) {
	if (!src) return;
	if (dest) delete[] dest;
	giveMem(dest, strlen(src) + 1);
	strcpy(dest, src);
};
template<typename T>void giveMem(T*& dest, int size, bool zero) {
	try {
		dest = new T[size];
	}
	catch (...) {
		cout << "Error while allocating memory\n";
		system("pause");
		exit(1);
	}
	if (zero) {
		for (int i = 0; i < size; i++) dest[i] = 0;
	}
}

template<typename T>void mySwap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>void giveMem(T*& dest, int size) {
	try {
		dest = new T[size];
	}
	catch (...) {
		cout << "Error while allocating memory\n";
		system("pause");
		exit(1);
	}
}

template<typename T>T Gmin(T a, T b) { return a < b ? a : b; }
template<typename T>T Gmax(T a, T b) { return a > b ? a : b; }
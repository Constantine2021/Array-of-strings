#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


class StrArr
{
	char** ptr;
	int num;
public:
	StrArr();
	StrArr(int);
	StrArr(const StrArr& other);
	~StrArr();

	void elCat(const StrArr, const StrArr);
	void sort(int, int);
	void addUnique(const StrArr);

	void setNum(int);
	int getNum() { return num; };

	StrArr operator+(const StrArr&);
	StrArr operator*(const StrArr&);
	char*& operator[](int);
	StrArr& operator=(const StrArr&);

	friend ostream& operator<<(ostream&, const StrArr&);
	friend istream& operator>>(istream&, const StrArr&);
};
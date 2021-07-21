#include "StrArr.h"
#include "Functions.h"


StrArr::StrArr() : ptr(nullptr), num(0) {};
StrArr::StrArr(int inNum) : ptr(nullptr), num(inNum) { giveMem(ptr, num); };
StrArr::StrArr(const StrArr& other) : ptr(nullptr), num(other.num) {
	giveMem(ptr, num);
	for (int i = 0; i < num; i++) {
		ptr[i] = nullptr;
		setStr(ptr[i], other.ptr[i]);
	}
};

StrArr::~StrArr()
{
	for (int i = 0; i < num; i++)
		if (ptr[i]) delete[] ptr[i];
	if (ptr) delete[] ptr;
};

void StrArr::elCat(const StrArr a, const StrArr b) {
	if (this->ptr) {
		for (int i = 0; i < num; i++)
			if (ptr[i]) delete[] ptr[i];
		delete[] ptr;
	}
	this->num = Gmax(a.num, b.num);
	giveMem(this->ptr, this->num);
	for (int i = 0; i < Gmin(a.num, b.num); i++) {
		giveMem(this->ptr[i], strlen(a.ptr[i]) + strlen(b.ptr[i]) + 1);
		strcpy(this->ptr[i], a.ptr[i]);
		strcat(this->ptr[i], b.ptr[i]);
	}
	if (a.num > b.num) {
		for (int i = b.num; i < a.num; i++) {
			this->ptr[i] = nullptr;
			setStr(this->ptr[i], a.ptr[i]);
		}
	}
	else {
		for (int i = a.num; i < b.num; i++) {
			this->ptr[i] = nullptr;
			setStr(this->ptr[i], b.ptr[i]);
		}
	}
};

void StrArr::sort(int begin, int end) {
	for (int i = begin; i < end - 1; i++) {
		for (int j = i + 1; j < end; j++) {
			if (strcmp(this->ptr[i], this->ptr[j]) > 0)
				mySwap(this->ptr[i], this->ptr[j]);
		}
	}
};

void StrArr::addUnique(const StrArr other) {
	*this = *this + other;
	bool* isUnique;
	int size = this->num;
	giveMem(isUnique, size);
	for (int i = 0; i < size; i++) isUnique[i] = true;
	for (int i = 0; i < this->num - 1; i++) {
		if (isUnique[i]) {
			for (int j = i + 1; j < this->num; j++) {
				if (!strcmp(this->ptr[i], this->ptr[j])) {
					isUnique[j] = false;
					size--;
				}
			}
		}
	}
	StrArr res(size);
	for (int i = 0, j = 0; i < this->num && j < size; i++) {
		if (isUnique[i]) {
			res.ptr[j] = nullptr;
			setStr(res.ptr[j], this->ptr[i]);
			j++;
		}
	}
	*this = res;
};

StrArr StrArr::operator+(const StrArr& other)
{
	int i, j;
	int resNum = this->num + other.num;
	StrArr res(resNum);
	for (i = 0; i < this->num; i++) {
		res.ptr[i] = nullptr;
		setStr(res.ptr[i], this->ptr[i]);
	}

	for (i = this->num, j = 0; i < resNum && j < other.num; i++, j++) {
		res.ptr[i] = nullptr;
		setStr(res.ptr[i], other.ptr[j]);
	}
	return res;
};

StrArr StrArr::operator*(const StrArr& other) {
	StrArr res;
	res.elCat(*this, other);
	return res;
};

char*& StrArr::operator[](int index) { return this->ptr[index]; };

StrArr& StrArr::operator=(const StrArr& other) {
	if (this != &other) {
		for (int i = 0; i < this->num; i++)
			if (this->ptr[i]) delete[] ptr[i];
		if (this->ptr) delete[] ptr;

		this->num = other.num;
		giveMem(this->ptr, this->num);
		for (int i = 0; i < this->num; i++) {
			this->ptr[i] = nullptr;
			setStr(this->ptr[i], other.ptr[i]);
		}
	}
	return *this;
};

void StrArr::setNum(int inNum) {
	if (ptr) {
		for (int i = 0; i < num; i++) {
			if (ptr[i]) delete[] ptr[i];
		}
		delete[] ptr;
	}
	num = inNum;
	giveMem(ptr, num, true);
};

ostream& operator<<(ostream& stream, const StrArr& other) {
	for (int i = 0; i < other.num; i++) stream << other.ptr[i] << '\n';
	return stream;
};

istream& operator>>(istream& stream, const StrArr& other) {
	if (!other.ptr) {
		cout << "Firstly, set the amount of strings!\n";
	}
	else {
		char* buffer;
		giveMem(buffer, BUF_SIZE);
		cout << "Enter strings:\n";
		for (int i = 0; i < other.num; i++) {
			getStr(stream, buffer, BUF_SIZE);
			setStr(other.ptr[i], buffer);
		}
	}
	return stream;
};
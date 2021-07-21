/*Разработать класс для массива строк.Написать несколько конструкторов, 
в том числе конструктор копирования.Реализовать методы для поэлементной конкатенации двух массивов, 
упорядочения строк в лексикографическом порядке, слияния двух массивов с удалением повторяющихся строк, а также
для вывода на экран всего масси - ва и заданной строки.Перегрузить операции сложения, умножения, индексирования, 
присваивания для данного класса.Создать массив объектов и передавать объекты в функцию, которая выполняет слияние
объектов и для полученного объекта - результата производит лексикографическое упорядочения строк.
*/

#include "StrArr.h"
#include <iostream>
#include <clocale>
#include <Windows.h>


using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int op;
	int input;
	StrArr a, b, c;
	
	while (1) {
		system("cls");
		cout << "Выберете действие:\n";
		cout << "0) выход\n";
		cout << "1) Введите первый массив строк\n";
		cout << "2) Введите второй массив строк\n";
		cout << "3) Использование оператора \"+\" \n";
		cout << "4) Использование оператора \"*\" \n";
		cout << "5) Сортировка в лексикографическом порядке\n";
		cout << "6) Конкатенация\n";
		cout << "7) Слияние массивов строк с удалением повторяющихся строк\n";
		
		
		cin >> op;
		if (op == 0) {
			exit(0);
			break;
		}
		switch (op) {
		case 1:
			cout << "Введите количество строк: ";
			cin >> input;
			a.setNum(input);
			cin >> a;
			system("pause");
			break;
		case 2:
			cout << "Введите количество строк: ";
			cin >> input;
			b.setNum(input);
			cin >> b;
			system("pause");
			break;
		case 3:
			c = a + b;
			cout << c;
			system("pause");
			break;
		case 4:
			c = a * b;
			cout << c;
			system("pause");
			break;
		case 5:
			a.sort(0, a.getNum());
			cout << a;
			system("pause");
			break;
		
		case 6:
			c.elCat(a, b);
			cout << c;
			system("pause");
			break;
		case 7:
			c = a;
			c.addUnique(b);
			cout << c;
			system("pause");
			break;
		default:
			cout << "НЕВЕРНОЕ ДЕЙСТВИЕ\n";
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}
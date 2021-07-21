/*����������� ����� ��� ������� �����.�������� ��������� �������������, 
� ��� ����� ����������� �����������.����������� ������ ��� ������������ ������������ ���� ��������, 
������������ ����� � ������������������ �������, ������� ���� �������� � ��������� ������������� �����, � �����
��� ������ �� ����� ����� ����� - �� � �������� ������.����������� �������� ��������, ���������, ��������������, 
������������ ��� ������� ������.������� ������ �������� � ���������� ������� � �������, ������� ��������� �������
�������� � ��� ����������� ������� - ���������� ���������� ������������������ ������������ �����.
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
		cout << "�������� ��������:\n";
		cout << "0) �����\n";
		cout << "1) ������� ������ ������ �����\n";
		cout << "2) ������� ������ ������ �����\n";
		cout << "3) ������������� ��������� \"+\" \n";
		cout << "4) ������������� ��������� \"*\" \n";
		cout << "5) ���������� � ������������������ �������\n";
		cout << "6) ������������\n";
		cout << "7) ������� �������� ����� � ��������� ������������� �����\n";
		
		
		cin >> op;
		if (op == 0) {
			exit(0);
			break;
		}
		switch (op) {
		case 1:
			cout << "������� ���������� �����: ";
			cin >> input;
			a.setNum(input);
			cin >> a;
			system("pause");
			break;
		case 2:
			cout << "������� ���������� �����: ";
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
			cout << "�������� ��������\n";
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}
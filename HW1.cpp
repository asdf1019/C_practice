#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char str[10];
	double a, b, c;

	cout << "�̸� : ";
	cin.getline(str, sizeof(str));
	cout << "�� ������ ���� : ";
	cin >> a >> b >> c;
	while (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "�� ������ ���� : ";
		cin >> a >> b >> c;
	}
	cout << "\n\n" << "                    =====< ����ǥ >=====                    " << "\n";
	cout << "============================================================" << "\n";
	cout << right;
	cout << setw(10) << "�̸�" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "����" << setw(10) << "���" << "\n";
	cout << "============================================================" << "\n";
	cout << setw(10) << str << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << a + b + c;
	cout << setprecision(2);
	cout << fixed << setw(10) << (a + b + c) / 3;
}
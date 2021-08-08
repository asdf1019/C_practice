#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char str[10];
	double a, b, c;

	cout << "이름 : ";
	cin.getline(str, sizeof(str));
	cout << "세 과목의 점수 : ";
	cin >> a >> b >> c;
	while (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "세 과목의 점수 : ";
		cin >> a >> b >> c;
	}
	cout << "\n\n" << "                    =====< 성적표 >=====                    " << "\n";
	cout << "============================================================" << "\n";
	cout << right;
	cout << setw(10) << "이름" << setw(10) << "국어" << setw(10) << "영어" << setw(10) << "수학" << setw(10) << "총점" << setw(10) << "평균" << "\n";
	cout << "============================================================" << "\n";
	cout << setw(10) << str << setw(10) << a << setw(10) << b << setw(10) << c << setw(10) << a + b + c;
	cout << setprecision(2);
	cout << fixed << setw(10) << (a + b + c) / 3;
}
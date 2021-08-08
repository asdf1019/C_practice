#include <iostream>
#include <iomanip>
using namespace std;

struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};
void init(Savings& s);
void input(int& unit, int& cnt);
void save(Savings& s, int unit, int cnt);
int total(Savings& s);

int main() {

	int unit, cnt;
	struct Savings money;
	int totmoney;
	init(money);
	while (1) {
		input(unit, cnt);
		if (unit < 0) {
			break;
		}
		save(money, unit, cnt);
	}
	totmoney = total(money);
	cout << "총 저금액 : " << totmoney << endl;
	return 0;
	
}

void init(Savings& s) {
	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;
}
void input(int& unit, int& cnt) {
	while (1) {
		cout << "동전의 금액 : ";
		cin >> unit;
		if (unit<0 || unit == 500 || unit == 100 || unit == 50 || unit == 10) {
			break;
		}
	}
	while (cin.fail()) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "동전의 금액 : ";
		cin >> unit;
	}
	if (unit == 500 || unit == 100 || unit == 50 || unit == 10) {
		cout << "동전의 개수 : ";
		cin >> cnt;
		while (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "동전의 개수 : ";
			cin >> cnt;
		}
	}
}
void save(Savings& s, int unit, int cnt) {
	switch (unit) {
		case 10 : s.w10 += cnt; break;
		case 100 : s.w100 += cnt; break;
		case 50 : s.w50 += cnt; break;
		case 500 : s.w500 += cnt; break;
	}
}
int total(Savings& s) {
	return 10 * s.w10 + 100 * s.w100 + 50 * s.w50 + 500 * s.w500;
}
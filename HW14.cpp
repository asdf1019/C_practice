#include <iostream>
using namespace std;

class Save {
private :
	char name[20];
	int capital;
	int profit;
	int tax;
	int tot;
	static double ratio;
public :
	static double tax_ratio;
	Save(const char* np = "�ƹ���", int n = 0);
	void calculate();
	friend ostream& operator << (ostream& os, const Save& br);
	static void set_ratio(double r) {
		Save::ratio = r;
	}
};
double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;
int main() {
	Save a("ö��", 1000000);
	a.calculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	Save b("����", 2000000);
	b.calculate();
	cout << b << endl;
	return 0;
}
Save::Save(const char* np, int n) {
	strcpy(name, np);
	capital = n;
	profit = 0;
	tax = 0;
	tot = 0;
}
void Save::calculate() {
	profit = capital * Save::ratio;
	tax = profit * tax_ratio;
	tot = capital + profit - tax;
}
ostream& operator << (ostream& os, const Save& br) {
	cout << "�̸� : " << br.name << endl;
	cout << "���� : " << br.capital << endl;
	cout << "���ڼҵ� : " << br.profit << endl;
	cout << "���� : " << br.tax << endl;
	cout << "�ѱݾ� : " << br.tot << endl;
	cout << "���� : " << Save::ratio << endl;
	cout << "���� : " << br.tax_ratio << endl;
	return os;
}
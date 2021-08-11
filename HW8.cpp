#pragma warning(disable:4996)
#include<iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time& tr);
	Time plus(const Time& tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
};
Time::Time() {
	hour = 0;
	min = 0;
}
Time::Time(int h, int m) {
	hour = h;
	min = m;
}
Time::Time(double dh) {
	hour = (int)dh;
	double m = dh * 60;
	min = (int)m % 60;
}
Time::Time(const Time& tr) {
	this->hour = tr.hour;
	this->min = tr.min;
}
Time Time::plus(const Time& tr) {
	Time t;
	t.hour = getHour();
	t.min = getMin();
	t.hour += tr.hour;
	t.min += tr.min;

	if (t.min > 60) {
		t.hour += t.min / 60;
		t.min = t.min % 60;
	}

	return t;
}
void Time::setHour(int h) {
	hour = h;
}
int Time::getHour() {
	return hour;
}
void Time::setMin(int m) {
	min = m;
}
int Time::getMin() {
	return min;
}

int main() {
	Time a(3, 20), b;
	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð�" << res.getMin() << "��" << endl;
	Time c(4.5);
	cout << c.getHour() << "�ð�" << c.getMin() << "��" << endl;
	return 0;
}
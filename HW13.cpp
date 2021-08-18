#include <iostream>
using namespace std;

class Time {
private :
	int hour;
	int min;
	double time;
	static int mode;
	enum {integer, real};
public :
	Time();
	Time(int, int);
	Time(double);
	Time(const Time& tr);
	Time plus(const Time& tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	friend ostream& operator<<(ostream& os, const Time& br);
	static void mode_change() {
		if (mode == 0) {
			mode = 1;
		}
		else mode = 0;
	}
};
int Time::mode;
int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "기본 출력 형태(시간, 분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
	return 0;
}
Time::Time() {
	hour = 0;
	min = 0;
	time = 0;
	mode = integer;
}
Time::Time(int h, int m) {
	hour = h;
	min = m;
	double t = hour * 60 + min;
	time = t / 60;
	mode = integer;
}
Time::Time(double d) {
	time = d;
	int t = d * 60;
	hour = t / 60;
	min = t % 60;
	mode = integer;
}
Time::Time(const Time& tr) {
	hour = tr.hour;
	min = tr.min;
	time = tr.time;
	mode = tr.mode;
}
Time Time::plus(const Time& tr) {
	hour += tr.hour;
	min = tr.min;
	if (min >= 60) {
		hour++;
		min -= 60;
	}
	time = tr.time;
	return *this;
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
ostream &operator<<(ostream& os, const Time& br) {
	if (br.mode == Time::integer) {
		cout << br.hour << "시간 " << br.min << "분";
	}
	else {
		cout << br.time << "시간";
	}
	return os;
}
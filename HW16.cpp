#include <iostream>
using namespace std;
#include "MyAry.h"
class SmartArray : public MyArray
{
private:
	int max;
public:
	SmartArray();
	SmartArray(int s);
	bool put(int index, int val);
	bool operator>(const SmartArray& br);
	int getMax();
};
SmartArray::SmartArray() { max = 0; }
SmartArray::SmartArray(int s) : MyArray(s), max(0)
{}
bool SmartArray:: put(int index, int val) {
	if (index > getSize() - 1) {
		return false;
	}
	else {
		MyArray::put(index, val);
		getMax();
	}
	return true;
}
int SmartArray::getMax() {
	int* a;
	a = new int;
	a = getAry();
	max = a[0];
	for (int i = 0; i < getSize(); i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
bool SmartArray::operator>(const SmartArray& br) {
	if (this->max > br.max) {
		return true;
	}
	else return false;
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(2);
	SmartArray a(3);
	SmartArray b(5);
	int temp;
	int tot1 = 0, tot2 = 0;
	cout << "ö���� �� ������ ���� �Է� : ";
	for (int i = 0; i < 3; i++) {
		cin >> temp;
		a.put(i, temp);
		tot1 += temp;
	}
	cout << "ö���� ���� : " << tot1 << endl;
	cout << "ö���� ��� : " << (double)tot1 / 3 << endl;

	cout << "������ �ټ� ������ ���� �Է� : ";
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		a.put(i, temp);
		tot2 += temp;
	}
	cout << "������ ���� : " << tot2 << endl;
	cout << "������ ��� : " << (double)tot2 / 5 << endl;

	if (a.getMax() < b.getMax()) {
		cout << "ö���� �ְ����� ���ں��� ũ��...";
	}
	else cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�...";
}
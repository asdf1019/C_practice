#include <iostream>
using namespace std;
#include "MyAry.h"
int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	MyArray score(3);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;

	for (i = 0; i < 4; i++) {
		cout << i + 1 << "번 학생의 성적 입력 : ";
		cin >> temp;
		if (score.put(i, temp) == false) {
			cout << "배열 쓰기 실패" << endl;
		}
	}
	for (i = 0; i < 4; i++) {
		res = score.get(i, num);
		if (res) {
			tot += num;
		}
		else {
			cout << "배열 읽기 실패" << endl;
		}
	}
	cout << "평균 :" << tot / 3.0 << endl;
	MyArray tempArray(score);
	MyArray tmp;
	tmp = score;

	return 0;
}
MyArray::MyArray() { ary = 0; size = 0; }
MyArray::MyArray(int s) {
	size = s;
	ary = new int[size];
}
MyArray::MyArray(const MyArray& br) {
	ary = new int[br.size];
	size = br.size;
	for (int i = 0; i < size;i++) {
		ary[i] = br.ary[i];
	}
}
MyArray::~MyArray() { delete[] ary; }
MyArray& MyArray::operator=(const MyArray& br) {
	if (this == &br) return *this;
	delete[] ary;
	ary = new int[br.size];
	size = br.size;
	for (int i = 0; i < size; i++) {
		ary[i] = br.ary[i];
	}
	return *this;
}
bool MyArray::put(int index, int val) {
	if (index > size - 1) {
		return false;
	}
	else {
		ary[index] = val;
		return true;
	}
	
}
bool MyArray::get(int index, int& getdata) {
	if (index > size - 1) {
		return false;
	}
	else {
		getdata = ary[index];
		return true;
	}
}
int MyArray::getSize() {
	return size;
}
int* MyArray::getAry(void) {
	return ary;
}
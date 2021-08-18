#include <iostream>
using namespace std;
#include "MyAry.h"
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
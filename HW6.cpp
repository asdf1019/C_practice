#include <iostream>
using namespace std;
void swap_ptr(const char* & ap, const char* & bp);

int main() {
	const char* ap = "apple";
	const char* bp = "banana";

	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap_ptr(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;

	return 0;
}

void swap_ptr(const char * & ap, const char* & bp) {
	const char* cp;
	cp = ap;
	ap = bp;
	bp = cp;
}
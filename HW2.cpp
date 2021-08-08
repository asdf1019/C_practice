#include <iostream>
using namespace std;
int max(int a, int b);
char* max(char str1[], char str2[]);

int main() {
	double a, b, dres;
	cout << "두 실수 입력 : ";
	cin >> a >> b;
	dres = max(a, b);
	cout << "큰 값 : " << dres << "\n";
	char str1[100], str2[100];
	char* cres;
	cout << "두 문자열 입력 : ";
	cin >> str1 >> str2;
	cres = max(str1, str2);
	cout << "긴 문자열 : " << cres;

}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else return b;
}

char* max(char* str1, char* str2) {
	if (strlen(str1) >= strlen(str2)) {
		return str1;
	}
	else {
		return str2;
	}
}
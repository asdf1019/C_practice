#include <iostream>
using namespace std;
int max(int a, int b);
char* max(char str1[], char str2[]);

int main() {
	double a, b, dres;
	cout << "�� �Ǽ� �Է� : ";
	cin >> a >> b;
	dres = max(a, b);
	cout << "ū �� : " << dres << "\n";
	char str1[100], str2[100];
	char* cres;
	cout << "�� ���ڿ� �Է� : ";
	cin >> str1 >> str2;
	cres = max(str1, str2);
	cout << "�� ���ڿ� : " << cres;

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
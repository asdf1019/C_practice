#include <iostream>
#include <iomanip>
using namespace std;
int my_strlen(char str[], char ch = '#');

int main() {
	char str[80];
	char l;
	cout << "���ڿ� �Է� : ";
	cin.getline(str, sizeof(str));
	cout << "���ڿ��� ���� : " << my_strlen(str) << "\n";
	
	cout << "���� �Է� : ";
	cin >> l;
	cout << l << " ���� ������ ���� : " << my_strlen(str, l);
	return 0;
}

int my_strlen(char str[], char ch) {
	int len = 0;
	if (ch == '#') {
		for (int i = 0; i < 80; i++) {
			if (str[i] != '\0') {
				len++;
			}
			else return len;
		}
	}
	else {
		for (int i = 0; i < 80; i++) {
			if (str[i] != ch && str[i] != '\0') {
				len++;
			}
			else return len;
		}
	}
}
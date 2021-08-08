#include <iostream>
#include <iomanip>
using namespace std;
void str_prn(char str[], char ch = '#');

int main() {
	char str[80];
	cout << "문자 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_prn(str);
	cout << "\n";
	str_prn(str, ch);
	return 0;
}

void str_prn(char str[], char ch) {
	if (ch == '#') {
		cout << str;
	}
	else {
		for (int i = 0; i < 80; i++) {
			if (str[i] != ch && str[i] != '\0') {
				cout << str[i];
			}
			else {
				break;
			}
		}
	}
}
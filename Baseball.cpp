#pragma warning(disable:4996)
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
int random(int);
void game(int t, int* n);
void numset(int* n);
int result(int strike, int ball);
int count(int* r, int* n);

int main()
{
	int t = 1;
	int randomnum[4];
	int n[4];
	srand((unsigned int)time(NULL)); 
	numset(randomnum);

	while (1) {
		game(t, n);
		if (count(randomnum, n) == 1) {
			break;
			}
		t++;
	}

	return 0;
}
int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}
void numset(int *n) {
	for (int i = 0; i < 4; i++) {
		n[i] = random(9) + 1;
		for (int j = 0; j < i; j++) {
			if (n[i] == n[j]) {
				i--;
			}
		}
	}
}
int count(int *r, int * n) {
	int strike = 0;
	int ball = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (r[i] == n[j]) {
				if (i == j) {
					strike++;
				}
				else {
					ball++;
				}
			}
		}
	}
	return result(strike, ball);
}
void game(int t, int * n) {
	cout << "# " << t << "Â÷ : ";
	for (int i = 0; i < 4; i++) {
		cin >> n[i];
	}
}
int result(int strike, int ball) {
	if (strike == 0 && ball == 0) {
		cout << "No!";
	}
	else if (strike == 4) {
		cout << "OK!!!";
		return 1;
	}
	else {
		cout << strike << "S " << ball << "B";
	}
	cout << endl;
	return 0;
}
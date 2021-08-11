#include <iostream>
using namespace std;
#include "Robot.h"
void init(Robot* rp, int cnt);
void work(Robot* rp, int cnt);
void output(Robot* rp, int cnt);

int main() {
	Robot* rp;
	int cnt;
	cout << "������ �κ� ����� �Է��Ͻÿ� : ";
	cin >> cnt;
	cout << endl;
	rp = new Robot[cnt];

	init(rp, cnt);
	work(rp, cnt);
	output(rp, cnt);

	delete[] rp;
	return 0;
}

void init(Robot* rp, int cnt) {
	char name[20];
	int energy;

	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "�� �κ����� �Է��Ͻÿ� : ";
		cin >> name;
		cout << name << "�� ������ ���� �Է��Ͻÿ� : ";
		cin >> energy;
		cout << endl;
		rp[i].setName(name);
		rp[i].setEnergy(energy);
	}
}

void work(Robot* rp, int cnt) {
	char r[20];
	char w[5];

	while(1) {
		cout << "# �κ��� ����(";
		for (int i = 0; i < cnt; i++) {
			cout << rp[i].getName();
			if (i < cnt - 1) {
				cout << ", ";
			}
		}
		cout << ") : ";
		cin >> r;
		if (!strcmp(r, "end")) break;

		cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
		cin >> w;

		for (int i = 0; i < cnt; i++) {
			if (!strcmp(r, rp[i].getName())) {
				if (!strcmp(w,"1")) rp[i].go();
				else if (!strcmp(w, "2")) rp[i].back();
				else if (!strcmp(w, "3")) rp[i].turn();
				else if (!strcmp(w, "4")) rp[i].jump();
				else if (!strcmp(w, "5")) {
					int e;
					cout << "# ������ �������� �Է� : ";
					cin >> e;
					rp[i].charge(e);
				}
			}
		}
		cout << endl;
	}
}

void output(Robot* rp, int cnt) {
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << ". " << rp[i].getName() << " : " << rp[i].getEnergy() << endl;
	}
}
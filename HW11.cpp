#include <iostream>
#include <iomanip>
using namespace std;

class Fitness
{
private :
	int num;
	char* name;
	double weight;
	double height;

public :
	Fitness();
	Fitness(int num, char* name, double weight, double height);
	Fitness(Fitness& r);
	~Fitness();
	Fitness& operator=(Fitness& r);
	bool operator==(Fitness& r);
	void setNum(int num);
	int getNum();
	void setName(char* name);
	char* getName();
	void setWeight(double weight);
	double getWeight();
	void setHeight(double height);
	double getHeight();
	double bmi();
};
Fitness::Fitness() {
	name = new char;
	strcpy(this->name, name);
	num = 0;
	weight = 0;
	height = 0;
}
Fitness::Fitness(int num, char* name, double weight, double height) {
	this->name = new char[strlen(name) + 1];
	this->num = num;
	strcpy(this->name, name);
	this->weight = weight;
	this->height = height;
}
Fitness::Fitness(Fitness& r) {
	this->name = new char[strlen(r.name) + 1];
	this->num = r.num;
	strcpy(this->name, r.name);
	this->weight = r.weight;
	this->height = r.height;
}
Fitness::~Fitness() {
	delete[] name;
}
Fitness& Fitness::operator=(Fitness& r) {
	if (this == &r) return *this;
	delete[] name;
	this->name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	this->num = r.num;
	this->height = r.height;
	this->weight = r.weight;
	return *this;
}
bool Fitness::operator==(Fitness& r) {
	if (!strcmp(this->name, r.name) && this->height == r.height && this->weight == r.weight && this->num == r.num) return true;
	else return false;
}
void Fitness::setNum(int num) {
	this->num = num;
}
int Fitness::getNum() {
	return num;
}
void Fitness::setName(char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char* Fitness::getName() {
	return name;
}
void Fitness::setWeight(double weight) {
	this->weight = weight;
}
double Fitness::getWeight() {
	return weight;
}
void Fitness::setHeight(double height) {
	this->height = height;
}
double Fitness::getHeight() {
	return height;
}
double Fitness::bmi() {
	double bmi;
	double h = this->height / 100;
	bmi = this->weight / (h*h);
	return bmi;
}
int main() {
	Fitness* fary[100];
	int memberCnt = 0;
	int menu;
	char* n;
	n = new char[10];
	double h, w;
	int num;
	while (1) {
		cout << "1. ȸ�����" << endl << "2. ȸ����ü����" << endl << "3. ȸ�������˻�" << endl << "4. ȸ��Ż��" << endl << "5. Ư������ ȸ��" << endl << "6. ����" << endl;
		cin >> menu;
		if (menu == 1) {
			if (memberCnt > 99) {
				cout << "�ִ�� ��� ������ ȸ�� ���� 100���Դϴ�." << endl;
			}
			else {
				cout << "�̸� : ";
				cin >> n;
				cout << "������ : ";
				cin >> w;
				cout << "���� : ";
				cin >> h;
				Fitness(memberCnt+1, n, w, h);
				memberCnt++;
			}
		}
		else if (menu == 2) {
			for (int i = 0; i <= memberCnt; i++) {
				cout << "   ȸ����ȣ       ����         ������        ����" << endl;
				cout << setw(10) << fary[i]->getNum() << setw(10) << fary[i]->getName() << setw(10) << fary[i]->getHeight() << setw(10) << fary[i]->getWeight() << endl;
			}
		}
		else if (menu == 3) {
			cout << "�˻��� ȸ���� : ";
			cin >> n;
			int a = 0;
			for (int i = 0; i <= memberCnt; i++) {
				if (!strcmp(n, fary[i]->getName())) {
					cout << "   ȸ����ȣ         ������        ����";
					cout << setw(10) << fary[i]->getNum() << setw(10) << fary[i]->getHeight() << setw(10) << fary[i]->getWeight() << endl;
					a++;
				}
			}
			if (a == 0) {
				cout << "��ġ�ϴ� ȸ������ �����ϴ�." << endl;
			}
		}
		else if (menu == 4) {
			cout << "Ż���ϰ� ���� ȸ���� ȸ�� ��ȣ�� �Է��ϼ��� : " << endl;
			cin >> num;
			if (fary[num - 1]->getNum() == num) {
				delete fary[num - 1];
				memberCnt--;
			}

		}
		else if (menu == 5) {
			double b;
			for (int i = 0; i <= memberCnt; i++) {
				b = fary[i]->bmi();
				if (b > 40) {
					cout << "   ȸ����ȣ       ����         ������        ����" << endl;
					cout << "*����* " << fary[i]->getNum() << setw(10) << fary[i]->getName() << setw(10) << fary[i]->getHeight() << setw(10) << fary[i]->getWeight() << endl;
				}
				else if (b > 30) {
					cout << "   ȸ����ȣ       ����         ������        ����" << endl;
					cout << "*��*     " << fary[i]->getNum() << setw(10) << fary[i]->getName() << setw(10) << fary[i]->getHeight() << setw(10) << fary[i]->getWeight() << endl;
				}
				else if (b > 25) {
					cout << "   ȸ����ȣ       ����         ������        ����" << endl;
					cout << "*��ü��*   " << fary[i]->getNum() << setw(10) << fary[i]->getName() << setw(10) << fary[i]->getHeight() << setw(10) << fary[i]->getWeight() << endl;
				}
			}
		}
		else {
			break;
		}
	}
}
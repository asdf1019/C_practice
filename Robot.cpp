#pragma warning(disable:4886)
#include<iostream>
#include<stdlib.h>
using namespace std;
#include "Robot.h"

void Robot::errPrn()
{
	cout << "에너지 부족!!!" << endl;
}

Robot::Robot()
{
	this->name = new char(strlen("") + 1);
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::Robot(const char* name, int energy)
{
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot& r)
{
	name = r.name;
	energy = r.energy;
}

Robot::~Robot()
{
}

void Robot::go()
{
	if (this->energy >= 10) {
		cout << this->name << " 전진..." << endl;
		this->energy -= 10;
	}
	else errPrn();
}

void Robot::back()
{
	if (this->energy >= 20) {
		cout << this->name << " 후진..." << endl;
		this->energy -= 20;
	}
	else errPrn();
}

void Robot::turn()
{
	if (this->energy >= 30) {
		cout << this->name << " 턴..." << endl;
		this->energy -= 30;
	}
	else errPrn();
}

void Robot::jump()
{
	if (this->energy >= 40) {
		cout << this->name << " 점프..." << endl;
		this->energy -= 40;
	}
	else errPrn();
}

void Robot::charge(int e)
{
	if (e > 0) {
		energy += e;
		cout << this->name << " 에너지 " << e << " 충전..." << endl;
	}
	else cout << "음수값은 충전 불가능" << endl;
}

char* Robot::getName()
{
	return this->name;
}

void Robot::setName(const char * a)
{
	strcpy(this->name, a);
}

int Robot::getEnergy()
{
	return this->energy;
}

void Robot::setEnergy(int a)
{
	if (a >= 0) this->energy = a;
	else this->energy = 0;
}
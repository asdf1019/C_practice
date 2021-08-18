#include <iostream>
using namespace std;

class San {
private:
	char* name;
	int height;
public:
	San();
	San(const char*, int);
	San(const San& r);
	~San();
	void setName(char*);
	char* getName();
	void setHeight(int);
	int getHeight();
	San &operator= (const San& r);
};
San::San() {
	name = new char[100];
	strcpy(this->name,"");
	this->height = 0;
}
San::San(const char* n, int h) {
	name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	this->height = h;
}
San::San(const San& r) {
	name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->height = r.height;
}
San::~San() {
}
San& San::operator= (const San& r) {
	if (this == &r) return *this;
	delete[] name;
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	height = r.height;
	return *this;
}

void San::setName(char* n) {
	strcpy(this->name, n);
}
char* San::getName() {
	return this->name;
}
void San::setHeight(int h) {
	this->height = h;
}
int San::getHeight() {
	return this->height;
}
int main() {
	char str[100];
	San a("관악", 629);
	San b = a;

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;
	cout << "새로운 산이름을 입력 하시오 : " << endl;
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << b.getName() << " : " << b.getHeight() << "m" << endl;

	return 0;
}
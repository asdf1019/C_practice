#pragma warning(disable : 4996)

#include<iostream>
using namespace std;
#include<cstring>

class MyString {
private:
	char* str;  // 문자열을 연결할 포인터멤버
	int len;  // 문자열의 길이를 저장
public:
	MyString();  // 디폴트 생성자
	MyString(const char* cp);  // 오버로디드 생성자
	MyString(const MyString& br);  // 복사 생성자
	~MyString();  // 소멸자
	MyString& operator=(const MyString& br);  // 대입연산자 멤버함수
	MyString operator+(const MyString& br);  // 덧셈 연산자
	bool operator>(const MyString& br);  // 관계연산자 멤버함수(길이 비교)
	void operator<<(ostream& os);  // 출력연산자 멤버함수
	void operator>>(istream& is);  // 입력연산자 멤버함수
};

MyString::MyString()
{
	
}
MyString::MyString(const char* cp)
{
	
}
MyString::MyString(const MyString& br) : len(br.len)
{
	
}
MyString::~MyString()
{
	
}
MyString& MyString::operator=(const MyString& br)
{
	
}
MyString MyString::operator+(const MyString& br)
{
	
}
bool MyString::operator>(const MyString& br)
{
	
}
void MyString::operator<<(ostream& os)
{
	
}
void MyString::operator>>(istream& is)
{
	
}

ostream& operator<<(ostream& os, MyString& br);  // 출력 일반함수
istream& operator>>(istream& is, MyString& br);  // 입력 일반함수

int main()
{
	MyString ary[5];  // 객체 배열
	MyString res;  // 문자열을 모두 붙여서 저장할 객체
	int i;
	cout << "5개의 과일이름 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];  // 입력연산자 사용
	}
	cout << "첫번째와 두번째 중 긴 과일 이름 : ";
	if (ary[0] > ary[1]) {  // 관계연산자 사용
		cout << ary[0] << endl;  // 출력연산자 사용
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4]; // 덧셈연산자 사용
	cout << "모든 문자열 출력:" << res << endl;
	cout << "배열내의 문자열 출력..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}
ostream& operator<<(ostream& os, MyString& br)
{
	

}
istream& operator>>(istream& is, MyString& br)
{
	
}
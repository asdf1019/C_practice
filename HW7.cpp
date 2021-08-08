#pragma warning(disable:4996)
#include <iostream>
#include <time.h> 
#include<windows.h> 
using namespace std;
struct Goods {
	char item[50];
	int price;
	int year;
	int mon;
	int day;
	int discount;
};
struct date {
    unsigned int da_year;
    unsigned int da_mon;
    unsigned int da_day;
};
void input(Goods& s);
void selling_price(Goods& s);
void prn(const Goods& s);
int tot_days(int y, int m, int d);
int leap_check(int year);
void getdate(struct date* p);

int main()
{   
    Goods s;
    input(s);
    selling_price(s);
    prn(s);
    date stdate;
    getdate(&stdate);
    cout << endl << "** 프로그램 실행 날짜 : " << stdate.da_year << "년 " << stdate.da_mon << "월 " << stdate.da_day << "일" << endl;
}

void getdate(struct date* p)
{
    char temp[128];
    char* cp, syear[5] = "20";
    _strdate(temp);
    cp = strtok(temp, "/");
    p->da_mon = atoi(cp);
    cp = strtok(NULL, "/");
    p->da_day = atoi(cp);
    cp = strtok(NULL, "/");
    strcat(syear, cp);
    p->da_year = atoi(syear);
}
void input(Goods& s) {

    cout << "품목 입력 : ";
    cin >> s.item;
    cout << "정가 입력 : ";
    cin >> s.price;
    cout << "유통기한 입력 : ";
    cin >> s.year >> s.mon >> s.day;
}
void selling_price(Goods& s) {
    date stdate;
    getdate(&stdate);
    int sttotal = tot_days(stdate.da_year, stdate.da_mon, stdate.da_day);
    int xtotal = tot_days(s.year, s.mon, s.day);
    if (xtotal - sttotal < 0) {
        s.discount = -1;
    }
    else if (xtotal - sttotal < 4) {
        s.discount = 50;
    }
    else if (xtotal - sttotal < 11) {
        s.discount = 20;
    }
    else s.discount = 0;
}
void prn(const Goods& s) {
    if (s.discount == -1) {
        cout << "유통기한이 지났습니다!" << endl;
    }
    else {
    cout << "품명 : " << s.item << endl;
    cout << "판매가 : ";
    if (s.discount == 0) {
        cout << s.price << endl;
    }
    else cout << s.price - s.price * s.discount * 0.01 << endl;
    cout << "유통기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
    cout << "할인율 : " << s.discount << "%" << endl;
    }

}
int tot_days(int y, int m, int d) {
    int total = 0;
    int year = 1900, mon = 1, day = 1;
    while (y != year) {
        if (leap_check(year) == 1) {
            total = total + 366;
        }
        else {
            total = total + 365;
        }
        year++;
    }
    while (m != mon) {
        if (mon==1 || mon==3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {
            total = total + 31;
        }
        else {
            total = total + 30;
        }
        mon++;
    }
    total += (d - day);
    return total;
}
int leap_check(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else return 0;
        }
        else return 0;
    }
    else return 0;
}
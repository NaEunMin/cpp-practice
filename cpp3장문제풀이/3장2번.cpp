// 이 전 코드는 month가 2자리이면 코드실행이 안되어 지금의 코드로 변경함
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Date {
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	Date(string ymd);
	int getYear();
	int getMonth();
	int getDay();
	void show();
};
Date::Date(string ymd) {
	char NewYMD[11];
	strcpy(NewYMD, ymd.c_str());   //c.str()함수는 string클래스의 문자열을 char* 형태의 문자열로 변환시켜주는 함수이다.
	year = stoi(strtok(NewYMD, "/")); //strtok는 문자열을 해당 문자를 기준으로 잘라준다. 자르고 남은 문자열을 계속 자르겠다면 
	month = stoi(strtok(NULL, "/"));  //문자열 매개변수를 NULL로 입력을 해준다.
	day = stoi(strtok(NULL, "/"));
}

int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}
int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/12/15");
	independenceDay.show();
	cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

stoi()함수가 숫자형태가 아닌 것이 있으면 빼고 그 앞까지 정수로 바꿔주는듯함.
substr(a,b)은 a=추출시작인덱스, b=추출끝인덱스 b는 추출대상이 아님.

*/

#include <iostream>
#include <string>
using namespace std;

class Date{
    private:
    int year;
    int month;
    int day;
    
    public:
    Date(int year, int month, int day);
    Date(string YMD);
    int getYear();
    int getMonth();
    int getDay(); 
    void show();
};

Date::Date(int x, int y, int z)
{
    year = x;
    month = y;
    day = z;
}

Date::Date(string YMD)
{
    year = stoi(YMD);
	month = stoi(YMD.substr(5,6));
	day = stoi(YMD.substr(7,9));
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::show(){
    cout << year << "년" << month << "월" << day << "일" <<'\n';
}
int main(){
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");
    independenceDay.show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << '\n';
    return 0;
}

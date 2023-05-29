/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

라이브러리 헤더파일은 <헤더파일>, 사용자가 만든 헤더파일은 "헤더파일"
클래스 선언부는 클래스이름.h    클래스 구현부는 클래스이름.cpp

*/

#include <iostream>

using namespace std;

#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"
/*
class Add{
    int a;
    int b;
    public:
    void setValue(int x, int y){
     a=x;
     b=y;
    }
    int calculate(){
        return a+b;
    }
};

class Sub{
    int a;
    int b;
    public:
    void setValue(int x, int y){
     a=x;
     b=y;
    }
    int calculate(){
        return a-b;
    }
};

class Mul{
    int a;
    int b;
    public:
    void setValue(int x, int y){
     a=x;
     b=y;
    }
    int calculate(){
        return a*b;
    }
};

class Div{
    int a;
    int b;
    public:
    void setValue(int x, int y){
     a=x;
     b=y;
    }
    int calculate(){
        return a/b;
    }
};
*/
int main()
{
    Add a;
    Sub s;
    Mul m;
    Div d;
    int num1,num2;
    char ch;
    while(true){
    cout << "두 정수와 연산자를 입력하세요>>";
    cin >> num1 >> num2 >> ch;
    if(ch=='+')
    {
        a.setValue(num1, num2);
        cout << a.calculate();
    }
        if(ch=='-')
    {
        s.setValue(num1, num2);
        cout << s.calculate();
    }
        if(ch=='*')
    {
        m.setValue(num1, num2);
        cout << m.calculate();
    }
        if(ch=='/')
    {
        d.setValue(num1, num2);
        cout << d.calculate();
    }
    cout << endl;
}
    return 0;
}

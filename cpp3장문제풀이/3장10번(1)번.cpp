/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

함수가 간단해서 자동인라인(선언부에 함수 구현)을 사용해봄.

*/

#include <iostream>

using namespace std;

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

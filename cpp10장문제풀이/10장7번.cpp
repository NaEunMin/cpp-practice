/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

컴파일 오류의 이유는 "객체간의 크기를 비교하지 못하기 때문이다."

*/

#include <iostream>

using namespace std;

class Circle {
    int radius;
    public:
    Circle(int radius = 1){ this->radius = radius; }
    int getRadius() {return radius;}
};

template <class T>
T bigger(T a, T b){
    if(a > b) return a;
    else return b;
}

Circle bigger(Circle a, Circle b){  //클래스의 크기를 비교하지 못해서 생기는 오류이다. 
    if(a.getRadius()>b.getRadius()) return a; //그래서 Circle bigger()중복함수를 작성해서 객체가 매개변수로 들어가면 작동될 함수를 작성해줌.
    else return b;
}

int main()
{
    int a = 20, b = 50, c;
    c = bigger(a,b);
    cout << "20과 50중 큰 값은 " << c << endl;
    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);
    cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
    
    return 0;
}

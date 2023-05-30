/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

매개변수와 인수에 대한 고정관념을 버려야한다.
반드시 NamedCircle안에 radius라는 변수가 있어야 생성자매개변수에 radius넣을수 있는 그런 개념이 아니다.
명시적으로 기본클래스의 생성자를 지정해주고 그 생성자의 매개변수인 radius에 값을 넘겨주기위해 사용하는 것이다.

*/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    Circle(int radius=0) {
        this->radius = radius;
    }
    int getRadius(){
        return radius;
    }
    void setRadius(int radius){
        this->radius = radius;
    }
    double getArea(){
        return 3.14*radius*radius;
    }
};

class NamedCircle : public Circle{
    string name;
    public:
    NamedCircle(int radius, string name) : Circle(radius){
        this->name = name;
    }
    void show(){
        cout << "반지름이 " << getRadius() << "인" << name;
    }
};

int main()
{
 NamedCircle waffle(3, "waffle");
 waffle.show();

    return 0;
}

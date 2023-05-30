/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

***다운캐스팅***
기본클래스의 포인터가 가르키는 객체를 파생클래스 포인터로 가르키는 것을 말한다. 
-사용이유-
업캐스팅을 하면 기본클래스의 멤버만 접근이 가능하므로 모든클래스의 멤버에 접근하기위해 다운캐스팅을 해준다.

8장 상속, 9장 가상 함수와 추상클래스를 집중도있게 공부해야함을 알려주는 문제.

***업캐스팅과 다운캐스팅 비교***
-업캐스팅 : 기본클래스포인터->파생클래스 객체
-다운캐스팅 : [기본클래스포인터->파생클래스 객체]의 형태에서 [파생클래스포인터->파생클래스 객체]의 형태로 형변환 

***연산자 중복, 오버라이딩***
연산자 중복: 문제상황과 같이 >를 다른 방식으로 사용하고 싶을때 문제코드와 같이 연산자를 재정의하여 사용할 수 있다.
오버라이딩 : 기본클래스의 가상함수를 파생클래스에서 이름, 매개변수타입과 개수, 리턴 타입까지 완벽히 같은 원형으로 재작성하는 것.
                     --> 기본클래스에 구현된 가상함수를 무시하고 무조건 파생클래스의 오버라이딩된 함수가 먼저 실행된다.

*/

#include <iostream>

using namespace std;

class Comparable{
    public:
    virtual bool operator > (Comparable& op2) = 0;
    virtual bool operator < (Comparable& op2) = 0;
    virtual bool operator == (Comparable& op2) = 0;
};


class Circle : public Comparable{
    int radius;
    public:
    Circle(int radius = 1){ this->radius = radius; }
    int getRadius() {return radius;}
    bool operator > (Comparable& op2){
        Circle *p = (Circle*)&op2;   //다운캐스팅
        if(this->radius > p->getRadius()) return true;
        else return false;
    }
    bool operator < (Comparable& op2){
        Circle *p = (Circle*)&op2;  //다운캐스팅
        if(this->radius < p->getRadius()) return true;
        else return false;
    }
    bool operator == (Comparable& op2){
        Circle *p = (Circle*)&op2;  //다운캐스팅
        if(this->radius==p->getRadius()) return true;
        else return false;
    }
};

template <class T>
T bigger(T a, T b){
    if(a > b) return a;
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

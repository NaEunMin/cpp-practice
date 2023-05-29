/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

기본 생성자의 특징-> 기본 생성자가 자동으로 생성되지 않는 경우: 생성자가 하나라도 선언된 클래스의 경우
객체는 생성 시  생성자가 꼭 필요한데 Circle tmp 생성할때 위 특징으로 인해 기본 생성자가 자동생성되지않았다. 이런 디테일을 놓치지말아야할듯.
위임생성자: 중복된 초기화코드를 하나의 생성자로 몰고, 다른 생성자에서 목표 생성자 호출(코드 간소화를 할 수 있는 장점이 있다.) 이런 디테일도 알아두면 좋을 것 같다.
주석으로 위임생성자로 클래스 생성하는 코드 적어두었다.

*/

#include <iostream>

using namespace std;

class Circle{
  int radius;
  public:
  Circle(){radius = 1;}
  Circle(int radius){this->radius=radius;}
  void swap(Circle& c1,Circle& c2);
  int getRadius(){return radius;}
};

/*class Circle {
	int radius;
public:
	Circle():Circle(1) {}
	Circle(int r) { this->radius = r; }
void Circle::swap(Circle &c1,Circle &c2){
    Circle tmp;
    tmp=c1;
    c1=c2;
    c2=tmp;
}
*/

int main()
{
    Circle circle1(1);
    Circle circle2(2);
    cout << circle1.getRadius() << ' ' << circle2.getRadius() << endl;
    
    swap(circle1, circle2);
    
    cout << circle1.getRadius() << ' ' << circle2.getRadius() << endl;
    return 0;
}

/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

너무 함수 구현만 생각하니 기본을 다하지 못했던 문제.
단항연산자 구현 할때(멤버함수) 당연히 객체 자신을 변경할 것이다. 그럼 매개변수를 안주는 것이다. 그리고 객체자신을 리턴해줘야한다.
후위연산자 구현 할때는 전위연산자와 구분하기 위해 int x처럼 아무거나 넣어주는 것을 잊지 않아야한다.
외부함수로 구현할때는 매개변수에 객체를 넘겨줘야한다. 객체원본을 바꾸어야 할때는 참조에 의한 호출을 사용할 것. -----------강조하고 또 강조한다.
외부함수는 매개변수에 객체를 받아와서 실행하기에 ex) c.radius처럼 c. 이런걸 잊으면 안된다.-----------------굉장히 기본적인걸 실수했다.

*/

#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	Circle& operator ++ ();
	Circle operator ++ (int x);
	//friend Circle& operator ++(Circle& op);
	//friend Circle operator ++ (Circle& op, int x);
};
Circle& Circle::operator++() {
	radius++;
	return *this;
}
Circle Circle::operator++(int x) {
	Circle tmp = *this;
	radius++;
	return tmp;
}
/*
Circle& operator ++(Circle& op) {
	op.radius++;
	return op;
}
Circle operator ++(Circle& op, int x) {
	Circle tmp = op;
	op.radius++;
	return tmp;
}*/
int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}

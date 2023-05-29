/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

값에 의한 호출로 main문의 a는 변하지 않는다.

*/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    Circle(int radius=0){
        this->radius = radius;
    }
    void show() {
        cout << "radius = " << radius << " 인 원" << endl;
    }
    
    friend Circle operator + (int r, Circle c);

};

Circle operator + (int r, Circle c){
    c.radius += r;
    return c;
}

int main()
{
    Circle a(5), b(4);
    b = 1 + a;
    a.show();
    b.show();

    return 0;
}

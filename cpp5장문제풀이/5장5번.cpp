/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    Circle(int r){radius=r;}
    int getRadius() {return radius;}
    void setRadius(int r){radius = r;}
    void show() { cout << "반지름이 " << radius << "인 원" << endl;}
};

void increaseBy(Circle &a, Circle b){
    int r = a.getRadius()+b.getRadius();
    a.setRadius(r);
}

int main()
{
    Circle x(10), y(5);
    increaseBy(x,y);
    x.show();

    return 0;
}

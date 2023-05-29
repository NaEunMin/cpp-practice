/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

매개 변수의 순서를 확실하게 알게해준 문제

*/

#include <iostream>

using namespace std;

class Color{
    int r;
    int g;
    int b;
    public:
    Color(int r=0, int g=0, int b=0){
        this->r = r;
        this->g = g;
        this->b = b;
    }
    //Color operator + (Color op);
    //bool operator == (Color op);
    
    friend Color operator + (Color op1, Color op2);
    friend bool operator == (Color op1, Color op2);
    
    void show(){
        cout << r << ' ' << g << ' ' << b << endl;
    }
    
};
/* 클래스 멤버함수 구현***
Color Color::operator + (Color op){
    Color tmp;
    tmp.r = this->r + op.r;
    tmp.g = this->g + op.g;
    tmp.b = this->b + op.b;
    
    return tmp; 
}

bool Color::operator == (Color op){
    if(r==op.r && g==op.g && b==op.b)
    return true;
    else
    return false;
}*/

Color operator + (Color op1, Color op2){
    Color tmp;
    tmp.r = op1.r + op2.r;
    tmp.g = op1.g + op2.g;
    tmp.b = op1.b + op2.b;
    
    return tmp; 
}

bool operator == (Color op1, Color op2){
    if(op1.r==op2.r && op1.g==op2.g && op1.b==op2.b)
    return true;
    else
    return false;
}

int main()
{
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue;
    c.show();
    
    Color fuchsia(255, 0, 255);
    if(c == fuchsia)
    cout << "보라색 맞음";
    else
    cout << "보라색 아님";

    return 0;
}

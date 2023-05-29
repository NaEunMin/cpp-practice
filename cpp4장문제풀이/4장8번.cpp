/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

공책필기에도 적어놨듯이 동적으로 할당받는다고 완전 다른 개념이 아니다. 사용법 근본은 우리가 평소에 쓰던 정적배열과 같다.
p = new Circle[num]이면 포인터변수p가 평소에 우리가 쓰던 객체이름을 대신한다고 생각하자. 그럼 편한 것 같다.

*/

#include <iostream>

using namespace std;

class Circle{
    int radius;
    public:
    void setRadius(int radius);
    double getArea();
};

void Circle::setRadius(int radius){
    this->radius = radius;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main()
{
    Circle *p;
    int rad;
    int num;
    cout << "원의 개수 >> ";
    cin >> num;
    p = new Circle[num];
    for(int i=0;i<num;i++){
        cout << "원 " << i+1 << "의 반지름 >> ";
        cin >> rad;
        p[i].setRadius(rad);
    }
    cout << endl;
    int count=0;
    for(int i=0;i<num;i++){
        if(100<p[i].getArea()){
           count++;
        }
    }
    cout << "면적이 100보다 큰 원은 " << count <<"개 입니다.";
    return 0;
}





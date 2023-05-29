/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

객체 포인터사용해서 포인터변수로 멤버함수 사용할때 ->연산자 사용할것.

*/

#include <iostream>

using namespace std;

class Color{
    int red, green, blue;
    public:
    Color(){ //기본생성자
        red = green = blue = 0;
    }
    Color(int r, int g, int b){ //생성자
        red = r; green = g; blue = b;
    }
    void setColor(int r, int g, int b){ //색깔 세팅
        red = r; green = g; blue = b;
    }
    void show(){ //색 보여주기
        cout << red << ' ' << green << ' ' << blue << endl;
    }
};

int main()
{
    Color screenColor(255,0,0); //빨간색의 screenColor객체 생성
    Color *p;
    p=&screenColor;
    p->show();
    Color colors[3];
    p=colors;
    p[0].setColor(255,0,0);
    p[1].setColor(0,255,0);
    p[2].setColor(0,0,255);
    for(int i=0;i<3;i++){
        p[i].show();
    }
    return 0;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

상속을 많이 연습해야겠구나라고 생각한 문제.
아직 상속에 대한 시각이 좁다.

*/

#include <iostream>

using namespace std;

class Point{
    int x, y;
    public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){ return x; }
    int getY(){ return y; }
    protected:
    void move(int x, int y){
        this->x = x;
        this->y = y;
    }
};

class ColorPoint : public Point{
    string Color;
    public:
    ColorPoint(int x, int y, string Color) : Point(x, y){
        this->Color = Color;
    }
    void setColor(string Color){
        this->Color = Color;
    }
    string getColor(){
        return Color;
    }
    void setPoint(int x, int y){
        move(x,y);
    }
    void show(){
        cout << Color << "색으로 (" << getX() << "," << getY() << ")" << "에 위치한 점입니다.";
    }
};
int main()
{
   ColorPoint cp(5, 5, "RED");
   cp.setPoint(10, 20);
   cp.setColor("BLUE");
   cp.show();
    return 0;
}

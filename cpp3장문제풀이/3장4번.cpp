/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class CoffeeMachine{
    private:
    int coffee;
    int water;
    int sugar;
    
    public:
    CoffeeMachine(int coffee,int water,int sugar);
    void drinkEspresso();
    void drinkAmericano();
    void drinkSugarCoffee();
    void show();
    void fill();
};

CoffeeMachine::CoffeeMachine(int a, int b, int c){
    coffee=a;
    water=b;
    sugar=c;
}

void CoffeeMachine::drinkEspresso(){
    coffee=coffee-1;
    water=water-1;
}

void CoffeeMachine::drinkAmericano(){
    coffee=coffee-1;
    water=water-2;
}

void CoffeeMachine::drinkSugarCoffee(){
    coffee=coffee-1;
    water=water-2;
    sugar=sugar-1;
}

void CoffeeMachine::show(){
    cout<<"커피 머신 상태, "<<"커피:"<<coffee<<" 물:"<<water<<" 설탕:"<<sugar<<'\n';
} 

void CoffeeMachine::fill(){
    coffee=10;
    water=10;
    sugar=10;
}
int main()
{
    CoffeeMachine java(5,10,3);//커피량5,물량10,설탕3으로 초기화
    java.drinkEspresso();//커피1, 물1 소비
    java.show();//현재머신상태 출력
    java.drinkAmericano();//커피1,물2소비
    java.show();
    java.drinkSugarCoffee();//커피1,물2,설탕1소비
    java.show();
    java.fill();//커피10,물10,설탕10으로 채우기
    java.show();
    return 0;
}

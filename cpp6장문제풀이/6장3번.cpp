/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
/*
int big(int num1, int num2){
    int max=100;
    if(num1>num2){
        int big = num1;
        if(big<max)
        return big;
        else
        return max;
    }
    else{
        int big = num2;
        if(big<max)
        return big;
        else
        return max;
    }
}*/
 //디폴트 매개변수 사용시 위 함수 주석처리 후 아래 int max -> int max = 100
int big(int num1, int num2, int max=100){ 
    if(num1>num2){
        int big = num1;
        if(big<max)
        return big;
        else
        return max;
    }
    else{
        int big = num2;
        if(big<max)
        return big;
        else
        return max;
    }
}
int main(){
    int x = big(3,5);
    int y = big(300,60);
    int z = big(30,60,50);
    cout << x << ' ' << y << ' ' << z << endl;
    return 0;
}



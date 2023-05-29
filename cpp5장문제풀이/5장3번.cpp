/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

2번의 사소한 디테일 생각에 별 중요하지도 않은 노력을 함수구현할때 해보았다.

*/

#include <iostream>

using namespace std;

void combine(string &text1, string &text2, string &text3){
    text3 = text1 + " " + text2;
}
int main()
{
    string text1("I love you"), text2("very much");
    string text3;
    combine(text1, text2, text3);
    cout << text3;

    return 0;
}

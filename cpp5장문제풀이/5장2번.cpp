/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

사소한 디테일인데 num=num/2를 간단하게 num/=2 이렇게 작성하는 디테일을 알아둬도 좋을 것 같다.

*/

#include <iostream>

using namespace std;

void half(double &num){
    num=num/2; //num/=2;
}

int main()
{
   double n=20;
   half(n);
   cout << n;

    return 0;
}

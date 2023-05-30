/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

2번과 비슷한 느낌이다.

*/

#include <iostream>

using namespace std;

template <class T>
bool search(T target, int x[], int size){
    for(int i=0; i<size; i++){
        if(x[i]==target)
        return true;
    }
    return false;
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    if(search(100, x, 5)) cout << "100이 배열 x에 포함되어 있다";
    else cout << "100이 배열 x에 포함되어 있지 않다.";

    return 0;
}

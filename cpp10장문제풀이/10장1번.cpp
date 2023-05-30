/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template <class T>
int biggest(T x[], int size){
    T max=x[0];
    for(int i=1; i<size; i++){
        if(max<x[i])
        max = x[i];
    }
    return max;
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    cout << biggest(x, 5) << endl;

    return 0;
}

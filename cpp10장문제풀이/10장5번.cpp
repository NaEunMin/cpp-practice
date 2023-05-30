/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

int c[] = concat() 하면 c배열크기 지정해주라고해서 int *c로 처리해보았다.

*/

#include <iostream>

using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb){
    T *tmp;
    tmp = new T[sizea+sizeb];
    for(int i=0; i<sizea; i++){
        tmp[i] = a[i];
    }
    for(int i=0; i<sizeb; i++){
        tmp[i+sizea] = b[i]; 
    }
    return tmp;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};
    int *c = concat(a, 5, b, 5);  //int c[] 로 하니까 변수 크기 필요하다해서 포인터로 처리함.
    for(int i=0; i<10; i++){
        cout << c[i] << " ";
    }
    return 0;
}

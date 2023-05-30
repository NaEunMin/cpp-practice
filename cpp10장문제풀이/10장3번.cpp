/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

4장 문자열 뒤집기의 "사이즈가 홀수 일때 짝수일때"를 이용했다.
홀수 : 양쪽씩 계속 바꾸면 가운데가 남는데 가운데는 안바꿔도됨을 이용.
짝수 : 어차피 다 바꿔야함.
==> 사이즈를 size/2를 해서 for문을 돌리면된다.    //한번에 두자리씩 바뀌니까 size의 절반반큼만 실행하면됨.

    T tmp;
    for(int i=0; i<size/2; i++){
        tmp = p[i];
        p[i] = p[size-1-i];    // i를 빼주는 이유는 i번째 인덱스를 교환하기 위해 뒤에서 i만큼 떨어져있는 인덱스와 교환해야하기 때문 ***배열을 뒤집어야 하니까***
        p[size-1-i] = tmp;
    }

*/

#include <iostream>

using namespace std;

template <class T>
void reverseArray(T *p, int size){
    T tmp;
    for(int i=0; i<size/2; i++){
        tmp = p[i];
        p[i] = p[size-1-i];
        p[size-1-i] = tmp;
    }
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x,5);
    for(int i=0; i<5; i++) cout << x[i] << ' ';
    return 0;
}

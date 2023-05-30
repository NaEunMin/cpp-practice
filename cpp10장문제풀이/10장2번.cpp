/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

bool eqaulArray(T x[], T y[], int size) 함수 작성시 
for(int i=0; i<size; i++){
if(x[i]==y[i])
return true;
else return false;
}
이렇게 작성하면 실행은 되는데 오류메시지가 나온다. 리턴값을 제대로 전달하지 않아서 생기는 메시지이다. 또한 알고리즘도 문제가 있어 첫번째 원소로만 판단하게 된다.

bool equalArrays(T x[], T y[], int size){
    for(int i=0; i<size; i++){
        if(x[i]!=y[i])
        return false;
    }
    return true;
}
이렇게 작성되면 정답이다.
for문안에서는 배열이 서로 같으면 패스해서 끝까지 같으면 true를 리턴해주고  다르면 바로 false를 리턴해서 함수를 종료시킨다.

*/

#include <iostream>

using namespace std;

template <class T>
bool equalArrays(T x[], T y[], int size){
    for(int i=0; i<size; i++){
        if(x[i]!=y[i])
        return false;
    }
    return true;
}
int main()
{
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {1, 10, 100, 5 ,4};
    if(equalArrays(x,y, 5)) cout << "같다";
    else cout << "다르다";
    
    cout << endl;
    double a[] = {1.1, 2.2};
    double b[] = {3.3, 4.4};
    
    if(equalArrays(a,b,5)) cout << "같다";
    else cout << "다르다";

    return 0;
}

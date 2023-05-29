/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

아직 자료구조공부를 안해서 통상적으로 스택에서 어떤 변수를 사용하는지 그런걸 몰라서 배열느낌으로 풀었다.
다른분들이 작성한 스택을 이용한 코드를 보니까 코드돌아가는 구조와 알고리즘은 내가 작성한것과 같았다.

***** 보통 스택에서는 top이라는 변수를 사용하는 것 같다. (배열에서 size의 느낌)

*/

#include <iostream>

using namespace std;

class Stack{
    int *num_Array;
    int size;
    public:
    Stack(int size=0){
        this->size = size;
        num_Array = new int[size];
    }
    
    ~Stack(){ delete [] num_Array;}
    
    Stack& operator << (int num){
        num_Array[size] = num;
        size++;
        return *this;
    }
    
    bool operator !(){
        if(size == 0)
        return true;
        else
        return false;
    }
    
    int operator >> (int& num){
        num = num_Array[size-1]; //위에 <<연산자함수에서 마지막에 size가 1증가
        size--;                  //그래서 마지막에 -1해줌.
        return num;
    }
};

int main()
{
    Stack stack;
    stack << 3 << 5 << 10;
    while(true) {
        if(!stack) 
        break;
        int x;
        stack >> x;
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}

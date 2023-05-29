/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class MyVector{
    int *mem;
    int size;
    public:
    MyVector();
    MyVector(int n, int val);
    ~MyVector(){
        delete [] mem;
    }
    void show(){
        for(int i=0; i<size; i++){
            cout << mem[i] << ' ';
        }
    }
};

MyVector::MyVector(int val, int n=100){
    mem = new int[n];
    size = n;
    for(int i=0; i<size; i++)
    mem[i]=val;
}

int main(){
    MyVector myvector(1,10);
    myvector.show();
}



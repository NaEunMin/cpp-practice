/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

소멸자에서 delete [] p; 해주는 디테일 
*** 동적으로 할당 받았다면 반환을 해주어야함을 잊지말자.

*/

#include <iostream>

using namespace std;

class Sample{
    int *p;
    int size;
    public:
    Sample(int n){
        size = n;
        p = new int[n];
    }
    void read();
    void write();
    int big();
    ~Sample();
};

void Sample::read(){
    for(int i=0;i<size;i++){
        cin >> p[i];
    }
}

void Sample::write(){
    for(int i=0;i<size;i++){
        cout << p[i] << ' ';
    }
    cout << endl;
}

int Sample::big(){
    int max=0;
    for(int i=0; i<size;i++){
        if(max<p[i])
        {
            max=p[i];
        }
    }
    return max;
}

Sample::~Sample(){
    delete [] p;
}
int main()
{
    Sample s(10);
    s.read();
    s.write();
    cout << "가장 큰 수는 " << s.big() << endl;
    return 0;
}

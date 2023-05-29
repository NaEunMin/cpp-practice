/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

5번 짝수로 출력되게 하는 문제
if문에서 return n, return n-1 이렇게 짝수구별했는데 do while n%2==1 이렇게 걸어서 짝수 나올때까지 해도될듯함.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class EvenRandom{
  
  public:
  EvenRandom();
  int next();
  int nextInRange(int num1,int num2);
};

EvenRandom::EvenRandom(){
    srand((unsigned)time(0));
}
int EvenRandom::next(){
   
    int n=rand();
    if(n%2==0)
    return n;
    else if(n%2==1)
    return n-1;
}

int EvenRandom::nextInRange(int a, int b){
    int n=rand()%(b-a+2)+a;
    if(n%2==0)
    return n;
    else if(n%2==1)
    return n-1;
}

int main()
{
    EvenRandom r;
    cout << "--0에서 " << RAND_MAX << "까지의 랜덤 짝수정수10개--" << '\n';
    for(int i=0; i<10; i++){
        int n=r.next(); //0에서 RAND_MAX(32767) 사이의 랜덤한 짝수정수
        cout << n << ' ';
    }
    cout << '\n' << '\n' << "--2에서 " << "10 까지의 랜덤 짝수정수 10개 --" << '\n';
    for(int i=0; i<10; i++){
        int n=r.nextInRange(2,10);//2에서10사이의 랜덤한 짝수정수
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}

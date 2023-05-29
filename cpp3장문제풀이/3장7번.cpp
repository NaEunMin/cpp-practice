/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

무한루프를 해주는이유:     int n=rand()%(end-start+1)+start;  if(n%2==even_or_odd) return n; 이문장이
만약 홀수를 뽑는함수다. 그러면 짝수가 나오면 그냥 함수종료하고 아무것도안됨. 그래서 무한루프로 홀수나올때까지 함수작동하게 해주는 것.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SelectableRandom{
  private:
  int start;
  int end;
  
  public:
  SelectableRandom();
  int next(int even_or_odd);
  int nextInRange(int start, int end, int even_or_odd);
};
  SelectableRandom::SelectableRandom(){
    srand((unsigned)time(0));
    start=0;
    end=RAND_MAX;
  }
  
int SelectableRandom::next(int even_or_odd){
    while(true){
   int n=rand()%RAND_MAX+1;
   if(n%2==even_or_odd)
   return n;
    }
}

int SelectableRandom::nextInRange(int start, int end, int even_or_odd){
    while(true){
    int n=rand()%(end-start+1)+start;
    if(n%2==even_or_odd)
    return n;
    }
}



int main()
{
    SelectableRandom r;
    cout << "--0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수10개--" << '\n';
    for(int i=0; i<10; i++){
        int n=r.next(0); //0에서 RAND_MAX(32767) 사이의 랜덤한 짝수정수
        cout << n << ' ';
    }
    cout << '\n' << '\n' << "--2에서 " << "9 까지의 랜덤 홀수 정수 10개 --" << '\n';
    for(int i=0; i<10; i++){
        int n=r.nextInRange(2,9,1);//2에서10사이의 랜덤한 짝수정수
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}




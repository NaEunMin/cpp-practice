/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

저번에도 공부한 내용임-> 알파벳 랜덤 출력 ex) char ch = 'a'+rand()%26;
공부하면서 안 사실-> 실수 랜덤 출력(0~1) (double)rand()/Rand_MAX

*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random{
    public:
    static void seed(){
        srand((unsigned)time(0));
    }
    static int nextInt(int min=0, int max=32767){
        return rand()%32767+min;
    }
    static char nextAlphabet(){
        return 'a'+rand()%26;
    }
    
    static double nextDouble(){
        return (double)rand()/RAND_MAX;
    }
};

int main()
{
    Random random;
    Random::seed();
    cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다.\n";
    for(int i=0; i<10; i++){
        cout << Random::nextInt() << ' ';
    }
    cout << endl;
    
    cout << "알파벳을 랜덤하게 출력합니다.\n";
    for(int i=0; i<10; i++){
        cout << Random::nextAlphabet() << ' ';
    }
    cout << endl;
    
    cout << "랜덤한 실수를 10개 출력합니다.\n";
    for(int i=0; i<10; i++){
        cout << Random::nextDouble() << ' ';
    }
    cout << endl;
    return 0;
}

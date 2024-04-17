/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

저번에도 공부한 내용임-> 알파벳 랜덤 출력 ex) char ch = 'a'+rand()%26;
공부하면서 안 사실-> 실수 랜덤 출력(0~1) (double)rand()/Rand_MAX
rand()는 정수 0~32767중 랜덤 생성한다는걸 반드시 기억해야한다.
%는 나누는 수 미만의 나머지만 나오는 구조를 이용하여 nextInt함수의 return 식이 나오는 구조이다
ex) rand() % 해당 수 전까지 + 해당 수 부터
실수 랜덤 생성은 rand()와 /의 이해가 필요하다.
rand()는 위 처럼 0~32767중 생성을 한다.
그렇다면 rand() / 32767을 하면 몫이 0 아니면 1이 나올 수 밖에 없는 구조이다,
(double)rand()를 해주면 rand()에서 32767이 나오면 랜덤 생성해서 1이 나오는거고 32767이 나오지 않는다면
몫이 0이고 double로 형변환을 하였기 때문에 계속 계산을 진행하여 0뒤 소수점이 나오는 구조이다.
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
        return rand()%max+min;
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
    Random random; //이 코드는 써도 그만 안써도 그만
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

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


/*

클래스 선언부에서 멤버함수원형 작성할때 진짜로 진짜로 함수리턴자료형이나 매개변수 빼먹었는지 확인해야한다.... 이걸 계속 실수하고 또 찾다가 시간날려먹는다.
cin.get(ch); 이걸 사용했는데 cin을 사용하면 계속 엔터만 치게되고 문자한개만 딱 받으려면 cin.get(ch); 함수를 사용해야하는 것 같다. 
cin은 엔터치면 종료로 간주하는데 cin.get()은 엔터도 문자로 간주하기 때문이다.
좀 코드가 난해하긴해서 player1과 player2의 턴을 구분해주는 함수 구현하면 코드가 깔끔할 것 같다.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Player{
    string name;
    public:
    void setName(string name){this->name=name;}
    string getName(){return name;}
};

class GamblingGame{
    Player player[2];
    public:
    void run();
};


void GamblingGame::run(){
    string name;
    char ch;
    int num_array[3];
    cout << "*****갬블링 게임을 시작합니다.*****\n";
    cout << "첫번째 선수 이름>>";
    cin >> name;
    player[0].setName(name);
    cout << "두번째 선수 이름>>";
    cin >> name;
    player[1].setName(name);
    

    while(true){
        //1player
        srand((unsigned)time(0));
        cout << player[0].getName() << ":<Enter>"; //엔터키 받는 코드
        while(true){
            cin.get(ch);
            if(ch=='\n')
            break;
        }
        cout << endl;
        
        for(int i=0;i<3;i++){ //랜덤한 정수 3개 생성
        num_array[i]=rand()%3;
    }
        for (int i=0;i<3;i++){ //랜덤정수출력
            cout << '\t' << num_array[i] << '\t';
        }
        if(num_array[0]==num_array[1]&&num_array[1]==num_array[2]){
            cout << player[0].getName() <<"님 승리!";
            break;
        }
        else{
            cout << "아쉽군요!" <<endl;
        }
        ///2player///////////////////////////////////////////////////////////
        cout << player[1].getName() << ":<Enter>"; //1player와 같은 구조의 코드
        while(true){
            cin.get(ch);
            if(ch=='\n')
            break;
        }
        cout << endl;
        for(int i=0;i<3;i++){ 
        num_array[i]=rand()%3;
    }
        for (int i=0;i<3;i++){
            cout << '\t' << num_array[i] << '\t';
        }
        if(num_array[0]==num_array[1]&&num_array[1]==num_array[2]){
            cout << player[1].getName() <<"님 승리!";
            break;
        }
        else{
            cout << "아쉽군요!" << endl;
        }
    }
}


int main()
{
    GamblingGame gamblinggame;
    gamblinggame.run();
    return 0;
}

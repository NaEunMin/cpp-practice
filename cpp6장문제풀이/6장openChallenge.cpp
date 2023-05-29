/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

/*

지역변수를 함수를 통해 바꾸고 싶다면 '주소에 의한 호출'이나 '참조에 의한 호출'을 사용해야할 것 이다.
static 멤버는 non-static을 접근 못한다고 했다.
하지만 static 멤버함수 내에서 다른 클래스 객체생성하면 그 객체의 non-static 멤버 접근가능한 것 같다.

*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Person{
    string name;
    int playerAnswer;
    public:
    Person(string name){this->name = name;}
    string getName(){return name;}
    void setplayerAnswer(int answer){playerAnswer=answer;}
    int getplayerAnswer(){return playerAnswer;}
};

class UpAndDownGame{
    public:
  static void GameStart();
  static void Hint(int answer, int randomNumber, int &min, int &max);
};



void UpAndDownGame::Hint(int answer, int randomNumber, int &min, int &max){
    if(answer>randomNumber){
        max=answer;
        cout << "답은" << min << "과" << max << "사이에 있습니다." << endl;
    }
    else if(answer<randomNumber){
        min=answer;
        cout << "답은" << min << "과" << max << "사이에 있습니다." << endl;
    }
    
}

void UpAndDownGame::GameStart(){
    int min=0;
    int max=99;
    int answer;
    srand((unsigned)time(0));
    int randomNumber = rand()%100;
    cout << "UP & DOWN 게임을 시작합니다." << endl;
    cout << "답은" << min << "과" << max << "사이에 있습니다." << endl;
    Person player1("김인수");
    Person player2("오은경");
    
    while(true){
    cout << player1.getName() << ">>";
    cin >> answer;
    player1.setplayerAnswer(answer);
    
    UpAndDownGame::Hint(answer, randomNumber, min, max);
    
    if(player1.getplayerAnswer()==randomNumber){
        cout << player1.getName() << "가 이겼습니다." << endl;
        break;
    }
    cout << player2.getName() << ">>";
    cin >> answer;
    player2.setplayerAnswer(answer);
    
    UpAndDownGame::Hint(answer, randomNumber, min, max);
    

    if(player2.getplayerAnswer()==randomNumber){
         cout << player2.getName() << "가 이겼습니다." << endl;
         break;
    }
}
}

int main()
{
    UpAndDownGame::GameStart();

    return 0;
}

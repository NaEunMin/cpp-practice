/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

*** map에 원소 삽입하기 ***
m.insert(make_pair(키 , 값));

*** map에 키를 이용하여 값 알아내기 ***
m[키] ---> 값을 알려줌.

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int menu;
    string name;
    int score;
    map<string, int> m;
    cout << "***** 점수 관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
    while(true){
    cout << "입력:1, 조회:2, 종료:3 >>";
    cin >> menu;
    if(menu == 1){
        cout << "이름과 점수>>";
        cin >> name >> score;
        m.insert(make_pair(name, score));
    }
    else if(menu == 2){
        cout << "이름>>";
        cin >> name;
        cout << name << "의 점수는 " << m[name] << endl;
    }
    else if(menu == 3){
        cout << "프로그램을 종료합니다...";
        return 0;
    }
}//while문

    return 0;
}

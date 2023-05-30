/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int menu;
    string name;
    string password;
    map<string, string> m;
    cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;
    while(true){
    cout << "삽입:1, 검사:2, 종료:3>>";
    cin >> menu;
    if(menu == 1){
        cout << "이름 암호>>";
        cin >> name >> password;
        m.insert(make_pair(name, password));
    }
    else if(menu == 2){
        cout << "이름?";
        cin >> name;
        while(true){
        cout << "암호?";
        cin >> password;
        if(m[name]==password){
        cout << "통과!!" << endl;
        break;
        }
        else
        cout << "실패~~" << endl;
        }
    }
    else if(menu == 3){
        cout << "프로그램을 종료합니다...";
        return 0;
    }
}
    return 0;
}

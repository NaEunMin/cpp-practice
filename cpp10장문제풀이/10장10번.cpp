/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

/*

*** class Nation ***
set함수들은 필요가 없었음.  ---> 생성자를 활용하여 vector에 객체들을 삽입했기 때문임.

*** 정보 입력 ***
cout << v.size()+1 << ">>";   //처음에 v.size()는 아무것도 없기때문에 0임. 그래서 번호를 출력할 것이기에 +1을 해줌.

        for(int i=0; i<v.size(); i++){   
            if(nation==v[i].getNation()){  //위에서 입력한 나라를 vector에 저장된 나라들과 비교를 함. 기존에 있는 나라를 입력했다면
                cout << "already exists !!" << endl;  //이미 저장이 되어있음을 알림
                check = 1;  //이미 저장되어 있는 상황과 새로운 정보를 저장하는 상황을 구분하기위한 장치
                break;
            }
        }

        if(check == 0){  //위에서 이미 저장된 상황에선 check = 1이고 새로운 정보를 저장하는 상황은 check = 0으로 된다. 
        Nation p(nation, capital);  //나라와 수도를 저장한 객체 생성
        v.push_back(p);  //객체를 vector에 삽입
        }

주석에 있는 for문으로도 가능하다. 여러가지 방법이 있음을 염두해두자.

*** 퀴즈 ***
    while(true){
    srand(time(NULL));
    int random = rand()% v.size();
    cout << v[random].getNation() <<"의 수도는?(exit 입력시 퀴즈 종료)";
    cin >> capital;
----> 랜덤하게 나라를 뽑아서 문제를 출제해야 하기에 난수발생

*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nation{
    string nation;
    string capital;
    public:
    Nation(string nation, string capital){ this->nation = nation; this->capital = capital;}
    void setNation(string nation){ this->nation = nation; }
    string getNation() { return nation; }
    void setCapital(string capital){ this->capital = capital; }
    string getCapital(){ return capital; }
};


int main()
{
    vector<Nation> v;
    int menu;
    string nation;
    string capital;
    
    cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
    while(true){
    cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
    cin >> menu;
    if(menu==1){
        cout << "현재 " << v.size() <<"개의 나라가 입력되어 있습니다." << endl;
        cout << "나라와 수도를 입력하세요(no no 이면 입력 끝)" << endl;
        while(true){
        int size = 0;
        cout << v.size()+1 << ">>";
        cin >> nation >> capital;
        if(nation=="no" && capital=="no") break;
        for(int i=0; i<v.size(); i++){
            if(nation==v[i].getNation()){
                cout << "already exists !!" << endl;
                check = 1;
                break;
            }
        }
        
        if(check == 0){
        Nation p(nation, capital);
        v.push_back(p); 
        }
    }
}
/*cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다.\n";
                 cout << "나라와 수도를 입력하세요(no no 이면 입력끝)\n";
                 for(int i=v.size()+1;; i++){
                     string n, c;   //나라와 수도 변수 선언
                    cout << i << ">>";    //번호 출력
                     cin >> n >> c;
                     if(n=="no" && c=="no") //나라와 수도에 no no를 입력하면
                         break; //나라와 수도 입력을 멈춤
                     for(int j=0; j<v.size(); j++) //입력한 나라와 수도를 검사
                         if(nation==v[j].getNation()){  //입력한 나라가 vector에 이미 존재한다면
                             cout << "already exists !!\n";  //이미 존재함을 알림
                             i--;  //위에서 나라와 수도 입력시 i(번호)가 증가했으므로 1감소시켜줌.
                             check = 1;
                            break;
                        }
                    if(check == 0)
                    v.push_back(Nation(n, c)); // 정상적인 입력 값이면 vector v에 입력 
                }
                break;*/
else if(menu==2){
    while(true){
    srand(time(NULL));
    int random = rand()% v.size();
    cout << v[random].getNation() <<"의 수도는?(exit 입력시 퀴즈 종료)";
    cin >> capital;
    
    if(v[random].getCapital()==capital)
    cout << "Correct!!"<< endl;
    else
    cout << "NO !!" << endl;
    
    if(capital == "exit")
    break;
}

}
else if(menu==3){
    cout << "게임을 종료합니다.";
    return 0;
}
}
}


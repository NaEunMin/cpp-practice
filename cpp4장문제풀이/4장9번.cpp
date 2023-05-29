/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Person{
    string name;
    string tel;
    public:
    Person();
    string getName() {
        return name;
    }
    string getTel(){
        return tel;
    }
    void set(string name, string tel);
};

void Person::set(string name, string tel){
    this->name=name;
    this->tel=tel;
}

Person::Person(){
    
}

int main()
{
    Person people[3];
    string name,tel;
    cout << "이름과 전화 번호를 입력해 주세요\n";
    for(int i=0;i<3;i++){
        cout << "사람 " << i+1 <<">>";
        cin >> name >> tel;
        people[i].set(name,tel);
        cout << endl;
    }
    cout << "모든 사람의 이름은";
    for(int i=0;i<3;i++){
        cout << people[i].getName() << ' ';
    }
    cout << endl;
    cout << "전화번호 검색합니다. 이름을 입력하세요>>";
    string input_name;
    cin >> input_name;
    
    for(int i=0;i<3;i++){
        if(people[i].getName()==input_name){
            cout << "전화번호는 " << people[i].getTel();
            break;
        }
    }
    return 0;
}

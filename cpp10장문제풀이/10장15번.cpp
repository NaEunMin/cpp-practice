/*****************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

******************************************************************************/

/*

*** 삽입 파트 ***
그 전에 많이 했으니 할 수 있을 것이다.

*** 삭제 파트 ***
vector<Circle*>::iterator it = v.begin();  
vector<Circle*>의 원소를 가리키는 포인터 it변수 선언
it = v.begin(); ---> 처음 선언하면 it은 아무것도 가르키고 있지않다. 앞에서부터 원이름을 비교할 것이므로 it에 vector의 첫번째 원소의 주소를 대입한다.

   vector<Circle*>::iterator it = v.begin();
                while(it != v.end()){   // v.end()는 vector끝 원소의 다음 위치에 대한 포인터를 리턴한다. it이 vector끝 다음의 원소를 가르키면 비교할 것이 없으므로 vector의 끝까지만 비교하도록 while문의 조건을 걸어준다.
                    Circle *p = *it; //Circle의 객체에 접근해야하므로 객체포인터 p에 vector의 원소를 가르키는 it의 값을 대입한다.
                    if(p->getName() == name){  
                        it = v.erase(it);   //v.erase()는 it이 가리키는 원소 삭제 후, vector의 원소들을 앞으로 한자리씩 이동시켜준다. 리턴값은 삭제된 다음 원소를 가리키는 포인터를 리턴한다.
                        delete p;
                    }
                    else
                        it++;   //이름이 같지 않다면 다음 vector원소와 삭제를 원하는 원의 이름을 비교하기위해 다음 vector원소를 가르키도록 ++연산해준다.
                }
            }

----> v.erase()는 위에서 삭제된 다음 원소를 가리키는 포인터를 리턴한다고 했다. 
그러므로 it에 리턴값을 넣어줘야한다.  it = v.erase(it);
이 이유로 위 코드에 삭제파트의 if문에는 it++이 없는 것이다. 삭제를 하면 erase가 알아서 it에 다음 원소를 넘겨주기 때문이다.

*** 모두 보기 파트 ***
vector의 데이터타입이 <Circle*>이다. 객체"포인터"이다.
그래서 접근할때 .연산자가 아닌 ->연산자로 접근해줘야한다.

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Circle{
    string name;
    int radius;
    public:
    Circle(int radius, string name){
        this->radius = radius;
        this->name = name;
    }
    double getArea() { return 3.14*radius*radius; }
    string getName() { return name; }
};

int main()
{
    int menu;
    int radius;
    string name;
    vector<Circle*> v;
    cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
    while(true){
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4  >>";
        cin >> menu;
        if(menu == 1){
            cout << "생성하고자 하는 원의 반지름과 이름은 >>";
            cin >> radius >> name;
            v.push_back(new Circle(radius, name));
        }
        else if(menu == 2){
                cout << "삭제하고자 하는 원의 이름은 >> ";
                cin >> name;
                vector<Circle*>::iterator it = v.begin();
                while(it != v.end()){
                    Circle *p = *it;
                    if(p->getName() == name){
                        it = v.erase(it);
                        delete p;
                    }
                    else
                        it++;
                }
            }
        else if(menu == 3){
            for(int i=0; i<v.size(); i++){
                cout << v[i]->getName() << endl;
            }
        }
        else if(menu == 4){
            cout << "프로그램을 종료합니다.";
            return 0;
        }
    }
    return 0;
}

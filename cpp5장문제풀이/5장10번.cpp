/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

main()안에  Buffer& temp = append(buf, "Guys"); 이 코드에서 append는 멤버함수가 아닌 함수인데 무의식적으로 클래스멤버함수로 구현을 하는 실수를 하였다.
이런 디테일 신경쓰면서 코드를 작성하자. 그리고  void add(string next){text+=next;}는 멤버함수라서 객체.멤버함수() 이런 식으로 가야하는데 apppend 구현할때 add()로
해버려서 오류가 나왔다. 이런 부분도 집중해서 실수하지않게 하자.

*/

#include <iostream>
#include <string>
using namespace std;

class Buffer{
    string text;
    public:
    Buffer(string text){this->text = text;}
    void add(string next){text+=next;}
    void print(){cout << text << endl;}
    Buffer& append(Buffer &b,string str);
};

Buffer& append(Buffer &b, string str){ //b는 객체buf에 대한 참조(공간을 공유함)
    b.add(str);
    return b;
}
int main()
{
    Buffer buf("Hello");
    Buffer& temp = append(buf, "Guys");
    temp.print();
    buf.print();
    return 0;
}

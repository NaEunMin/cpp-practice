/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

*** vector ***
vector --> 가변 길이 "배열"
vector 사용시 --> #include <vector> 필요
vector 선언 ---> vector<타입> vector 이름   // vector<int> v (int형 vector v)
vector 원소 삽입 --> v.push_back(원소)  // v.push_back(x)
                            --> v[i] = 원소  // vector클래스에는 []연산자가 작성되어 있어 배열처럼 사용 가능
vector 원소 개수 --> v.size()로 확인 가능

push_back(), size()는 멤버함수이다.

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int x;
    int sum=0;
    while(true){
    cout << "정수를 입력하세요(0을 입력하면 종료)>>";
    cin >> x;
    if(x==0)
    break;
    v.push_back(x);
    sum += x;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "평균 = " << (double)sum/v.size() << endl;
}   
    return 0;
}

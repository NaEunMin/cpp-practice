/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

동적 할당 받은 배열 이용하려면 p[i] 이렇게 하면됨. 
평균을 소수점으로 받고싶다면 합과 평균 변수를 double형으로 하면됨.

*/

#include <iostream>
using namespace std;

int main(){
    double sum=0;
    double avg=0;
    int *p = new int[5];
    cout << "정수 5개 입력>>";
    for(int i=0;i<5;i++){
        cin >> p[i];
        sum+=p[i];
    }
    avg = sum/5;
    cout << "평균 " << avg;
    delete [] p;
    return 0;
}

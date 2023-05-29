/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

자동인라인함수(클래스선언부에 함수구현)할때는 함수작성하고 마지막에 ; 안찍어도됨.
this포인터 멤버함수매개변수와 멤버변수의 이름이 같을때 사용  ex)this->멤버변수=함수인자

*/

#include <iostream>
#include <string>

using namespace std;

class Integer{
    int num;
    string array;
    
    public:
    Integer(int num){
        this->num=num;
    }
    
    Integer(string array){
       this->num=stoi(array); 
    }
    
    int get(){
        return num;
    }
    
    void set(int num){
        this->num=num;
    }
    
    int isEven(){
        return true;
    }
};

/*Integer::Integer(int input_num){
    num=input_num;
}

Integer::Integer(string input_array){
    num=stoi(input_array);
}

int Integer::get(){
    return num;
}

void Integer::set(int input_num){
    num=input_num;
}

int Integer::isEven(){
    if(num%2==0)
    return true;
}*/
int main()
{
    Integer n(30);
    cout << n.get() << ' '; //30출력
    n.set(50);
    cout << n.get() << ' '; //50출력
    
    Integer m("300");
    cout << m.get() << ' '; //300출력
    cout << m.isEven(); //true(정수로 1)출력
    return 0;
}




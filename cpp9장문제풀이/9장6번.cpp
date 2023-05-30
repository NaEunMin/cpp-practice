/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

5장에서 문제에서 다뤘던 자료구조"스택"에 관한 문제다.
pop출력이 왜 1 2 3 4 로 나오는지 잠깐 궁금했는데 size함수 고쳐보고 알았다.
배열에는 남아있다.  pop에서 n에 배열원소 저장하고 top--해버려서 stack[4]를 n에 저장하게되고 top는 3이 되는데
size()는 top+1(4)을 리턴해서 show()함수에서 인덱스가 3까지인 1 2 3 4 까지만 보여준다.

*/

#include <iostream>

using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack{
    int stack[5];
    int top = -1;
    public:
    bool push(int n){
        if(top>4){
           cout << "스택이 꽉 찼습니다." << endl; 
           return false;  
        }
        
        stack[++top] = n;
        return true;

    }
    bool pop(int &n){
        if(top<0){
            cout << "스택이 비었습니다." << endl;
            return false;
        }
        
        n = stack[top--];
        return true;
    }
    int size(){
        return top+1;
    }
    
    void show(){
        for(int i=0; i<size(); i++){
            cout << stack[i] << " ";
        }
    }
};

int main()
{
    IntStack intstack;
    
    intstack.push(1);
    intstack.push(2);
    intstack.push(3);
    intstack.push(4);
    intstack.push(5);
    
    intstack.show();
    
    int n;
    intstack.pop(n);
    cout << endl;
    intstack.show();
    return 0;
}

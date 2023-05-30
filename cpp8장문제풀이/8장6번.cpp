/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

***변수 top를 잘 관찰해야함***
스택에서 top는 마지막요소의 인덱스를 말해준다. 그래서 top를 처음에 0으로 초기화하려한다. 하지만 0으로 초기화한 후 push함수에서 put(top, num) top++ 이렇게 작성하면 문제발생
1 3 5 7 9를 스택에 넣을 것 인데 다 넣고나면 top는 4가 되어야하는데 top가 5가된다.  //push함수에서 코드순서가 top++가 마지막에 있기때문에 요소를 넣고 top를 한번 더해주고 때문.
결과 => 0 9 7 5 3  //0은 크기가 100인 배열에 없는 인덱스에 접근해서 0이 나옴.

***해결방법***
"top=-1"로 초기화하라.
top를 -1로 초기화하고 push함수를 ++top put(top, num)으로 해주면 top는 4에서 끝나고 요소도 문제없이 추가된다. 
디테일 : length()함수는 스택용량이 아닌 스택크기를 말해주므로 top+1을 해서 5가 출력되게 해주어야한다.

*/

#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray{
    int top;
    public:
    MyStack(int capacity) : BaseArray(capacity){
        top=-1;
    }
    void push(int num){
        ++top;
        put(top, num);
    }
    int pop(){
        return get(top--);
    }
    int capacity(){
        return getCapacity();
    }
    int length(){
        return top+1;
    }
    
};

int main()
{
    MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택의 용량:" << mStack.capacity() << ", 스택의 크기:" << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
	return 0;
}

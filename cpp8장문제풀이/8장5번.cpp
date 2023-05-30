/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

큐에 대한 이해가 필요한 문제.
***스택과의 차이점 ***
스택 : 먼저들어온 요소가 가장 나중에 제거된다. // 박스에 물건을 넣고 빼는 원리
큐 : 먼저들어온 요소가 가장 빨리 제거된다. // 마트의 진열대에 "선입선출"로 정리하는 원리.

***큐에서 사용하는 용어***
Enqueue : 큐의 맨 뒤쪽에 요소를 추가   // 가장늦게 들어오는 요소
Dequeue : 큐의 맨 앞쪽 요소를 삭제  // 가장빨리 들어온 요소를 삭제
Peek : front에 위치한 데이터를 읽음.
front : 큐의 맨 앞 위치(인덱스)
rear : 큐의 맨 뒤 위치(인덱스)

***문제 풀며 발생한 오류***
int capacity(), int dequeue() 작성 시
void capacity(){ getCapacity(); } 이렇게 작성하면 안된다.  // 컴파일 오류발생
int  capacity(){ return getCapacity(); } 이렇게 리턴으로 주어야 오류발생안한다.

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

class MyQueue : public BaseArray{
    int end;
    int start;
    public:
    MyQueue(int capacity) : BaseArray(capacity){
        end=0;
        start=0;
    }
    int capacity(){
        return getCapacity();
    }
    int length(){ 
        return end-start;
    }
    void enqueue(int num){
       put(end, num); 
       end++;
    }
    
    int dequeue(){
        return get(start++);
    }
};

int main()
{
    MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout<<endl<<"큐의 현재 크기 : " << mQ.length() << endl;

    return 0;
}

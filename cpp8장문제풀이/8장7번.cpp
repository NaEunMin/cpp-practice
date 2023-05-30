/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

구현하는데 굉장히 힘들었던 문제-----> 나중에 한번 더 봐야할 문제.
BaseMemory클래스에서 getData()데이터를 얻는함수, setData()데이터를 입력하는함수를 작성했다. //ROM, RAM 모두에게 필요한 기능이기때문

ROM생성자에서 for문으로 배열요소 초기화를 해줘야한다.  //문제에서 burn작업이 일어나야한다고 했다.  **burn : 사용자가 요청한 데이터로 초기화하는 작업

main문에서 for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i)); 이 문장이 ROM에서 읽기와 RAM에서 쓰기를 동시에하는 코드라 이해하기가 힘들었다.

***이 문제는 함수들이 서로 얽혀서 돌아하는 프로그램이므로 함수들의 관계와 순서를 이해하는게 관건이다.***
알고리즘이 어려운건 아니다.

*/

#include <iostream>

using namespace std;

class BaseMemory{
    char *mem;
    protected:
    BaseMemory(int size){ mem = new char [size]; }
    char getData(int index){ return mem[index]; }
    void setData(int index, char ch){ mem[index] = ch; }
};

class ROM : public BaseMemory{
    public:
    ROM(int size, char x[], int length) : BaseMemory(size){
        for(int i=0; i<length; i++) setData(i, x[i]);
    }
    char read(int index){ return getData(index); } 
};

class RAM : public BaseMemory{
    public:
    RAM(int size) : BaseMemory(size){}
    void write(int index, char ch){ setData(index, ch); }
    char read(int index){ return getData(index); }
};

int main()
{
    char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
    return 0;
}

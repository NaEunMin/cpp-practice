/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

3장풀면서 함수타입 안적는 실수 등 자잘한 실수들이 많았다. 좀 더 꼼꼼히 검토하는 습관이 있으면 좋을듯하다.(물론 실행하면서 어디가 문제인지 나와서 고치면되지만 실수는 없으면 좋다!)

*/


#include <iostream>

using namespace std;

#include "Ram.h"
    int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102번지의 값 = " << (int)ram.read(102) << endl;

	return 0;
}

/*  Ram.h 소스코드
class Ram{
    char mem[100*1024];
    int size;
    public:
    Ram();
    ~Ram();
    char read(int address);
    void write(int address, char value);
};*/

/* Ram.cpp 소스코드
#include <iostream>
#include "Ram.h"
using namespace std;
Ram::Ram(){
    size=100*1024;
    for(int i=0;i<size;i++)
    {
        mem[i]=0;
    }
}

Ram::~Ram(){
    cout << "메모리 제거됨";
}

char Ram::read(int address){
    return mem[address];
}

void Ram::write(int address, char value){
    mem[address]=value;
}*/



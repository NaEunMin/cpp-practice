/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

문제풀고 다른 분들의 코드를 봤는데 비트연산자 &,|,^로 코드를 작성하셨다.
평소에 쓰던 논리연산자는 주석처리해두었다.

*/

#include <iostream>

using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate{
    public:
    bool operation(){
        return x&y; //return x&&y;
    }
};

class ORGate : public AbstractGate{
    public:
    bool operation(){
        return x|y; //return x||y;
    }
};

class XORGate : public AbstractGate{
    public:
    bool operation(){
        return x^y;
    }
};

int main()
{
    ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;


    return 0;
}

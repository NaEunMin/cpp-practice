/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

함수는 같으나 태그와 디버그가 달라서 서로 다르게 구분해서 저장해야해서 고민했던 문제
----> 문자열은 배열로 저장을 못하나? 라는 생각을 했음. 사실 당연히 가능한건데 생각이 좁았음 int num[], char ch[]이런것만 봐도 될텐데 string str[] 이것도 될 것이다.
그리고 여기서 멤버변수를 추가할 생각을 못했다. 너무 주어진 것으로 해결할 생각으로 문제를 보는 시각이 좁아졌다.
이 문제의 포인트는 string 배열, static 멤버변수 생성이라고 생각한다.
string 배열 : static string tagName[100], static string debugCourse[100] //태그와 디버그를 저장할 배열
static 멤버변수 : static int count = 0; //태그와 디버그를 저장할때 저장할 인덱스
이제 print 함수에서 tag만 구별해서 출력하는 기능을 구현만 하면 된다.

*/

#include <iostream>
#include <string>
using namespace std;
class Trace {
public:
	static string tagName[100];
	static string debugInfo[100];
	static int index;
	static void put(string tag, string Info);
	static void print(string tag);
	static void print();
};
//이 부분 매우 중요!! static 멤버 변수는 외부에 전역 변수로 반드시 선언되어야한다.
// class 내부에서 만들었다면 전역 변수에 반드시 다시 선언하여 변수 공간을 만들어주자.
int Trace::index = 0;
string Trace::tagName[100];
string Trace::debugInfo[100];


void Trace::put(string t, string in) {
	tagName[index] = t;
	debugInfo[index] = in;
	index++;

}
void Trace::print(string t) {

	cout << t << "태그의 Trace 정보를 출력합니다" << endl;
	for (int i = 0; i <=index; i++) {
		if (tagName[i] == t) {
			cout << tagName[i] << ":" << debugInfo[i] << endl;
		}
	}
}
void Trace::print() {
	cout << "모든 Trace 정보를 출력합니다" << endl;
	for (int i = 0; i <=index; i++) {
		cout << tagName[i] << ":" << debugInfo[i] << endl;
	}
}
void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}
int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}

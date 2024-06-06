/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

연산자 함수 작성시 매개변수는 메인함수에서 
if (b < a) 이렇게 있다고 하면
매개변수 작성순서는 b --> a 순으로 작성해주면된다.        bool operator < (string title, Book op1) 이런 느낌으로

*/

#include <iostream>
#include <string>
using namespace std;
class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << "페이지 " << endl;
	}
	string getTitle() { return title; }
	friend bool operator <(string b, Book a); //연산자 함수 작성 시 main 함수에 왼쪽 피연산자에 본인 객체가 아닌 상수 ex)int, string 등이 있다면 friend함수로 작성
};
bool operator <(string b, Book a) {
	if (b < a.title) return true;
	else return false;
}
int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요>>";
	getline(cin, b);
	if (b < a) {
		cout << a.getTitle() << "이" << b << "보다 뒤에 있구나!" << endl;
	}
	return 0;
}

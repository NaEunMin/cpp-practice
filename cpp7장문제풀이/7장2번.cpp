/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

/*

title == op.title && price == op.price && pages == op.pages ---> 이 코드처럼 3개의 조건을 &&로 비교 못하는줄 알았다. 하지만 가능했다.
외부함수에서 객체2개를 비교하려면 매개변수에 객체 2개를 넘겨주어야한다. ----> 원본을 바꿀건 아니기 때문에 참조에 의한 호출은 필요없다.

*/


#include <iostream>
#include <string>

using namespace std;

class Book {
	string title;
	int price, pages;
public : 
	Book(string title="", int price=0, int pages=0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	
	friend bool operator == (Book op, int price);
	friend bool operator == (Book op, string title);
	friend bool operator == (Book op1, Book op2);
	/* **************클래스 멤버 함수 구현*****************
	bool operator == (int price) { 
		if( this->price == price ) return true;
		else return false;
	}
	
	bool operator == (string title) { 
		if( this->title == title ) return true;
		else return false;
	}
	
	bool operator == (Book op) {
		if( title == op.title && price == op.price && pages == op.pages ) return true;
		else return false;
	}*/
	
};

bool operator == (Book op, int price){
    if(op.price==price)
    return true;
    else
    return false;
}

bool operator == (Book op, string title){
    if(op.title==title)
    return true;
    else
    return false;
}

bool operator == (Book op1, Book op2){
    if(op1.title==op2.title && op1.price==op2.price && op1.pages==op2.pages)
    return true;
    else
    return false;
}

int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if( a == 30000 ) cout << "정가 30000원" << endl;
	if( a == "명품 C++" ) cout << "명품 C++ 입니다." << endl;
	if( a == b ) cout << "두 책이 같은 책입니다." << endl;
	else
	cout << "두 책이 다른 책입니다." << endl;
	
	return 0;
}

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
	/*
	bool operator == (int a) {
		if (price == a) return true;
		else return false;
	}
	bool operator == (string a) {
		if (title == a) return true;
		else return false;
	}
	bool operator == (Book b) {
		if (title == b.title && price == b.price && pages == b.pages) return true;
		else return false;
	}*/
	friend bool operator == (Book a, int b);
	friend bool operator == (Book a, string b);
	friend bool operator == (Book a, Book b);
};
bool operator == (Book a, int b) {
	if (a.price == b) return true;
	else return false;
}
bool operator == (Book a, string b) {
	if (a.title == b) return true;
	else return false;
}
bool operator == (Book a, Book b) {
	if (a.title == b.title && a.price == b.price && a.pages == b.pages) return true;
	else return false;
}
int main() {
	Book a("청춘", 30000, 300), b("미래", 30000, 500);
	if (a == 30000) cout << "정가 30000원 입니다." << endl;
	if (a == "청춘") cout << "청춘입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}

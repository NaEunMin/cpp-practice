/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

연산자 함수 구현 시 클래스 멤버함수로 구현을 하면 매개변수에 객체를 안넘기지만 외부함수로 프렌드로 선언하려면 객체를 매개변수로 넘겨주어야한다.
객체원본을 수정하려면 참조매개변수를 사용하는 디테일도 필요하다.

*/

#include <iostream>

using namespace std;


class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	
	friend Book& operator += (Book &op, int price);
	friend Book& operator -= (Book &op, int price);
	
	//Book& operator += (int price);
	//Book& operator -= (int price);  
};


/*  ******************클래스 멤버 함수로 구현**************************
Book& Book::operator += (int price){
    this->price += price;
    return *this;
}

Book& Book::operator -= (int price){
    this->price -= price;
    return *this;
}*/

Book& operator += (Book &op, int price){
    op.price += price;
    return op;
}

Book& operator -= (Book &op, int price){
    op.price -= price;
    return op;
}

int main()
{
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500;
    b -= 500;
    a.show();
    b.show();

    return 0;
}

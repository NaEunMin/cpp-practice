/******************************************************************************
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/


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
	bool operator !() {
		if (price == 0) return true;
		else return false;
	}*/
	friend bool operator !(Book a) {
		if (a.price == 0) return true;
		else return false;
	}
};
int main() {
	Book book("벼룩시장", 0, 50);
	if (!book)cout << "공짜다" << endl;
	return 0;
}

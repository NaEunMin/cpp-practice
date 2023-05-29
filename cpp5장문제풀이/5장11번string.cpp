/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

class Book{
    string title;
    int price;
    public:
    Book(string title, int price){    
    this->title = title;
    this->price = price;}
    
    Book(const Book &b){
    this->title = b.title;
    this->price = price;
    }
    
    void set(string title, int price){
    this->title = title;
    this->price = price;
    }
    
    void show(){cout << title << ' ' << price << "원" << endl;}

};
int main(){
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();

    return 0;
}

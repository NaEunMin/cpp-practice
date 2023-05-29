/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

복사생성자 다룰때 생성자와 복사생성자 둘다 동적생성을 한다는 디테일을 잊었다... 좀 더 꼼꼼하게 공부하자.

*/

#include <iostream>
#include <cstring>
using namespace std;

class Book{
    char *title;
    int price;
    public:
    Book(const char *title, int price){    
    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
    this->price = price;}
    
    Book(const Book &b){
    this->title = new char[strlen(b.title)+1];
    strcpy(this->title, b.title);
    this->price = price;
    }
    
    ~Book(){
        delete [] title;
    }
    
    void set(char *title, int price){
    if(this->title)
    delete [] this->title;
    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
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

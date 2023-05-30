/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

*** cin.ignore() ***
cin과 getline을 같이 사용할때 cin.ignore()가 필요한 이유
---> cin은 '\n'을 처리하지 않고 입력버퍼에 남겨둔다.  ----> getline은 '\n'를 입력버퍼에서 가져와서 처리한다.  ---> getline에서 처음에 '\n'을 가져오므로 getline이 한번 무시된다.

이 문제상황에서 처음에 year를 입력받을때 cin을 사용한다. 
이 다음줄에 cin.ignore(1, '\n')을 작성하지 않으면 다음 책이름 입력하는 getline은 무시된다.

문제에서 cin.ignore(1, '\n')로 작성했는데 cin.ignore()로 해도 된다.

*** cin.ignore() ***
입력버퍼를 비워주는 코드
-매개변수가 없을때 : 입력버퍼 비워버리기
-매개변수가 있을때 : 첫번째 매개변수(읽어들일 문자의 개수), 두번째 매개변수(읽어들이면 종료할 문자)

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book{
    int year;
    string bookname;
    string writer;
    public:
    Book(int year, string bookname, string writer){
        this->year = year;
        this->bookname = bookname;
        this->writer = writer;
    }
    int getYear(){ return year; }
    string getBookName() { return bookname; }
    string getWriter() { return writer; }
};

int main()
{
    int year;
    string bookname;
    string writer;
    
    vector<Book> v;
    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while(true){
        cout << "년도>>";
        cin >> year;
        if(year == -1) break;
        
        cin.ignore(1, '\n');
        cout << "책이름>>";
        getline(cin, bookname);
        
        cout << "저자>>";
        getline(cin, writer);
        
        v.push_back(Book(year, bookname, writer));
    }
    
    cin.ignore(1, '\n');
    cout << "총 입고된 책은 " << v.size() << "입니다." << endl;
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    getline(cin, writer);
    
    for(int i=0; i<v.size(); i++){
        if(writer == v[i].getWriter()){
            cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
        }
    }
    
    cout << "검색하고자 하는 년도를 입력하세요>>";
    cin >> year;
    
    for(int i=0; i<v.size(); i++){
        if(year == v[i].getYear()){
            cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
        }
    }
    return 0;
}

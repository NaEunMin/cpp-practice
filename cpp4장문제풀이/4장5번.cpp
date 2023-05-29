/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

   srand((unsigned)time(0));
    char ch = 'a'+rand()%26;  아스키코드를 이용해서 알파벳이 26개이니 %26을 해주고 'a'를 더하면 알파벳이 무작위로 출력이 된다는걸 알았음.

*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    string str;
    cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)";
    while(true){
    getline(cin,str);
    if(str=="exit")
    break;
    
    srand((unsigned)time(0));
    int n = rand()%str.length();
    
    srand((unsigned)time(0));
    char ch = 'a'+rand()%26;
    
    str[n]=ch;
    
    cout << str << endl;
    }
    
    
    return 0;
}

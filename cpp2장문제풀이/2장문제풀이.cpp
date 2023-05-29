/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string eng;
    int count=0;
    int ch_count=0;
    cout<<"영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n";
    cout<<"텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
    getline(cin,eng);
    
    for(int i=0;i<=eng.length();i++)
    {
        if(isalpha(eng[i])!=0)
        {
            count++;
        }
}
cout<<"총 알파벳 수 "<<count<<'\n';

for(char ch='a';ch<='z';ch++)//a~z까지 출력하기위함
{
    ch_count=0;
    for(int j=0;j<=eng.length();j++)//소문자 바꾸고 몇번 나왔는지 카운트
    {
        tolower(eng[j]);
        if(eng[j]==ch)
        {
            ch_count++;
        }
    }
    cout<<ch<<' '<<ch_count<<' '<<':';
    
    for(int z=0;z<ch_count;z++) /카운트 한 횟수를 출력
    {
        cout<<'*';
    }
    cout<<'\n';
}
    return 0;
}

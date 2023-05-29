/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

아래 주석코드처럼 뒤쪽인덱스부터 출력해버리는 간단한 방식이 있었음.
하지만 나는 tmp를 이용해서 앞쪽 인덱스와 뒤쪽인덱스를 바꾸는 방식을 채택했음.
더 쉬운방법이 있었고 알고리즘은 참 다양하다를 느끼는 문제...

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)\n";
  while(true){
      getline(cin , str);
      if(str=="exit")
      break;
      for(int i=0;i<str.length()/2;i++){
          char tmp = str[i];
          str[i] = str[str.length()-i-1];
          str[str.length()-i-1] = tmp;
      }
      cout << str << endl;
  }
    return 0;
}



/*
int main() {
	string str;

	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str.compare("exit") == 0) break;

		for (int i = str.length() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << endl;
	}

	return 0;
}
*/

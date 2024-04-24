/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*

control reaches end of non-void function 이런 오류가 뜨긴하는데 실행은 되고 결과도 잘 나왔다.
return값이 없어서 나오는 오류라고한다. 왜 뜨는지는 찾아봐야할 것 같다.

*/

#include <iostream>
using namespace std;
char& find(char a[], char c, bool& success) {
	int size = strlen(a);
	for (int i = 0; i < size; i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
}
int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}

/*
#include <iostream>
#include <cstring>

using namespace std;

char& find(char a[], char c, bool& success){
    for(int i=0;i<strlen(a);i++){  //for(int i=0; a[i] != NULL ; i++) 이방법도 있었다.
        if(a[i]==c){
            success = true;
            return a[i];
        }
        else
        success == false;
    }
}

int main()
{
    char s[] = "Mike";
    bool b = false;
    char &loc = find(s, 'M', b);
    if(b==false){
        cout << "M을 발견할 수 없다" << endl;
        return 0;
    }
    loc = 'm';
    cout << s << endl;
}
*/

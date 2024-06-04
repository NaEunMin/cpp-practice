#include <iostream>
using namespace std;

int main() {
	int ch;
	int count = 0;
	cout << "라인 1개를 입력 >>";
	while ((ch = cin.get())!=EOF) { //이 문장을 잘 알아두도록하자. 파일의 끝이 아니면 계속해서 입력 받는다
		cout.put(ch);
		if (ch == 'a') count++;
		else if (ch == '\n') break; //이 문장으로 enter키 들어오면 멈춘다
	}
	cout << endl;
	cout << "라인 1개에 포함된 a의 개수는 :" << count << endl;
	return 0;
}

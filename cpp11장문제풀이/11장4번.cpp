#include<iostream>
using namespace std;

int main() {
	int ch;
	while (true) {
		cout << "라인 1개를 입력해주세요 >>";
		while ((ch = cin.get()) != EOF) {
			if (ch == ';') { //';'를 만나면
				cout.put('\n');//한줄 내리고
				cin.ignore(100, '\n');//버퍼에 있는 문자 무시하기
			}
			else cout.put(ch); //';'만나지 않았다면 계속 출력
		}
	}
}

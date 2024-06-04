#include <iostream>
using namespace std;

int main() {
	int ch;
	cout << "라인 1개를 입력해주세요 >>";
	cin.ignore(100,';'); // cin.ignore는 입력을 받을 수 도 있는 듯 하다.
	while ((ch = cin.get()) != EOF) {
		if (ch == '\n') {
			cin.ignore(100, ';');
		}
		cout << (char)ch;
	}
	cout << endl;
}

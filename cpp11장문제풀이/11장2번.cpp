#include <iostream>
using namespace std;

int main() {
	char ch;
	int count = 0;
	cout << "공백을 포함한 라인 1개 입력 >>";
	while (true) {
		cin.get(ch);
		if (cin.eof())break;
		cout.put(ch);
		if (ch == '\n')break;
		else if (ch == ' ') count++;
	}cout << endl;
	cout << "라인 1개에 포함된 공백의 개수 :" << count << endl;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "문자열 입력>>";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j <= i; j++) {
			cout << str[j];
		}
		cout << "\n";
	}
	return 0;
}

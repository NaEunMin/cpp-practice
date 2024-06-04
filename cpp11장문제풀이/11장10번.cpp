#include <iostream>
using namespace std;
istream& prompt (istream& ins) {
	cout << "암호?";
	return ins;
}
int main() {
	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
		}
		else {
			cout << "login fail. try again" << endl;
		}
	}
}

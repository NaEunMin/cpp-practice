#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
int main() {
	for (int i = 0; i < 4; i++) {
		cout << left << setw(8) << "dec";
		cout << left << setw(8) << "hexa";
		cout << left << setw(8) << "char";
	}
	cout << endl;
	for (int i = 0; i < 4; i++) {
		cout << left << setw(8) << "___";
		cout << left << setw(8) << "____";
		cout << left << setw(8) << "____";
	}
	cout << endl;
	for (int i = 0; i <= 128; i++) {
		cout << left << setw(8) << dec << i;
		cout << left << setw(8) << hex << i;
		if (isprint(i)) {
			cout << left << setw(8) << (char)i;
		}
		else {
			cout << left << setw(8) << '.';
		}
		if (i % 4 == 0)cout << endl;
	}
}

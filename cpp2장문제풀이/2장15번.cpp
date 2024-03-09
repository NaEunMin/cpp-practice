#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char num1[100];
	char ch[10];
	char num2[100];
	while (true) {
		cout << "?";
		cin.getline(num1, 100, ' ');
		cin.getline(ch, 10, ' ');
		cin.getline(num2, 100, ' ');

		if (strcmp(ch,"+")==0) {
			cout << num1 << " + " << num2 << " = " << atoi(num1) + atoi(num2) << '\n';
		}
		else if (strcmp(ch, "-") == 0) {
			cout << num1 << " - " << num2 << " = " << atoi(num1) - atoi(num2) << '\n';
		}
		else if (strcmp(ch, "/") == 0) {
			cout << num1 << " / " << num2 << " = " << atoi(num1) / atoi(num2) << '\n';
		}
		else if (strcmp(ch, "%") == 0) {
			cout << num1 << " % " << num2 << " = " << atoi(num1) % atoi(num2) << '\n';
		}
		else if (strcmp(ch, "*") == 0) {
			cout << num1 << " * " << num2 << " = " << atoi(num1) * atoi(num2) << '\n';
		}
	}
	return 0;
}

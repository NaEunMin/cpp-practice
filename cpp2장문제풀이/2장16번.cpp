#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[10000];
	int count = 0;
	int alpha_count = 0;
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n";
	cout << "텍스트의 끝은 ; 입니다. 100000개까지 가능합니다.\n";
	cin.getline(str, 10000, ';');

	int index = 0;
	while (str[index]!=NULL) {
		
		if (isalpha(str[index])) {
			alpha_count++;
		}
		index++;
	}
	cout << "총 알파벳 수 " << alpha_count << "\n";
	for (char ch = 'a'; ch <= 'z'; ch++) {
		count = 0;
		for (int i = 0; i < 10000; i++) {
				if (tolower(str[i]) == ch) {
					count++;
				}
		}
		cout << ch << "(" << count << ")" << "    : ";
		for (int j = 0; j < count; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string max_str;
	char name[100];
	int max = 0;
	int max_index;
	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요\n";
	for (int i = 1; i <= 5; i++) {               //for문 내부의 구조를 잘 알아야 함
		cin.getline(name, 100, ';');             //입력받다가 ; 나오면 입력 끝
		cout << i << " : " << name << '\n';     // 그 다음에 출력, 그 다음에 또 입력받다가 ; 나오면 입력 끝-> 출력
		if (max < strlen(name)) {
			max = strlen(name);
			max_str = name;
		}
	}
	cout << "가장 긴 이름은" << max_str;
	return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main() {
	char name[100];
	int max = 0;
	char maxName[100];
	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		cin.getline(name, 100, ';');
		cout << i + 1 << " : " << name << endl;
		if (max < strlen(name)) {
			max = strlen(name);
			strcpy(maxName, name);
		}
	}
	cout << "가장 긴 이름은 " << maxName << endl;
}
*/

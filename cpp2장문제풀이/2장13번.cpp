#include <iostream>
#include <string>
using namespace std;

int main() {
	int menu_number;
	int count;

	while (true) {
		cout << "***** 승리장에 오신 것을 환영합니다 *****\n";
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
		cin >> menu_number;
		if (menu_number == 1) {
			cout << "몇인분?";
			cin >> count;
			cout << "짬뽕 " << count << "인분 나왔습니다.\n";
		}
		else if (menu_number == 2) {
			cout << "몇인분?";
			cin >> count;
			cout << "짜장 " << count << "인분 나왔습니다.\n";
		}
		else if (menu_number == 3) {
			cout << "몇인분?";
			cin >> count;
			cout << "군만두 " << count << "인분 나왔습니다.\n";
		}
		else if (menu_number == 4) {
			cout << "오늘 영업은 끝났습니다.";
			break;
		}
		else {
			cout << "다시 주문하세요\n";
		}
	}
}

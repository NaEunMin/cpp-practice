#include <iostream>
using namespace std;

int main() {
	char coffee[100];
	int number;
	int sum_money=0;
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다.\n";
	while (true) {
		cout << "주문>>";
		cin >> coffee >> number;
		if (strcmp(coffee, "에스프레소") == 0) {
			cout << 2000 * number << "원입니다. 맛있게드세요.\n";
			sum_money += 2000 * number;
		}
		else if (strcmp(coffee, "아메리카노") == 0) {
			cout << 2300 * number << "원입니다. 맛있게드세요.\n";
			sum_money += 2300 * number;
		}
		else if (strcmp(coffee, "카푸치노") == 0) {
			cout << 2500 * number << "원입니다. 맛있게드세요.\n";
			sum_money += 2500 * number;
		}

		if (sum_money >= 20000) {
			cout << "오늘" << sum_money << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~";
			break;
		}
	}
}

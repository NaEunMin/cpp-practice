// 더 다양한 방법으로 문제를 풀었다.

#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int count = 0;
	int index = 0;
	cout << "문자열 입력 >>";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a') //문자열 다루는 기본적인 방법
			count++;
	}
	cout << "문자는 " << count << "개 있습니다." << endl;

	count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'a')
			count++;
	}
	cout << "문자는 " << count << "개 있습니다." << endl;

	count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == 'a') //i인덱스에 있는 문자를 리턴하는 함수 at()
			count++;
	}
	cout << "문자는 " << count << "개 있습니다." << endl;

	count = 0;
	while (true) {
		if (str.find('a', index) == -1)
			break;

		if (str.find('a', index) >= 0) { //a가 있는 인덱스를 반환하는 함수 find()
			count++;
			index = str.find('a', index); //이 코드가 없으면 1칸씩 올라가면서 a가 있는 인덱스를
			//다 반환해서 원하는 값이 안나온다. a를 찾았다면 해당 인덱스를 저장해주자
		}
		index++; //a의 다음 인덱스부터 비교하기 위한 코드
	}
	cout << "문자는 " << count << "개 있습니다." << endl;

}

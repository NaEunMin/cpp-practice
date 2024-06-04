#include <iostream>
using namespace std;
class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}
	friend ostream& operator << (ostream& stream, Circle c);
	friend istream& operator >> (istream& stream, Circle& c);
};
ostream& operator << (ostream& stream, Circle c) {
	stream << "(반지름" << c.radius << "인 " << c.name << ")";
	return stream;
}
istream& operator >> (istream& stream, Circle& c) { //함수를 통해 직접 멤버변수의 원형을 변경해야 하므로 참조를 인자값으로 넘겨준다.
	cout << "반지름>>";
	stream >> c.radius;
	cout << "이름>>";
	stream >> c.name;
	return stream;
}
int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}

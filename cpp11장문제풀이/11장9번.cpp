#include <iostream>
using namespace std;
class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend istream& operator >> (istream& stream, Phone& info);
	friend ostream& operator << (ostream& stream, Phone info);
};
istream& operator >> (istream& stream, Phone& info) {
	cout << "이름>>";
	stream >> info.name;
	cout << "전화번호>>";
	stream >> info.telnum;
	cout << "주소>>";
	stream >> info.address;
	return stream;
}
ostream& operator << (ostream& stream, Phone info) {
	stream << "(" << info.name << "," << info.telnum << "," << info.name << "집)" << endl;
	return stream;
}
int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << boy;
}

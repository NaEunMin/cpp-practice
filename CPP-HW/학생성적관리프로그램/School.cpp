#include <iostream>
#include <string>
#include "School.h"
using namespace std;

School::School(string name) {
	this->name = name; //학교의 이름을 저장
}
School::~School() {//생성했던 School의 객체가 소멸하면서 프로그램 종료를 알림
	cout << " *****" << this->name << "의 입학 관리 프로그램을 종료합니다 *****" << endl;
	delete[] p; //동적 생성했던 p를 반환
}
void School::run() { //학생 입학관리 프로그램 시작함수
	int size; //입력받을 입학생 수;
	cout << " *****" << this->name << "의 입학 관리 프로그램입니다.*****" << endl;
	cout << "입학생 수>>";
	cin >> size;
	this->size = size; //멤버변수 size에 입력받은 size를 저장함
	p = new Student[size]; //학생 배열을 동적으로 생성
	cout << "***** 입학생의 이름과 학과, 점수를 입력합니다.*****" << endl;
	read(); //학생 정보를 입력함
	searchByName(); //이름으로 학생을 찾음
	showAll(); //모든 학생 정보를 출력
}

void School::searchByName() { //학생 이름을 입력받아 학생의 점수를 출력하는 함수
	string name;
	bool check; //학생이 있는지 없는지 체크하는 변수
	cout << "***** 이름으로 검색하면 학점을 출력합니다. *****" << endl;
	while (true) { //이름을 입력받아 학생을 검색, 이름을 '그만'이라고 입력하면 학생검색 종료
		cout << "이름 >>";
		cin >> name;
		if (name == "그만") {
			cout << "검색을 종료합니다." << endl;
			break;
		}
		for (int i = 0; i < size; i++) { //학생의 수 만큼 검색을 진행
			if (p[i].getName() == name) {
				cout << name << "은(는)" << p[i].getGrade() << "입니다." << endl;
				check = true; //학생이 존재한다면 true
				break; //학생이 존재한다면 더 이상 검색을 진행하지 않아도 되므로 break
			}
			else check = false; // 학생이 존재하지 않으므로 false
		}
		if (check == false) { //학생이 존재하지 않음을 출력함
			cout << name << " 학생은 존재하지 않습니다." << endl;
		}
	}
}
void School::showAll() { //전체 학생의 정보를 출력하는 함수
	cout << "***** 전체 학생을 출력합니다 *****" << endl;
	for (int i = 0; i < size; i++) {
		p[i].show(); //학생 별로 정보를 출력
	}
}
void School::read() { //학생들의 정보를 입력하는 함수
	string name;
	string dept;
	int score;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " : 이름, 학과, 점수 >>";
		cin >> name >> dept >> score;
		p[i].set(name, dept, score); //학생 별로 정보를 입력
	}
}
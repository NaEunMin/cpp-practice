#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() { //객체배열을 사용하므로 기본생성자가 필요함

}
void Student::set(string name, string dept, int score) { //학생 정보를 저장하는 함수
	this->name = name;
	this->dept = dept;
	this->score = score;
}
void Student::changeDept(string dept) { //학과를 변경하는 함수
	this->dept = dept;
}
string Student::getName() { //이름을 리턴하는 함수
	return name;
}
string Student::getDept() { //학과를 리턴하는 함수
	return dept;
}
char Student::getGrade() { //학생 점수에 따라 등급을 결정하는 함수
	if (score >= 91) { //점수가 91점 이상이라면 A
		return 'A';
	}
	else if (score <= 90 && score >= 81) { //점수가 81점 이상 90점 이하라면 B
		return 'B';
	}
	else if (score <= 80 && score >= 71) { //점수가 71점 이상 80점 이하라면 C
		return 'C';
	}
	else if (score <= 70 && score >= 61) { //점수가 61점 이상 70점 이하라면 D
		return 'D';
	}
	else if (score <= 60 && score >= 51) { //점수가 51점 이상 60점 이하라면 E
		return 'E';
	}
	else return 'F'; //점수가 50점 이하라면 F
}
void Student::show() { //학생을 정보를 출력하는 함수
	cout << getName() << " ," << getDept() << ", " << getGrade() << endl;
}
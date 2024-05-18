#ifndef SCHOOL_H
#define SCHOOL_H
#include "Student.h"
class School {
	string name; // 학교 이름
	Student* p; // 배열 포인터
	int size; // 입학생 수
	void searchByName();
	void showAll(); // 모든 학생들 출력
	void read(); // 모든 학생의 이름과 학과, 점수 입력
public:
	School(string name);
	~School();
	void run(); // 입학관리프로그램을 시작하는 함수
};
#endif
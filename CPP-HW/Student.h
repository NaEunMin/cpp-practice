#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student {
	string name;
	string dept;
	int score;
public:
	Student();
	void set(string name, string dept, int score); //학생 정보를 저장하는 함수
	void changeDept(string dept); //학생의 학과를 변경하는 함수
	string getName(); //학생이름을 리턴하는 함수
	string getDept(); //학생학과를 리턴하는 함수
	char getGrade(); // 점수로 학점 계산하여 리턴
	void show(); // 이 학생의 이름, 학과, 학점 출력
};
#endif
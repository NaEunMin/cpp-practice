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
	void set(string name, string dept, int score); //�л� ������ �����ϴ� �Լ�
	void changeDept(string dept); //�л��� �а��� �����ϴ� �Լ�
	string getName(); //�л��̸��� �����ϴ� �Լ�
	string getDept(); //�л��а��� �����ϴ� �Լ�
	char getGrade(); // ������ ���� ����Ͽ� ����
	void show(); // �� �л��� �̸�, �а�, ���� ���
};
#endif
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student() { //��ü�迭�� ����ϹǷ� �⺻�����ڰ� �ʿ���

}
void Student::set(string name, string dept, int score) { //�л� ������ �����ϴ� �Լ�
	this->name = name;
	this->dept = dept;
	this->score = score;
}
void Student::changeDept(string dept) { //�а��� �����ϴ� �Լ�
	this->dept = dept;
}
string Student::getName() { //�̸��� �����ϴ� �Լ�
	return name;
}
string Student::getDept() { //�а��� �����ϴ� �Լ�
	return dept;
}
char Student::getGrade() { //�л� ������ ���� ����� �����ϴ� �Լ�
	if (score >= 91) { //������ 91�� �̻��̶�� A
		return 'A';
	}
	else if (score <= 90 && score >= 81) { //������ 81�� �̻� 90�� ���϶�� B
		return 'B';
	}
	else if (score <= 80 && score >= 71) { //������ 71�� �̻� 80�� ���϶�� C
		return 'C';
	}
	else if (score <= 70 && score >= 61) { //������ 61�� �̻� 70�� ���϶�� D
		return 'D';
	}
	else if (score <= 60 && score >= 51) { //������ 51�� �̻� 60�� ���϶�� E
		return 'E';
	}
	else return 'F'; //������ 50�� ���϶�� F
}
void Student::show() { //�л��� ������ ����ϴ� �Լ�
	cout << getName() << " ," << getDept() << ", " << getGrade() << endl;
}
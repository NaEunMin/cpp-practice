#include <iostream>
#include <string>
#include "School.h"
using namespace std;

School::School(string name) {
	this->name = name; //�б��� �̸��� ����
}
School::~School() {//�����ߴ� School�� ��ü�� �Ҹ��ϸ鼭 ���α׷� ���Ḧ �˸�
	cout << " *****" << this->name << "�� ���� ���� ���α׷��� �����մϴ� *****" << endl;
	delete[] p; //���� �����ߴ� p�� ��ȯ
}
void School::run() { //�л� ���а��� ���α׷� �����Լ�
	int size; //�Է¹��� ���л� ��;
	cout << " *****" << this->name << "�� ���� ���� ���α׷��Դϴ�.*****" << endl;
	cout << "���л� ��>>";
	cin >> size;
	this->size = size; //������� size�� �Է¹��� size�� ������
	p = new Student[size]; //�л� �迭�� �������� ����
	cout << "***** ���л��� �̸��� �а�, ������ �Է��մϴ�.*****" << endl;
	read(); //�л� ������ �Է���
	searchByName(); //�̸����� �л��� ã��
	showAll(); //��� �л� ������ ���
}

void School::searchByName() { //�л� �̸��� �Է¹޾� �л��� ������ ����ϴ� �Լ�
	string name;
	bool check; //�л��� �ִ��� ������ üũ�ϴ� ����
	cout << "***** �̸����� �˻��ϸ� ������ ����մϴ�. *****" << endl;
	while (true) { //�̸��� �Է¹޾� �л��� �˻�, �̸��� '�׸�'�̶�� �Է��ϸ� �л��˻� ����
		cout << "�̸� >>";
		cin >> name;
		if (name == "�׸�") {
			cout << "�˻��� �����մϴ�." << endl;
			break;
		}
		for (int i = 0; i < size; i++) { //�л��� �� ��ŭ �˻��� ����
			if (p[i].getName() == name) {
				cout << name << "��(��)" << p[i].getGrade() << "�Դϴ�." << endl;
				check = true; //�л��� �����Ѵٸ� true
				break; //�л��� �����Ѵٸ� �� �̻� �˻��� �������� �ʾƵ� �ǹǷ� break
			}
			else check = false; // �л��� �������� �����Ƿ� false
		}
		if (check == false) { //�л��� �������� ������ �����
			cout << name << " �л��� �������� �ʽ��ϴ�." << endl;
		}
	}
}
void School::showAll() { //��ü �л��� ������ ����ϴ� �Լ�
	cout << "***** ��ü �л��� ����մϴ� *****" << endl;
	for (int i = 0; i < size; i++) {
		p[i].show(); //�л� ���� ������ ���
	}
}
void School::read() { //�л����� ������ �Է��ϴ� �Լ�
	string name;
	string dept;
	int score;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << " : �̸�, �а�, ���� >>";
		cin >> name >> dept >> score;
		p[i].set(name, dept, score); //�л� ���� ������ �Է�
	}
}
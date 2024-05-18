#include <iostream>
using namespace std;
#include "ScheduleSCAN.h"
ScheduleSCAN::ScheduleSCAN(string name,int floor[], int current) :
	Schedule(name, floor, current) {} //Schedule �����ڷ� �ʱ�ȭ�� �Ѵ�.
void ScheduleSCAN::run() {
	int distance; //���� ���� ���� ���� �Ÿ��� �����ϴ� ����
	int topFloor; //�Է��� 5���� ������ ���� ���� ���� �����ϴ� ����
	int nextFloor; //�������� �� ���� �����ϴ� ����
	int check = 0; //���������Ͱ� �Է��� �� �� �ְ����� �����ߴ��� ���ߴ��� üũ�ϴ� ����, �����ߴٸ� 1, �������� ���ߴٸ� 0
	topFloor = floor[0]; //���� ù��°�� �Է��� ������ �ʱ�ȭ
	showMessage();
	showCurrent(); // ���� ���������� ��ġ�� ����Ѵ�.
	showFloor(); // ���� ��û�� ������ ����Ѵ�.
	for (int i = 0; i < 5; i++) {
		if (topFloor < floor[i]) { //���� ���� ���ϴ� ���� ���ݱ����� �ְ������� ���ٸ�
			topFloor = floor[i]; //topFloor�� ���� ���ϴ� ���� ����
		}
	}

	for (int j = 0; j < 5; j++) {
		int minDistance = 100; //���� �ּҰŸ��� �ִ� ���� �˾Ƴ������� �Ÿ��� �����ϴ� ����

		if (check != 1) { //���������Ͱ� �Է��� �� �� �ְ��߿� �������� ���ߴٸ�
			for (int i = 0; i < 5; i++) {
				if (current < floor[i]) {//������������ ������ ����� ������ �Ͽ����Ƿ� ���纸�� ū ���� �񱳸� �Ѵ�.
					distance = abs(floor[i] - current); //abs�� ���밪�� �˷���
					if (minDistance > distance) {
						minDistance = distance;
						nextFloor = i;
					}
				}
			}
		}
		else if (check == 1) { //���������Ͱ� �Է��� �� �� �ְ����� �����߾��ٸ�
			for (int i = 0; i < 5; i++) {
				if (floor[i] == 0) distance = 100; //�̹� �̵��� ���� �񱳸� �Ѵٸ� distance���� 100���� �����Ͽ� minDistance�� ������ ��ġ�� ���ϰ���
				else { //floor[i]�� 0�� �ƴ϶��
					distance = abs(floor[i] - current); // abs()�� ���밪�� ����
					if (minDistance > distance) { //���� ��������� �ּҰŸ�(minDistance)�� ���� ���� ������ �Ÿ�(distance)���� ũ�ٸ�
						minDistance = distance; //���� ���� ������ �Ÿ��� minDistance�� ����
						nextFloor = i;//������� ���� ����� ���� �ε����� ������
					}
				}
			}
		}
		cout << floor[nextFloor] << "������ ���ϴ�." << ' '; // �̵��ϴ� ���� ����Ѵ�.
		movingDistance += minDistance; // �̵� �Ÿ��� �����Ѵ�.
		current = floor[nextFloor]; // ���� ���� ��ġ�� �����Ѵ�.
		if (current == topFloor) check = 1;//���������Ͱ� �Է��� �� �� �ְ� ���� �����ߴٸ� 1
		floor[nextFloor] = 0;//�̵��� ���� �˾Ƴ��� ���� �̵��� ���� 0���� ����
		cout << "���� �̵� �Ÿ��� " << getMovingDistance() << endl;
	}
	showCurrent(); // ���� ���������� ��ġ�� ����Ѵ�.
	cout << "�� �̵� �Ÿ��� " << getMovingDistance() << endl;
}
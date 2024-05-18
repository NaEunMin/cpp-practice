#include <iostream>
using namespace std;
#include "ScheduleSMDF.h"
ScheduleSMDF::ScheduleSMDF(string name, int floor[], int current)
	: Schedule(name, floor, current)
{ } //Schedule �����ڷ� �ʱ�ȭ�� �Ѵ�.
void ScheduleSMDF::run() {
	int distance; //���� ���� ���� ���� �Ÿ��� �����ϴ� ����
	int minFloor; //������� ���� ����� ���� �ε����� �����ϱ� ���� ����
	showMessage();
	showCurrent(); // ���� ���������� ��ġ�� ����Ѵ�.
	showFloor(); // ���� ��û�� ������ ����Ѵ�.
	for (int j = 0; j < 5; j++) {
		int minDistance = 100; //���� �ּҰŸ��� �ִ� ���� �˾Ƴ������� �Ÿ��� �����ϴ� ����
		for (int i = 0; i < 5; i++) {
			if (floor[i] == 0) distance = 100; //�̹� �̵��� ���� �񱳸� �Ѵٸ� distance���� 100���� �����Ͽ� minDistance�� ������ ��ġ�� ���ϰ���
			else { //floor[i]�� 0�� �ƴ϶��
				distance = abs(floor[i] - current); // abs()�� ���밪�� ����
				if (minDistance > distance) { //���� ��������� �ּҰŸ�(minDistance)�� ���� ���� ������ �Ÿ�(distance)���� ũ�ٸ�
					minDistance = distance; //���� ���� ������ �Ÿ��� minDistance�� ����
					minFloor = i;//������� ���� ����� ���� �ε����� ������
				}
			}
		}
		cout << floor[minFloor] << "������ ���ϴ�." << ' '; // �̵��ϴ� ���� ����Ѵ�.
		movingDistance += minDistance; // �̵� �Ÿ��� �����Ѵ�.
		current = floor[minFloor]; // ���� ���� ��ġ�� �����Ѵ�.
		floor[minFloor] = 0;//�̵��� ���� �˾Ƴ��� ���� �̵��� ���� 0���� ����
		cout << "���� �̵� �Ÿ��� " << getMovingDistance() << endl;
	}
	showCurrent(); // ���� ���������� ��ġ�� ����Ѵ�.
	cout << "�� �̵� �Ÿ��� " << getMovingDistance() << endl;
}

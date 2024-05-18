#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule { // 추상 클래스
protected:
	string name; // 스케줄 알고리즘 이름
	int floor[5]; // 목적하는 층 번호 5개 저장
	int current; // 엘리베이트가 있는 현재 층 번호
	int movingDistance = 0; // 총 이동거리. 0으로 초기화
public:
	Schedule(string name, int floor[], int current = 0);
	int getMovingDistance(); // 총 이동 거리 movingDistance 리턴
	virtual void run() = 0; // 스케줄을 시작한다. 상속받는 클래스에서 반드시 작성필요
	void showMessage();
	void showFloor();
	void showCurrent();
	static const int MAX_FLOOR = 30; // 최대 30층
};

#endif
#include <iostream>
using namespace std;

#include "ScheduleFCFS.h"

ScheduleFCFS::ScheduleFCFS(string name, int floor[], int current)
	: Schedule(name, floor, current)
{ }

// 도착한 순서대로 엘리베이트를 이동시킨다.
void ScheduleFCFS::run() {
	showMessage();
	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	showFloor(); // 현재 요청된 층들을 출력한다.

	for (int i = 0; i < 5; i++) {
		int distance = abs(floor[i] - current); // abs()는 절대값을 리턴
		cout << floor[i] << "층으로 갑니다." << ' '; // 이동하는 층을 출력한다.
		movingDistance += distance; // 이동 거리를 누적한다.
		current = floor[i]; // 현재 층의 위치를 갱신한다.
		cout << "누적 이동 거리는 " << getMovingDistance() << endl;
	}

	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	cout << "총 이동 거리는 " << getMovingDistance() << endl;
}
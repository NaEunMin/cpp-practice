#include <iostream>
using namespace std;
#include "ScheduleSMDF.h"
ScheduleSMDF::ScheduleSMDF(string name, int floor[], int current)
	: Schedule(name, floor, current)
{ } //Schedule 생성자로 초기화를 한다.
void ScheduleSMDF::run() {
	int distance; //현재 층과 비교할 층의 거리를 저장하는 변수
	int minFloor; //현재까지 가장 가까운 층의 인덱스를 저장하기 위한 변수
	showMessage();
	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	showFloor(); // 현재 요청된 층들을 출력한다.
	for (int j = 0; j < 5; j++) {
		int minDistance = 100; //가장 최소거리에 있는 층을 알아내기위해 거리를 저장하는 변수
		for (int i = 0; i < 5; i++) {
			if (floor[i] == 0) distance = 100; //이미 이동한 층과 비교를 한다면 distance값을 100으로 설정하여 minDistance에 영향을 미치기 못하게함
			else { //floor[i]가 0이 아니라면
				distance = abs(floor[i] - current); // abs()는 절대값을 리턴
				if (minDistance > distance) { //만약 현재까지의 최소거리(minDistance)가 현재 비교할 층과의 거리(distance)보다 크다면
					minDistance = distance; //현재 비교한 층과의 거리를 minDistance에 저장
					minFloor = i;//현재까지 가장 가까운 층의 인덱스를 저장함
				}
			}
		}
		cout << floor[minFloor] << "층으로 갑니다." << ' '; // 이동하는 층을 출력한다.
		movingDistance += minDistance; // 이동 거리를 누적한다.
		current = floor[minFloor]; // 현재 층의 위치를 갱신한다.
		floor[minFloor] = 0;//이동한 층을 알아내기 위해 이동한 층을 0으로 변경
		cout << "누적 이동 거리는 " << getMovingDistance() << endl;
	}
	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	cout << "총 이동 거리는 " << getMovingDistance() << endl;
}

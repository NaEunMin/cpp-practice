#include <iostream>
using namespace std;
#include "ScheduleSCAN.h"
ScheduleSCAN::ScheduleSCAN(string name,int floor[], int current) :
	Schedule(name, floor, current) {} //Schedule 생성자로 초기화를 한다.
void ScheduleSCAN::run() {
	int distance; //현재 층과 비교할 층의 거리를 저장하는 변수
	int topFloor; //입력한 5개의 층에서 가장 높은 층을 저장하는 변수
	int nextFloor; //다음으로 갈 층을 저장하는 변수
	int check = 0; //엘리베이터가 입력한 층 중 최고층을 도달했는지 안했는지 체크하는 변수, 도착했다면 1, 도착하지 못했다면 0
	topFloor = floor[0]; //가장 첫번째로 입력한 층으로 초기화
	showMessage();
	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	showFloor(); // 현재 요청된 층들을 출력한다.
	for (int i = 0; i < 5; i++) {
		if (topFloor < floor[i]) { //만약 현재 비교하는 층이 지금까지의 최고층보다 높다면
			topFloor = floor[i]; //topFloor에 현재 비교하는 층을 저장
		}
	}

	for (int j = 0; j < 5; j++) {
		int minDistance = 100; //가장 최소거리에 있는 층을 알아내기위해 거리를 저장하는 변수

		if (check != 1) { //엘리베이터가 입력한 층 중 최고중에 도착하지 못했다면
			for (int i = 0; i < 5; i++) {
				if (current < floor[i]) {//엘리베이터의 방향은 위라고 가정을 하였으므로 현재보다 큰 층과 비교를 한다.
					distance = abs(floor[i] - current); //abs는 절대값을 알려줌
					if (minDistance > distance) {
						minDistance = distance;
						nextFloor = i;
					}
				}
			}
		}
		else if (check == 1) { //엘리베이터가 입력한 층 중 최고층에 도착했었다면
			for (int i = 0; i < 5; i++) {
				if (floor[i] == 0) distance = 100; //이미 이동한 층과 비교를 한다면 distance값을 100으로 설정하여 minDistance에 영향을 미치기 못하게함
				else { //floor[i]가 0이 아니라면
					distance = abs(floor[i] - current); // abs()는 절대값을 리턴
					if (minDistance > distance) { //만약 현재까지의 최소거리(minDistance)가 현재 비교할 층과의 거리(distance)보다 크다면
						minDistance = distance; //현재 비교한 층과의 거리를 minDistance에 저장
						nextFloor = i;//현재까지 가장 가까운 층의 인덱스를 저장함
					}
				}
			}
		}
		cout << floor[nextFloor] << "층으로 갑니다." << ' '; // 이동하는 층을 출력한다.
		movingDistance += minDistance; // 이동 거리를 누적한다.
		current = floor[nextFloor]; // 현재 층의 위치를 갱신한다.
		if (current == topFloor) check = 1;//엘리베이터가 입력한 층 중 최고 층을 도착했다면 1
		floor[nextFloor] = 0;//이동한 층을 알아내기 위해 이동한 층을 0으로 변경
		cout << "누적 이동 거리는 " << getMovingDistance() << endl;
	}
	showCurrent(); // 현재 엘리베이터 위치를 출력한다.
	cout << "총 이동 거리는 " << getMovingDistance() << endl;
}
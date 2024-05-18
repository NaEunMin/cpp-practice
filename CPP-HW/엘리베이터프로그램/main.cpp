#include <iostream>
using namespace std;

#include "ScheduleFCFS.h"
#include "ScheduleSMDF.h"
#include "ScheduleSCAN.h"

int main() {
	int current = 10; //현재 층 수를 저장하는 변수
	int floor[5] = { 0 };//이동할 층 수를 저장하는 정수 배열
	cout << "엘리베이터는 " << Schedule::MAX_FLOOR << "층까지만 갑니다." << endl;
	cout << "현재 층은 " << current << "층입니다." << endl;
	cout << "가고자하는 순서대로 5개 층을 입력하세요(";
	cout << "0이하, 31이상, 현재 층, 이전과 동일한 층 입력 금지)>>";
	for (int i = 0; i < 5; i++) { // 5개 정수 입력
		cin >> floor[i];
	}

	// FCFS(First Come First Served). 입력한 순서대로 엘리베이터 이동
	ScheduleFCFS fcfs("FCFS", floor, current);
	fcfs.run();

	// SMDF(Shortest Moving Distance First). 현재 위치에서 가장 가까운 층으로 이동
	ScheduleSMDF smdf("SMDF", floor, current);
	smdf.run();

	// SCAN. 이동 방향에서 가장 가까운 층으로 이동. 끝까지 가면 방향 전환
	// 시작은 현재 엘리베이터가 있는 위치에서 위쪽 방향
	ScheduleSCAN scan("SCAN", floor, current);
	scan.run();
}
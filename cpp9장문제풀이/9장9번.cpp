#include <iostream>
using namespace std;
class Printer {
protected:
	string model;
	string manu;
	int printedCount;
	int availableCount;
public:
	Printer() {}
	Printer(string model, string manu, int availableCount) {
		this->model = model;
		this->manu = manu;
		this->availableCount = availableCount;
		this->printedCount = 0;
	}
	virtual void print(int pages) {}
	virtual void show() {}
	void run();
};


class InkJetPrinter : public Printer {
	int availableInk;
public:
	InkJetPrinter(string model, string manu, int availableCount, int availableInk) : Printer(model, manu, availableCount) {
		this->availableInk = availableInk;
	}
	virtual void print(int pages);
	virtual void show();
};
void InkJetPrinter::print(int pages) {
	if (availableCount < pages || availableInk < pages) {
		cout << "용지 혹은 잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
	else {
		availableInk -= pages;
		availableCount -= pages;
		cout << "프린트하였습니다." << endl;
	}
}
void InkJetPrinter::show() {
	cout << "잉크젯 : " << model << ", " << manu << ", " << "남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
}


class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manu, int availableCount, int availableToner) : Printer(model, manu, availableCount) {
		this->availableToner = availableToner;
	}
	virtual void print(int pages);
	virtual void show();
};
void LaserPrinter::print(int pages) {
	if (availableCount < pages || availableToner < pages) {
		cout << "용지 혹은 토너가 부족하여 프린트할 수 없습니다." << endl;
	}
	else {
		availableToner -= pages;
		availableCount -= pages;
		cout << "프린트하였습니다." << endl;
	}
}
void LaserPrinter::show() {
	cout << "레이저 : " << model << ", " << manu << ", " << "남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
}


void Printer::run() {
	InkJetPrinter *inkjet = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter *laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	inkjet->show();
	laser->show();

	int printerNumber, pages;
	while (true) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> printerNumber >> pages;
		if (printerNumber == 1) {
			inkjet->print(pages);
			inkjet->show();
			laser->show();
		}
		else if (printerNumber == 2) {
			laser->print(pages);
			inkjet->show();
			laser->show();
		}
		char choice;
		cout << "계속 프린트하시겠습니까?(y/n)";
		cin >> choice;
		if (choice == 'n') {
			delete inkjet;
			delete laser;
			break;
		}
	}
}
int main() {
	Printer* printer = new Printer;
	printer->run();
	delete printer;
}

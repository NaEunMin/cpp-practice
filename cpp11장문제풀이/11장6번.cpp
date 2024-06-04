#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	cout << left << setw(15) << "Number";
	cout << left << setw(15) << "Square";
	cout << left << setw(15) << "Square Root";
	cout << endl;
	for (int i = 0; i <= 45; i += 5) {
		cout << left << setw(15) << setfill('_') << i;
		cout << left << setw(15) << setfill('_') << i*i;
		cout << left << setw(15) << setfill('_') << setprecision(3) <<sqrt((double)i);
		cout << endl;
	}
}

#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
int vec[1000001];
bool apare = false;
void cb() {
	int st = 1,
		dr = 1000000;
	int mij = 0;
	while (st <= dr) {
		mij = (st + dr) / 2;
		if (vec[mij] == 19000000) {
			apare = true;
			return;
		}
		else if (vec[mij] > 19000000) dr = mij - 1;
		else st = mij + 1;
	}
	return;
}
void cautare_secv() {
	for (int i = 1; i <= 1000000; ++i) 
		if (vec[i] == 19000000) {
			apare = true;
			return;
		}
}
int main() {
	for (int i = 1; i <= 1000000; ++i) 
		vec[i] = i*(int)log2(i); 
	auto start = high_resolution_clock::now();
	cb();
	auto stop = high_resolution_clock::now();
	auto timp = duration_cast<nanoseconds>(stop - start);
	cout << (apare == 1);
	cout << "\nnanosecunde: "<<timp.count() << "\nsecunde: " << 
		timp.count() * std::pow(10,-9);

	apare = false;

	start = high_resolution_clock::now();
	cautare_secv();
	stop = high_resolution_clock::now();
	timp = duration_cast<nanoseconds>(stop - start);
	cout << '\n'<<(apare == 1);
	cout << "\nnanosecunde: " << timp.count() << "\nsecunde: " <<
		timp.count() * std::pow(10, -9);

	return  0;
}
#include <iostream>
#include <fstream>
#include <vector>

#define forn(max) for (int q=0; q<max; q++)
using namespace std;

bool withinRange(int val, int min, int max) { // min y max no inclusivo
	if (val > min && val < max) { return true; }
	else { return false; }
}

int main() {
	int N; cin >> N;
	if (withinRange(N, 0, 101)) {
		vector<int[2]> pares;
		forn(N) { // GOL PALO AFUERA
			int x, y; cin >> x; cin >> y;
			if (withinRange(x, -1001, 1001) && withinRange(y, 0, 1001)) {
				if (withinRange(x, 0, 732) && withinRange(y, -1, 232)) { cout << "GOL" << endl; }
				else if (withinRange(y, -1, 232) && x == 0 || withinRange(x, 0, 732) && y == 232 || withinRange(y, -1, 232) && x == 732) {
					cout << "PALO" << endl;
				}
				else { cout << "AFUERA" << endl; }
			}
		}
	}
	return 0;
}
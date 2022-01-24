#include <iostream>
using namespace std;
#define forn(MX) for (int w=1; w<MX; ++w)
bool perfecto(int n) {
	int sum = 0;
	forn(n) { if (n % w == 0) { sum+=w; } }
	return sum == n;
}
int main() {
	int n; cin >> n;
	if (n <= 1000 && n >= 6)
		forn(n+1) { if (perfecto(w)) { cout << w << endl; } }
}
#include <iostream>
#include <vector>
using namespace std;

const int COTA_MAXIMA = 1000;
const int COTA_MINIMA = 1;

int main() {
	int L, n; cin >> L;
	int min = COTA_MAXIMA + 1; int max = COTA_MINIMA - 1; int sum = 0; 
	for (int z = 0; z < L; ++z) {
		cin >> n; sum += n;
		if (n < min) { min = n; }
		else if (n > max) { max = n; }
	}
	cout << max << endl;
	cout << min << endl;
	cout << sum << endl;
}
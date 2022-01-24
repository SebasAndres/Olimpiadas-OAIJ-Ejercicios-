#include <iostream>
using namespace std;
int main() {
	int m, n; cin >> m >> n;
	
	if (!(m >= 1 && m <= 100 && n >= 1 && n <= 100)) { return 0; }

	int** arr = new int*[m]; for (int g = 0; g < m; g++) { arr[g] = new int[n]; }
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int vl; cin >> vl;
			if (vl >= 1 && vl <= 100) { arr[i][j] = vl; }
			else { return 0; };
		}
	}
	for (int p = 0; p < n; ++p) {
		for (int v = 0; v < m; ++v) {
			cout << arr[v][p] << " ";
		}
		cout << endl;
	}
}
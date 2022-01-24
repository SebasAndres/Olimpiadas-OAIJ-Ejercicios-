#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> vcc {a, b, c, d};
	vector<int> bff[4];
	int mDif = abs(vcc[0]+vcc[1]-vcc[2]-vcc[3]);
	do {
		int df = abs(vcc[0] + vcc[1] - vcc[2] - vcc[3]);
		if (mDif > df) { mDif = df; }
	} while (next_permutation(vcc.begin(), vcc.end()));

	cout << mDif << endl;
}

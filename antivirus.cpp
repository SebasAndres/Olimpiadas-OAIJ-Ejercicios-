#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#define forn(MAX) for (int q=0; q<MAX; q++)
int main() {
	int size; char a, b; cin >> size >> a >> b;
	vector<char> arr; forn(size) { char vl; cin >> vl; arr.push_back(vl); }
	if (!(a != 'ñ' && b != 'ñ' && size <= 255)) { return 0; }
	if (size == 0) { string rd; cin >> rd; return 0; }
	vector<int> indexes; 
	for (int z = 2; z < arr.size(); ++z) {
		if (arr[z-2] == arr[z] && arr[z] == a && arr[z-1] == b) { indexes.push_back(z-1-indexes.size()); }
	}
	int u = 0;
	for (int j : indexes) { arr.erase(arr.begin()+j); }
	string out; forn(arr.size()) { out += arr[q]; }
	cout << arr.size() << endl; cout << out << endl;
}
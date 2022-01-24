#include <iostream>
#include <string>
using namespace std;
int main() {
	string in; cin >> in;
	int c; cin >> c;
	in[c-1] = 'X';
	cout << in << endl;
}
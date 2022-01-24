#include <iostream>
#include <string>
using namespace std;
int main () {
	string in; cin >> in;
	cout << string(in.size() + 2, '*') << endl;
	cout << '*' << in << '*' << endl;
	cout << string(in.size() + 2, '*') << endl;
}
#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b, rdo;
	cin >> a >> b;
	rdo = a * b;
	cout << string(4 - to_string(a).size(), ' ') << a << endl;
	cout << "x" << string(3 - to_string(b).size(), ' ') << b << endl;
	cout << "----" << endl;
	cout << string(4 - to_string(rdo).size(), ' ') << rdo << endl;
}
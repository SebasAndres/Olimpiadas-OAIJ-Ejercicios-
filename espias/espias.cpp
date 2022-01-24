#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define forn(L) for (int q=0; q<L; ++q)

bool existe(string s, string msj) {
	bool rt = false;
	bool add = false;
	string acc; int cnt;

	forn (msj.size()) {
		if (msj[q] == s[0] && acc.size() == 0) { add = true; cnt = 0; }
		if (add) {
			if (acc.size() != s.size()) {
				if (s[acc.size()] == msj[q]) { acc += msj[q]; ++cnt; }
				else { 
					if (msj[q] == s[0]) { add = true; cnt = 1; acc = s[0]; }
					else { add = false; cnt = 0; acc = ""; }
				}
			}
		}
		if (cnt == s.size()) { if (s == acc) { rt = true; } else { acc = ""; } }
	}
	return rt;
}


int main(){
	ifstream cin("mensajes.in");
	ofstream cout("mensajes.out");

	int L; cin >> L;
	string msj; char p;
	forn(L) { cin >> p; msj += p; }
	string ppl; cin >> ppl;
	
	char dir = 'I';
	bool rt = false;

	if (existe(ppl, msj)) {
		rt = true;
	}
	else {
		for (int k = 0; k < int(L/2); ++k) { swap(msj[k], msj[(L-1) - k]); }
		if (existe(ppl, msj)) {
			dir = 'D';
			rt = true;
		}
	}

	if (rt) { cout << "SI" << endl; cout << dir << endl; }
	else { cout << "NO" << endl; }
}
/* INPUT EJEMPLO:
3 4 5
sopa
dele
tras
tra
sopa
letras
aes
reo
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

#define forn(MAX) for (int w=0; w<MAX; w++)

string von_bis(string pal, int beg, int end) {
	string buff = "";
	for (int n = beg; n < end; n++) { buff += pal[n]; }
	return buff;
}

bool contains(string large, string pal, string t) {
	if (large.size() >= pal.size()) {
		for (int n = 0; n < large.size() - pal.size() + 1; n++) {
			if (von_bis(large, n, n + pal.size()) == pal) { return true; }
		}
	}
	return false;
}

int D (int N, int M) { // Numero de diagonales (1 sentido) en un cuadrante N x M
	return 1 + N - 2 + M - 2;
}

int main() {

	ifstream cin("input.in");
	int N, M, K;
	vector<string> palabras, sopa_horizontal, sopa_vertical, sopa_diagonal;
	cin >> N >> M >> K;
	forn(N) { string sh; cin >> sh; sopa_horizontal.push_back(sh); }
	forn(K) { string pal; cin >> pal;  palabras.push_back(pal); }

	// Palabras leidas de derecha a izquierda
	for (int i = 0; i < N; i++) {
		string line = sopa_horizontal[i];
		string new_line = "";
		forn(M) { new_line += line[M-1-w]; } 
		sopa_horizontal.push_back(new_line);
	}

	// Palabras de arriba a bajo y viceversa
	forn(M) {
		string up_down = ""; string down_up = "";
		for (int r = 0; r < N; r++) {
			up_down += sopa_horizontal.at(r)[w]; 	  // Desde arriba para abajo 
			down_up += sopa_horizontal.at(N-r-1)[w];  // Desde abajo para arriba
		}
		sopa_vertical.push_back(up_down);
		sopa_vertical.push_back(down_up);
	}

	#pragma region Palabras en diagonal	
	// a. N (horizontal) a M (vertical)
	for (int s = 0; s < N - 1; s++){
		string N_to_M = "";
		for (int t = 0; t <= s + 1; t++) {
			N_to_M += sopa_horizontal.at(t)[s-t+1];
		}
		sopa_diagonal.push_back(N_to_M);
	}
	// a. M (vertical) a N (horizontal)
	for (int s = 0; s < M-2; s++) {
		string M_to_N = "";
		for (int t = 0; t < M-1-s; t++) {
			M_to_N += sopa_horizontal.at(1+t+s)[N-1-t];
		}
		sopa_diagonal.push_back(M_to_N);
	}
	// Diagonal principal
	string txt = "";
	for (int p = 0; p < N; p++) { txt += sopa_horizontal.at(p)[p]; }
	sopa_diagonal.push_back(txt);

	// Invertidos
	for (int z = 0; z < D(M,N)+1; z++) {
		string inv = "";
		string pal = sopa_diagonal.at(z);
		forn(pal.size()) { 
			if (pal[pal.size() - 1 - w] != ' ')
				inv += pal[pal.size()-1-w];
		}
		sopa_diagonal.push_back(inv);
	}
	#pragma endregion

	int enn = 0;
	cout << "Palabras" << endl;
	for (string palabra : palabras) { cout << enn << " " << palabra << endl; enn++; }
	cout << endl;

	enn = 0;
	cout << "Horizontal" << endl;
	for (string palabra : sopa_horizontal) { cout << enn << " " << palabra << endl; enn++; }
	cout << endl;

	enn = 0;
	cout << "Vertical" << endl;
	for (string palabra : sopa_vertical) { cout << enn << " " << palabra << endl; enn++; }
	cout << endl;

	enn = 0;
	cout << "Diagonal" << endl;
	for (string palabra : sopa_diagonal) { cout << enn << " " << palabra << endl; enn++; }
	cout << endl;


	vector<string> res;
	forn(K) { res.push_back("NO"); }
	
	int u = 0;
	for (string pal : palabras) {
		for (string sh : sopa_horizontal) {
			if (contains(sh, pal, "H")) { res.at(u) = "SI"; break; }
		}
		for (string sv : sopa_vertical) {
			if (contains(sv, pal, "V")) { res.at(u) = "SI"; break; }
		}
		for (string sd : sopa_diagonal) {
			if (contains(sd, pal, "D")) { res.at(u) = "SI"; break; }
		}
		u++;
	}

	for (string j : res) { cout << j << endl; }

	return 0;
}
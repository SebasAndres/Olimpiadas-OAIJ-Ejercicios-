#include <iostream>
#include <deque>
using namespace std;

#define forn(max) for (int w=0; w<max; w++)

void printDeque(deque<int> arreglo) {
	forn(arreglo.size()) { cout << arreglo.at(w) << " "; }
	cout << endl;
}

bool contiene(deque<int> arreglo, int elemento) {
	forn(arreglo.size()) { if (arreglo.at(w) == elemento) return true; }
	return false;
}

int main() {
	int N, Q; cin >> N >> Q;
	deque<int> hilera; deque<int> diferencias; deque<int> distintosMenorK;
	forn(N) { int n; cin >> n; hilera.push_back(n); }
	forn(Q) {
		// Movimiento
		int t, L, R, K;
		cin >> t >> L >> R >> K;
		L--; R--;
		if (t == 1 && K == 0) { hilera[L] = R; } // Evento tipo 1 
		else if (t == 2) { // Evento tipo 2
			int max_intervalo = hilera[L]; int min_intervalo = hilera[L];
			for (int d = L; d <= R; d++) {
				if (hilera.at(d) > max_intervalo) max_intervalo = hilera.at(d);
				else if (hilera.at(d) < min_intervalo) min_intervalo = hilera.at(d);
			}
			int dif = max_intervalo - min_intervalo;
			diferencias.push_back(dif);

			int distintosMK_counter = 0;
			deque<int> elegidos;
			forn(N) {
				if (hilera[w] < K && !contiene(elegidos, hilera[w])) {
					distintosMK_counter++;
					elegidos.push_back(hilera[w]);
				}
			}
			distintosMenorK.push_back(distintosMK_counter);
		}
	}
	printDeque(diferencias);
	printDeque(distintosMenorK);
	return 0;
}



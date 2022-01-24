#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Region {
	char color;
	vector<int[2]> pixeles; // [j,i]
	list<char> limites;
};

vector<Region> regiones;
const int N = 4;
char C[N][N] = { {'A', 'A', 'R', 'R'},
				 {'A', 'A', 'A', 'R'},
				 {'R', 'A', 'V', 'V'},
				 {'A', 'R', 'V', 'V'} };

int f(int x) {
	if (x < 0) {
		return 0;
	}
	else if (x >= N) {
		return N-1;
	}
}

void paint(char grid[N][N], vector<Region> regiones, int data[2]) {
	// pintar y tomar minimos movimientos
	int minimo_repeticiones = regiones.size() - 1;
	cout << "El minimo de repeticiones es: " << minimo_repeticiones << endl;
	cout << ": ";

	int empty;
	cin >> empty;
}

bool AllGrid(char color) {
	bool retorno = true;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (C[j][i] != color) {
				retorno = false;
			}
		}
	}
	return retorno;
}

list<char> delete_repeated(list<char> original) {
	list <char> nlist;
	for (char c : original) {
		if (find(original.begin(), original.end(), c) == original.end()) {
			nlist.push_back(c);
		}
	}
	return nlist;
}

list<char> get_limits(Region r) {
	list<char> limites;
	char color = r.color;
	for (int *pixl : r.pixeles) {
		int j = pixl[0];
		int i = pixl[1];

		// Misma fila
		if (C[f(j + 1)][i] != color) {
			limites.push_back(C[f(j + 1)][i]);
		}
		else if (C[f(j - 1)][i] != color) {
			limites.push_back(C[f(j - 1)][i]);
		}

		if (C[j, f(i + 1)][i] != color) {
			limites.push_back(C[j][f(i + 1)]);
		}
		else if (C[j][f(i - 1)] != color) {
			limites.push_back(C[j][f(i - 1)]);
		}
	};

	limites = delete_repeated(limites);
	return limites;
}

bool inReg(char color, int j, int i) {
	bool retorno = false;
	if (regiones.size() > 0) {
		for (Region reg : regiones)
		{
			if (reg.color == color) {
				for (int* pxl : reg.pixeles) {
					if (pxl[0] == j && pxl[1] == i + 1) {
						reg.pixeles.push_back({ j, i });
						retorno = true;
					}
					else if (pxl[0] == j + 1 && pxl[1] == i) {
						reg.pixeles.push_back({ j, i });
						retorno = true;
					}
				}
			}
		}
	}
	else {
		retorno = false;
	}
	return retorno;
}

void pixeles() {

	for (int j = 0; j < N; j++) { // lectura horizontal 
		for (int i = 0; i < N; i++) {

			if (inReg(C[j][i], j, i)) {// ¿C[j,i] pertenece a una region > 1
				// la funcion ya añade a C en la region
			}
			else {
				Region nueva_region;
				nueva_region.color = C[j][i];
				nueva_region.pixeles.push_back({ j,i });
			}

		}
	}
	
	int data[2];
	
	int max, contador = 0;
	int min = regiones[0].pixeles.size();
	int bigger, smaller;
	for (Region r: regiones) {
		r.limites = get_limits(r);
		if (r.pixeles.size() >= max) {
			bigger = contador;
			max = r.pixeles.size();
		}
		else if (r.pixeles.size() <= min) {
			smaller = contador;
			min = r.pixeles.size();
		}

		data[0] = bigger;
		data[1] = smaller;

	}

	while (AllGrid('A')) {
		paint(C, regiones, data);
	}
}

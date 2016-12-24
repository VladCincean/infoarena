#include <fstream>

using namespace std;

// 0 x - cea mai mare pozitie pe care se afla un element cu
// valoarea x sau -1 daca aceasta valoare nu se gaseste in sir
int question_0(long* S, int size, long x) {
	int res = -1;
	int st = 0;
	int dr = size - 1;
	while (st <= dr) {
		int m;

		m = st + (dr - st) / 2;
		if (S[m] == x) {
			res = m;
		}
		if (S[m] <= x) {
			st = m + 1;
		}
		else {
			dr = m - 1;
		}
	}

	if (res > -1)
		res++;

	return res;
}

// 1 x - cea mai mare pozitie pe care se afla un element cu valoarea mai mica
// sau egala cu x in sir. Se garanteaza ca cel mai mic numar al sirului este mai mic sau egal decat x 
int question_1(long* S, int size, long x) {
	int res = 0;
	int st = 1;
	int dr = size - 1;

	while (st <= dr) {
		int m;

		m = st + (dr - st) / 2;
		if (S[m] <= x) {
			st = m + 1;
			res = m;
		}
		else {
			dr = m - 1;
		}
	}

	return res + 1;
}

// 2 x - cea mai mica pozitie pe care se afla un element cu valoarea mai mare
// sau egala cu x in sir. Se garanteaza ca cel mai mare numar din sir este mai mare sau egal decat x
int question_2(long* S, int size, long x) {
	int res = size - 1;
	int st = 0;
	int dr = size - 2;

	while (st <= dr) {
		int m;

		m = st + (dr - st) / 2;
		if (S[m] >= x) {
			dr = m - 1;
			res = m;
		}
		else {
			st = m + 1;
		}
	}

	return res + 1;
}

int main() {
	int N;
	long *S;
	int M;
	int q;
	long x;

	// input
	ifstream f("cautbin.in");
	f >> N;
	S = new long[N];
	for (int i = 0; i < N; i++) {
		f >> S[i];
	}
	f >> M;

	// solve + output
	ofstream g("cautbin.out");
	while (M--) {
		f >> q >> x;
		if (q == 0) {
			g << question_0(S, N, x) << '\n';
		}
		else if (q == 1) {
			g << question_1(S, N, x) << '\n';
		}
		else if (q == 2) {
			g << question_2(S, N, x) << '\n';
		}
	}
	f.close();
	g.close();

	// free memory
	delete[] S;

	return 0;
}

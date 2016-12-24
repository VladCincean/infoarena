#include <fstream>
#include <cstring>

#define MAX_VAL 7001

using namespace std;

int main() {
	int n;
	int max = 0;
	int fr[7001];
	int r;

	memset(fr, 0, MAX_VAL);

	// input
	ifstream f("medie.in");
	f >> n;
	for (int i = 0; i < n; ++i) {
		int c;

		f >> c;
		fr[c]++;
		if (c > max) {
			max = c;
		}
	}
	f.close();

	// solve
	r = 0;

	for (int i = 1; i <= max; i++) if (fr[i]) {
		for (int j = 1; j < i && i + j <= max; j++) {
			if (fr[i - j] && fr[i + j]) {
				r += fr[i] * fr[i - j] * fr[i + j];
			}
		}

		if (fr[i] > 2) {
			r += (fr[i] * (fr[i] - 1) * (fr[i] - 2)) / 2; // n * C{n-1, 2}
		}
	}

	// output
	ofstream g("medie.out");
	g << r << '\n';
	g.close();

	return 0;
}

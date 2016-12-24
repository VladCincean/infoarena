#include <fstream>

using namespace std;

int N, K;
int* s;
long long maximum = 0;
long long sum = 0;

bool check(long long C) {
	int i = 0, t = K;
	long long c = 0;
	while (t > 0 && i < N) {
		if (c + s[i] <= C)
			c += s[i++];
		else {
			c = 0;
			t--;
		}
	}
	if (i == N)
		return true;
	return false;
}

long long bin_search(long long st, long long dr) {
	long long m = -1;
	long long ret = -1;

	while (st <= dr) {
		m = st + (dr - st) / 2;
		if (check(m)) {
			ret = m;
			dr = m - 1;
		}
		else
			st = m + 1;
	}

	return ret;
}

int main() {
	long long sol;

	// input
	ifstream f("transport.in");
	f >> N >> K;
	s = new int[N];
	for (int i = 0; i < N; i++) {
		f >> s[i];
		sum += s[i];
		maximum = s[i] > maximum ? s[i] : maximum;
	}
	f.close();

	// solve
	sol = bin_search(maximum, sum);

	// output
	ofstream g("transport.out");
	g << sol << '\n';
	g.close();

	// free memory
	delete[] s;

	return 0;
}

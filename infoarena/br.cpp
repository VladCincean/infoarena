//#include <fstream>
//
//using namespace std;
//
//inline long price_of_beers(long S[], int N, int first, int last) {
//	long res;
//
//	res = S[last];
//	if (first > 0)
//		res -= S[first - 1];
//	if (first > last)
//		res += S[N - 1];
//
//	return res;
//}
//
//inline int solve(long S[], int N, int k, int x) {
//	int st = 0;
//	int dr = N - 1;
//	int ind = -1;
//
//	while (st <= dr) {
//		int m;
//
//		m = st + (dr - st) / 2;
//		if (price_of_beers(S, N, k, (k + m) % N) <= x) {
//			ind = m;
//			st = m + 1;
//		}
//		else {
//			dr = m - 1;
//		}
//	}
//
//	return ind + 1;
//}
//
//int main() {
//	int N, T;
//	short C;
//	int k;
//	long x;
//	long *S;
//
//	// input
//	ifstream f("br.in");
//	f >> N >> T;
//	S = new long[N];
//	f >> C;
//	S[0] = C;
//	for (int i = 1; i < N; i++) {
//		f >> C;
//		S[i] = S[i - 1] + C;
//	}
//	ofstream g("br.out");
//	while (T--) {
//		f >> k >> x;
//		g << solve(S, N, k - 1, x) << '\n';
//	}
//	f.close();
//	g.close();
//
//	// free memory
//	delete[] S;
//
//	return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//#define MOD 1000000007
//
////inline long _abs(long a) {
////	if (a < 0)
////		return -a;
////	return a;
////}
//
//inline void merge(long long* v, int st, int m, int dr) {
//	int n1 = m - st + 1;
//	int n2 = dr - m;
//	int i, j, k;
//	long long *L, *R;
//
//	L = (long long*)malloc(n1 * sizeof(long long));
//	R = (long long*)malloc(n2 * sizeof(long long));
//
//	for (i = 0; i < n1; ++i) {
//		L[i] = v[st + i];
//	}
//	for (j = 0; j < n2; ++j) {
//		R[j] = v[m + 1 + j];
//	}
//
//	i = 0; j = 0; k = st;
//	while (i < n1 && j < n2) {
//		if (L[i] <= R[j]) {
//			v[k++] = L[i++];
//		}
//		else {
//			v[k++] = R[j++];
//		}
//	}
//	while (i < n1) {
//		v[k++] = L[i++];
//	}
//	while (j < n2) {
//		v[k++] = R[j++];
//	}
//
//	free(L); free(R);
//}
//
//inline void merge_sort(long long* v, int st, int dr) {
//	if (st < dr) {
//		int m = st + (dr - st) / 2;
//		merge_sort(v, st, m);
//		merge_sort(v, m + 1, dr);
//		merge(v, st, m, dr);
//	}
//}
//
//int main() {
//	int N;
//	long long *v;
//	long long *s;
//	long long result;
//
//	freopen("galagie.in", "r", stdin);
//	freopen("galagie.out", "w", stdout);
//
//	// input
//	scanf("%d", &N);
//	v = (long long*)malloc(N * sizeof(long long));
//	for (int i = 0; i < N; ++i) {
//		scanf("%lld", &v[i]);
//	}
//
//	// sort v + compute partial sums s
//	merge_sort(v, 0, N - 1);
//	s = (long long*)malloc(N * sizeof(long long));
//	s[0] = v[0];
//	for (int i = 1; i < N; ++i) {
//		s[i] = s[i - 1] + v[i];
//	}
//
//	// solve
//	result = ((1 - N)*v[0] + s[N - 1] - s[0]) % MOD;
//	for (int i = 1; i < N; ++i) {
//		result = (result + (2 * i + 1 - N)*v[i] - s[i - 1] + s[N - 1] - s[i]) % MOD;
//	}
//
//	//// solve - brute force
//	//result = 0;
//	//for (int i = 0; i < N; i++) {
//	//	for (int j = 0; j < N; j++) if (i != j) {
//	//		result = (result + _abs(s[i] - s[j])) % MOD;
//	//	}
//	//}
//
//	// output
//	printf("%lld\n", result);
//
//	// free memory
//	free(v);
//	free(s);
//
//	return 0;
//}

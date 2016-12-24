//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#define MAXL 2000004
//#define MAXN 1010
//
//int* compute_prefix_function(char* P, int m) {
//	int* pi;
//	int k, q;
//
//	pi = (int*)malloc((m + 1) * sizeof(int));
//	pi[1] = 0;
//	k = 0;
//	for (q = 2; q <= m; ++q) {
//		while (k > 0 && P[k + 1] != P[q])
//			k = pi[k];
//		if (P[k + 1] == P[q])
//			k = k + 1;
//		pi[q] = k;
//	}
//	return pi;
//}
//
//int kmp_matcher(int* result, char* T, char* P) {
//	int N, n, m, q, i, *pi;
//
//	N = 0;
//	n = strlen(T) - 1;
//	m = strlen(P) - 1;
//	pi = compute_prefix_function(P, m);
//	q = 0;
//	for (i = 1; i <= n; ++i) {
//		while (q > 0 && P[q + 1] != T[i])
//			q = pi[q];
//		if (P[q + 1] == T[i])
//			q = q + 1;
//		if (q == m) {
//			if (N < 1000)
//				result[N] = i - m;
//			N++;
//			q = pi[m];
//		}
//	}
//
//	free(pi);
//
//	return N;
//}
//
//int main() {
//	char *A;
//	char *B;
//	int *result;
//	int N, i;
//
//	freopen("strmatch.in", "r", stdin);
//	freopen("strmatch.out", "w", stdout);
//
//	A = (char*)malloc(MAXL * sizeof(char));
//	B = (char*)malloc(MAXL * sizeof(char));
//	result = (int*)malloc(MAXN * sizeof(int));
//
//	scanf("%s", A);
//	scanf("%s", B);
//
//	A[strlen(A) + 1] = '\0';
//	for (int i = strlen(A); i; --i)
//		A[i] = A[i - 1];
//	A[0] = ' ';
//	B[strlen(B) + 1] = '\0';
//	for (int i = strlen(B); i; --i)
//		B[i] = B[i - 1];
//	B[0] = ' ';
//
//	N = kmp_matcher(result, B, A);
//
//	printf("%d\n", N);
//	for (i = 0; i < N && i < 1000; ++i) {
//		printf("%d ", result[i]);
//	}
//	printf("\n");
//
//	free(A); free(B); free(result);
//
//	return 0;
//}

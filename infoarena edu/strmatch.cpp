//#include <cstdio>
//#include <cstring>
//#define MAXL 200010
//#define MAXN 1000
//
//int	main() {
//	char A[MAXL];
//	char B[MAXL];
//	int	match[MAXN];
//	int a, b, N;
//	int s, i;
//
//	freopen("strmatch.in", "r", stdin);
//	freopen("strmatch.out", "w", stdout);
//
//	scanf("%s %s", &A, &B);
//
//	a = strlen(A);
//	b = strlen(B);
//	N = 0;
//	for (s = 0; s < b - a + 1; ++s) {
//		for (i = 0; i < a; ++i) {
//			if (A[i] != B[s + i])
//				break;
//		}
//		if (i == a) {
//			match[N++] = s;
//		}
//	}
//
//	printf("%d\n", N);
//	for (i = 0; i < N; ++i) {
//		printf("%d ", match[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

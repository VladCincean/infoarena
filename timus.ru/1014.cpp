//#include <cstdio>
//
//inline void intoarce(long long& n) {
//	long long a;
//	a = 0;
//	while (n > 0) {
//		a *= 10;
//		a += n % 10;
//		n /= 10;
//	}
//	n = a;
//}
//
//int main() {
//	long long N, Q;
//	int i;
//
//	scanf("%lld", &N);
//
//	if (N == 0) {
//		Q = 10;
//	}
//	else if (N == 1) {
//		Q = 1;
//	}
//	else {
//		Q = 0;
//		i = 9;
//		while (N > 1 && i > 1) {
//			while (N % i == 0) {
//				Q = Q * 10 + i;
//				N /= i;
//			}
//			--i;
//		}
//		if (N > 1) {
//			Q = -1;
//		}
//		else {
//			intoarce(Q);
//		}
//	}
//	printf("%lld\n", Q);
//
//	return 0;
//}

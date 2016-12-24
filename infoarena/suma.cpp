//#include <cstdio>
//
///*
// * S = sum(i*(i-1)), i=1..N
// * S = 0*1 + 1*2 + 2*3 + ... + n*(n-1)
// * S = (n-1)*n*(n+1)/3
// */
//
//int main() {
//	long long N, P;
//	long long sum;
//
//	freopen("suma.in", "r", stdin);
//	freopen("suma.out", "w", stdout);
//
//	scanf("%lld %lld", &N, &P);
//
//	if ((N - 1) % 3 == 0) {
//		sum = ((N - 1) / 3) % P;
//		sum = (sum * N) % P;
//		sum = (sum * (N + 1)) % P;
//	}
//	else if (N % 3 == 0) {
//		sum = (N / 3) % P;
//		sum = (sum * (N - 1)) % P;
//		sum = (sum * (N + 1)) % P;
//	}
//	else {
//		sum = ((N + 1) / 3) % P;
//		sum = (sum * (N - 1)) % P;
//		sum = (sum * N) % P;
//	}
//
//	printf("%lld\n", sum);
//
//	return 0;
//}

#include <cstdio>

void intoarce(long long& n) {
	long long a;

	a = 0;
	while (n > 0) {
		a *= 10;
		a += n % 10;
		n /= 10;
	}
	n = a;
}

int main() {
	long long n;
	long long res;
	int i;

	freopen("g2.in", "r", stdin);
	freopen("g2.out", "w", stdout);

	// input
	scanf("%lld", &n);

	// solve
	if (n < 10) {
		res = n;
	}
	else {
		res = 0;
		i = 9;
		while (n > 1 && i > 1) {
			while (n % i == 0) {
				res = res * 10 + i;
				n /= i;
			}
			--i;
		}
		if (n > 1) {
			res = 0;
		}
		else {
			intoarce(res);
		}
	}

	// output
	printf("%lld\n", res);

	return 0;
}

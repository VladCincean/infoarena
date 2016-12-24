#include <cstdio>
#define O_ORANGE 0
#define O_BANANA 1

inline long min(long a, long b) {
	if (a < b)
		return a;
	return b;
}

int main() {
	int T;
	long P, B;

	freopen("fructe.in", "r", stdin);
	freopen("fructe.out", "w", stdout);

	scanf("%d", &T);

	while (T--) {
		scanf("%ld %ld", &P, &B);
		while (P + B > 1) {
			while (B > 1) {
				P += B / 2;
				B %= 2;
			}
			while (P > 1) {
				P = P / 2 + P % 2;
			}
			if (P > 0) {
				P -= min(P, B);
			}
		}

		if (P == 1) {
			printf("%d\n", O_ORANGE);
		}
		else {
			printf("%d\n", O_BANANA);
		}
	}

	return 0;
}

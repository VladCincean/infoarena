#include <cstdio>

int main() {
	int T;
	long B;

	freopen("fructe.in", "r", stdin);
	freopen("fructe.out", "w", stdout);

	scanf("%d", &T);

	while (T--) {
		scanf("%ld", &B);
		scanf("%ld", &B);
		printf("%d\n", B % 2);
	}

	return 0;
}

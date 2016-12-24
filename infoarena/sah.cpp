#include <cstdio>

int main() {
	short N;
	short c;
	short i, j;

	freopen("sah.in", "r", stdin);
	freopen("sah.out", "w", stdout);

	scanf("%hd", &N);
	
	c = 1;
	for (i = 1; i <= N / 2; ++i) {
		for (j = 1; j <= N; ++j) {
			printf("%hd ", c);
			if (j == i - 1) ++c;
		}
		printf("\n");
		if (i > 1) --c;
		for (j = 1; j <= N; ++j) {
			printf("%hd ", c);
			if (j == i - 1) ++c;
		}
		++c;
		printf("\n");
	}

	return 0;
}

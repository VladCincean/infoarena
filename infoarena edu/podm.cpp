#include <cstdio>
#include <cstdlib>
#include <climits>

int main() {
	int n;
	long long *d;
	long long **m;
	int i, j, k, len;
	long long q;

	freopen("podm.in", "r", stdin);
	freopen("podm.out", "w", stdout);

	// input
	scanf("%d", &n);
	d = (long long*)malloc((n + 1) * sizeof(long long));
	for (i = 0; i <= n; ++i) {
		scanf("%lld", &d[i]);
	}

	// solve
	m = (long long**)malloc((n + 1) * sizeof(long long*));
	for (i = 1; i <= n; i++) {
		m[i] = (long long*)malloc((n + 1) * sizeof(long long));
	}

	for (i = 1; i <= n; ++i) {
		m[i][i] = 0;
	}

	for (len = 2; len <= n; ++len) {
		for (i = 1; i <= n - len + 1; ++i) {
			j = i + len - 1;
			m[i][j] = LLONG_MAX;
			for (k = i; k <= j - 1; ++k) {
				q = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (q < m[i][j]) {
					m[i][j] = q;
				}
			}
		}
	}

	// output
	printf("%lld\n", m[1][n]);

	// free memory
	free(d);
	for (i = 1; i <= n; ++i) {
		free(m[i]);
	}
	free(m);

	return 0;
}

#include <cstdio>
#include <cstdlib>

typedef struct {
	long long A, B;
} interval;

void merge(interval *v, int st, int m, int dr) {
	int n1 = m - st + 1;
	int n2 = dr - m;
	interval *L = (interval*)malloc(n1 * sizeof(interval));
	interval *R = (interval*)malloc(n2 * sizeof(interval));
	int i, j, k;

	for (i = 0; i < n1; ++i) {
		L[i] = v[st + i];
	}
	for (j = 0; j < n2; ++j) {
		R[j] = v[m + 1 + j];
	}

	i = 0; j = 0; k = st;
	while (i < n1 && j < n2) {
		if (L[i].A <= R[j].A) {
			v[k++] = L[i++];
		}
		else {
			v[k++] = R[j++];
		}
	}
	while (i < n1) {
		v[k++] = L[i++];
	}
	while (j < n2) {
		v[k++] = R[j++];
	}

	free(L); free(R);
}

void merge_sort(interval *v, int st, int dr) {
	int m = st + (dr - st) / 2;
	
	if (st < dr) {
		merge_sort(v, st, m);
		merge_sort(v, m + 1, dr);
		merge(v, st, m, dr);
	}
}

void merge_sort(interval *v, int N) {
	merge_sort(v, 0, N - 1);
}

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main() {
	int N;
	interval *v;
	int A, B, result;

	freopen("granita.in", "r", stdin);
	freopen("granita.out", "w", stdout);

	// input
	scanf("%d", &N);
	v = (interval*)malloc(N * sizeof(interval));
	for (int i = 0; i < N; ++i) {
		scanf("%lld %lld", &v[i].A, &v[i].B);
	}

	// solve
	merge_sort(v, N);
	result = 0;
	A = v[0].A;
	B = v[0].B;
	for (int i = 1; i < N; ++i) {
		if (v[i].B < B) {
			//fprintf(stderr, "%lld %lld \n", v[i].A, v[i].B);
			++result;
		}
		A = v[i].A;
		B = max(B, v[i].B);
	}

	// output
	printf("%d\n", result);

	// free memory
	free(v);

	return 0;
}

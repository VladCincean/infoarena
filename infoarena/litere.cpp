#include <cstdio>
#include <cstdlib>
#define MAXN 10010

long long merge(char s[], int st, int m, int dr) {
	int n1 = m - st + 1;
	int n2 = dr - m;
	char *L = (char*)malloc(n1 * sizeof(char));
	char *R = (char*)malloc(n2 * sizeof(char));
	int i, j, k;
	long long inv_count = 0;

	for (i = 0; i < n1; ++i) {
		L[i] = s[st + i];
	}
	for (j = 0; j < n2; ++j) {
		R[j] = s[m + 1 + j];
	}

	i = 0; j = 0; k = st;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			s[k++] = L[i++];
		}
		else {
			s[k++] = R[j++];
			inv_count += n1 - i; // no. of remaining elements in L[]
		}
	}
	while (i < n1) {
		s[k++] = L[i++];
	}
	while (j < n2) {
		s[k++] = R[j++];
	}

	free(L); free(R);

	return inv_count;
}

long long merge_sort(char s[], int st, int dr) {
	long long inv_count = 0;
	int m = st + (dr - st) / 2;

	if (st < dr) {
		inv_count += merge_sort(s, st, m);
		inv_count += merge_sort(s, m + 1, dr);
		inv_count += merge(s, st, m, dr);
	}

	return inv_count;
}

inline long long merge_sort(char s[], int N) {
	return merge_sort(s, 0, N - 1);
}

int main() {
	int N;
	char sir[MAXN];

	freopen("litere.in", "r", stdin);
	freopen("litere.out", "w", stdout);

	scanf("%d", &N);
	scanf("%s", &sir);
	
	printf("%lld\n", merge_sort(sir, N));

	return 0;
}

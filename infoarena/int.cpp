//#include <cstdio>
//#include <cstdlib>
//
//typedef struct {
//	long long a, b;
//} interval;
//
//void merge(interval* v, int st, int m, int dr) {
//	int n1 = m - st + 1;
//	int n2 = dr - m;
//	interval *L = (interval*)malloc(n1 * sizeof(interval));
//	interval *R = (interval*)malloc(n2 * sizeof(interval));
//	int i, j, k;
//
//	for (i = 0; i < n1; ++i) {
//		L[i] = v[st + i];
//	}
//	for (j = 0; j < n2; ++j) {
//		R[j] = v[m + 1 + j];
//	}
//
//	i = 0; j = 0; k = st;
//	while (i < n1 && j < n2) {
//		if (L[i].b <= R[j].b) {
//			v[k++] = L[i++];
//		}
//		else {
//			v[k++] = R[j++];
//		}
//	}
//	while (i < n1) {
//		v[k++] = L[i++];
//	}
//	while (j < n2) {
//		v[k++] = R[j++];
//	}
//
//	free(L); free(R);
//}
//
//void merge_sort(interval* v, int st, int dr) {
//	int m = st + (dr - st) / 2;
//
//	if (st < dr) {
//		merge_sort(v, st, m);
//		merge_sort(v, m + 1, dr);
//		merge(v, st, m, dr);
//	}
//}
//
//void merge_sort(interval* v, int N) {
//	merge_sort(v, 0, N - 1);
//}
//
//int main() {
//	int N;
//	interval *v;
//	int result, choice;
//
//	freopen("int.in", "r", stdin);
//	freopen("int.out", "w", stdout);
//
//	// input
//	scanf("%d", &N);
//	v = (interval*)malloc(N * sizeof(interval));
//	for (int i = 0; i < N; ++i) {
//		scanf("%lld %lld", &v[i].a, &v[i].b);
//	}
//
//	// solve: sort in monotonically increasing order by .b coordinate, then apply a greedy algorithm
//	merge_sort(v, N);
//	choice = v[0].b;
//	result = 1;
//	for (int i = 1; i < N; ++i) {
//		if (v[i].a >= choice) {
//			choice = v[i].b;
//			++result;
//		}
//	}
//
//	// output
//	printf("%d\n", result);
//
//	// free memory
//	free(v);
//
//	return 0;
//}

//#include <cstdio>
//#include <cstdlib>
//
//typedef struct {
//	int Tmin, Tmax;
//} reactiv;
//
//void merge(reactiv *v, int st, int m, int dr) {
//	int n1 = m - st + 1;
//	int n2 = dr - m;
//	reactiv *L = (reactiv*)malloc(n1 * sizeof(reactiv));
//	reactiv *R = (reactiv*)malloc(n2 * sizeof(reactiv));
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
//		if (L[i].Tmax <= R[j].Tmax) {
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
//void merge_sort(reactiv *v, int st, int dr) {
//	int m = st + (dr - st) / 2;
//
//	if (st < dr) {
//		merge_sort(v, st, m);
//		merge_sort(v, m + 1, dr);
//		merge(v, st, m, dr);
//	}
//}
//
//void merge_sort(reactiv* v, int N) {
//	merge_sort(v, 0, N - 1);
//}
//
//int main() {
//	int N;
//	reactiv *v;
//	int choice, res;
//
//	freopen("reactivi.in", "r", stdin);
//	freopen("reactivi.out", "w", stdout);
//
//	// input
//	scanf("%d", &N);
//	v = (reactiv*)malloc(N * sizeof(reactiv));
//	for (int i = 0; i < N; ++i) {
//		scanf("%d %d", &v[i].Tmin, &v[i].Tmax);
//	}
//
//	// solve
//	merge_sort(v, N);
//	choice = v[0].Tmax;
//	res = 1;
//	for (int i = 1; i < N; ++i) {
//		if (v[i].Tmin > choice) {
//			choice = v[i].Tmax;
//			++res;
//		}
//	}
//
//	// output
//	printf("%d\n", res);
//
//	//// free memory
//	free(v);
//
//	return 0;
//}

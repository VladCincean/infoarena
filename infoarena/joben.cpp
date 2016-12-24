//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <algorithm>
//#define L_MAX 100100
//
////inline void merge(int *v, int st, int m, int dr) {
////	int n1 = m - st + 1;
////	int n2 = dr - m;
////	int *L = (int*)malloc(n1 * sizeof(int));
////	int *R = (int*)malloc(n2 * sizeof(int));
////	int i, j, k;
////
////	for (i = 0; i < n1; ++i) {
////		L[i] = v[st + i];
////	}
////	for (j = 0; j < n2; ++j) {
////		R[j] = v[m + 1 + j];
////	}
////
////	i = 0; j = 0; k = st;
////	while (i < n1 && j < n2) {
////		if (L[i] >= R[j]) {
////			v[k++] = L[i++];
////		}
////		else {
////			v[k++] = R[j++];
////		}
////	}
////	while (i < n1) {
////		v[k++] = L[i++];
////	}
////	while (j < n2) {
////		v[k++] = R[j++];
////	}
////
////	free(L); free(R);
////}
////
////inline void merge_sort(int *v, int st, int dr) {
////	int m = st + (dr - st) / 2;
////
////	if (st < dr) {
////		merge_sort(v, st, m);
////		merge_sort(v, m + 1, dr);
////		merge(v, st, m, dr);
////	}
////}
////
////inline void merge_sort(int *v, int size) {
////	merge_sort(v, 0, size - 1);
////}
//
//inline bool check(int a1[], int a2[]) {
//	for (int i = 0; i < 26; ++i)
//		if (a1[i] != a2[i])
//			return false;
//	return true;
//}
//
//int main() {
//	int T;
//	char sir1[L_MAX];
//	char sir2[L_MAX];
//	int a1[26];
//	int a2[26];
//
//	freopen("joben.in", "r", stdin);
//	freopen("joben.out", "w", stdout);
//
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%s", &sir1);
//		scanf("%s", &sir2);
//
//		for (int i = 0; i < 26; ++i) {
//			a1[i] = 0; a2[i] = 0;
//		}
//
//		for (int i = 0; i < strlen(sir1); ++i) {
//			a1[sir1[i] - 'a']++;
//			a2[sir2[i] - 'a']++;
//		}
//
//		//merge_sort(a1, 26);
//		//merge_sort(a2, 26);
//
//		std::sort(a1, a1 + 26, [](int a, int b) {return a > b; });
//		std::sort(a2, a2 + 26, [](int a, int b) {return a > b; });
//
//		if (check(a1, a2)) {
//			printf("DA\n");
//		}
//		else {
//			printf("NU\n");
//		}
//	}
//
//	return 0;
//}

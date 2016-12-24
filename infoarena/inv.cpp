#include <fstream>

using namespace std;

#define MOD 9917;

int mergeSort(int S[], int n);
int _mergeSort(int S[], int l, int r);
int _merge(int S[], int l, int m, int r);

int _mergeSort(int S[], int l, int r) {
	int inv_count = 0;

	if (l < r) {
		int m = (l + r) / 2;
		inv_count += _mergeSort(S, l, m);
		inv_count += _mergeSort(S, m + 1, r);
		inv_count += _merge(S, l, m, r);
	}

	return inv_count % MOD;
}

int _merge(int S[], int l, int m, int r) {
	int inv_count = 0;

	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;
	int *L, *R;

	L = new int[n1];
	R = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = S[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = S[m + 1 + j];
	}

	i = 0; j = 0; k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			S[k++] = L[i++];
		}
		else {
			S[k++] = R[j++];
			inv_count += n1 - i; // <- number of remaining elements in L[]
		}
	}
	
	while (i < n1) {
		S[k++] = L[i++];
	}

	while (j < n2) {
		S[k++] = R[j++];
	}

	delete[] L;
	delete[] R;

	return inv_count % MOD;
}

int mergeSort(int S[], int n) {
	return _mergeSort(S, 0, n - 1);
}

int main() {
	int n;
	int* S;
	int inv_count;

	// input
	ifstream f("inv.in");
	f >> n;
	S = new int[n];
	for (int i = 0; i < n; i++) {
		f >> S[i];
	}
	f.close();

	// solve
	inv_count = mergeSort(S, n);

	// output
	ofstream g("inv.out");
	g << inv_count << '\n';
	g.close();

	// free memory
	delete[] S;

	return 0;
}

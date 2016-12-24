#include <iostream>

using namespace std;

int main() {
	short n;
	cin >> n;
	short** A = new short*[n];
	for (short i = 0; i < n; i++) {
		A[i] = new short[n];
	}

	// input
	for (short i = 0; i < n; i++) {
		for (short j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	// output
	for (short i = 0; i < n; i++) {
		for (short j = 0; j <= i; j++) {
			cout << A[i - j][j] << " ";
		}
	}
	for (short i = 0; i < n; i++) {
		for (short j = i + 1; j < n; j++) {
			cout << A[n - j + i][j] << " ";
		}
	}
	cout << "\n";

	// free memory
	for (short i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;

	return 0;
}

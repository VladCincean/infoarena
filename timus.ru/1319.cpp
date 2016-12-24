//#include <iostream>
//
//using namespace std;
//
//int main() {
//	short n;
//	short** a;
//	short c;
//
//	// allocate memory
//	cin >> n;
//	a = new short*[n];
//	for (short i = 0; i < n; i++) {
//		a[i] = new short[n];
//	}
//
//	// fill
//	c = 1;
//	for (short j = n - 1; j > -1; j--) {
//		for (short i = 0; i < n - j; i++) {
//			a[i][i + j] = c++;
//		}
//	}
//	for (short i = 1; i < n; i++) {
//		for (short j = 0; j < n - i; j++) {
//			a[i + j][j] = c++;
//		}
//	}
//
//	// output
//	for (short i = 0; i < n; i++) {
//		for (short j = 0; j < n; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	// free memory
//	for (short i = 0; i < n; i++) {
//		delete[] a[i];
//	}
//	delete[] a;
//
//	return 0;
//}

//#include <fstream>
//#include <cstring>
//
//using namespace std;
//
//#define MOD 666013
//
///*
//	Sirul lui Fibonacci: F[0] = 0, F[1] = 1, ..., F[n] = F[n-1] + F[n-2]
//
//	| 0 1 | | F[n-2] |  =  | F[n-1] |
//	| 1 1 | | F[n-1] |     |  F[n]  |
//
//	M * X[i-1] = X[i]
//	M^(i-1) * X[1] = X[i]
//*/
//
//// init characteristic matrix
//void initMatrix(int M[2][2]) {
//	M[0][0] = 0; M[0][1] = 1;
//	M[1][0] = 1; M[1][1] = 1;
//}
//
//// A := A * B, where A,B are 2x2 matrices
//void multiply(int A[2][2], int B[2][2]) {
//	int C[2][2];
//
//	// C := 02
//	memset(C, 0, sizeof(C));
//
//	// C := A*B
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			for (int k = 0; k < 2; k++) {
//				C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
//			}
//		}
//	}
//
//	// A := C
//	memcpy(A, C, sizeof(C));
//}
//
//// M := M^p
//void lg_power(int M[][2], int p) {
//	int R[2][2];
//
//	// R := I2
//	memset(R, 0, sizeof(R));
//	R[0][0] = R[1][1] = 1;
//
//	// R := M^p
//	while (p > 0) {
//		if (p % 2 == 1) {
//			multiply(R, M);
//			p--;
//		}
//		multiply(M, M);
//		p /= 2;
//	}
//
//	// M := R
//	memcpy(M, R, sizeof(R));
//}
//
//int main() {
//	int K;
//	int M[2][2];
//
//	// input
//	ifstream f("kfib.in");
//	f >> K;
//	f.close();
//
//	// compute
//	if (K > 0) {
//		initMatrix(M);
//		lg_power(M, K - 1);
//	}
//	else {
//		M[1][1] = 0; // F0
//	}
//
//	// output
//	ofstream g("kfib.out");
//	g << M[1][1] << "\n";
//	g.close();
//
//	return 0;
//}
//#include <fstream>
//
//#define MOD 666013
//
//using namespace std;
//
//int X, Y, Z, A, B, C;
//long long N;
//
//// Initializes the characteristic matrix
//void initMatrix(long long M[3][3]) {
//	M[0][0] = 0; M[0][1] = 1; M[0][2] = 0;
//	M[1][0] = 0; M[1][1] = 0; M[1][2] = 1;
//	M[2][0] = C; M[2][1] = B; M[2][2] = A;
//}
//
//// Performs A := A * B, where A,B are 3x3 matrices
//void multyply(long long  A[3][3], long long B[3][3]) {
//	long long  C[3][3];
//
//	// C := O3
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			C[i][j] = 0;
//		}
//	}
//
//	// C := A*B
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				C[i][j] += (A[i][k] * B[k][j]) % MOD;
//				C[i][j] %= MOD;
//			}
//		}
//	}
//
//	// A := C
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			A[i][j] = C[i][j];
//		}
//	}
//}
//
//// Performs M := M^p
//void power(long long M[3][3], long long p) {
//	long long R[3][3];
//
//	// R := I3
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3 && j != i; j++) {
//			R[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		R[i][i] = 1;
//	}
//
//	// R := M^p
//	while (p > 0) {
//		if (p % 2 == 1) {
//			multyply(R, M);
//			p--;
//		}
//		multyply(M, M);
//		p /= 2;
//	}
//
//	// M := R (M^p)
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			M[i][j] = R[i][j];
//		}
//	}
//}
//
//int main() {
//	int T;
//	long long M[3][3];
//	long long result;
//	ifstream f("iepuri.in");
//	f >> T;
//	ofstream g("iepuri.out");
//	while (T--) {
//		f >> X >> Y >> Z >> A >> B >> C >> N;
//		initMatrix(M);
//		power(M, N - 2);
//		result = ((M[2][0] * X) % MOD + (M[2][1] * Y) % MOD + (M[2][2] * Z) % MOD) % MOD;
//		g << result << "\n";
//	}
//	f.close();
//	g.close();
//
//	return 0;
//}

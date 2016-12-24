#include <fstream>
#include <iomanip>

using namespace std;

int N;
long long M;
long double* x;
long double* p;
long double* y;
long double** matrix;

// C := A * B, where A, B, C are size*size matrices
void multiply(long double** A, long double** B, long double** C, int size) {
	long double** R = new long double*[size];
	for (int i = 0; i < size; i++) {
		R[i] = new long double[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			R[i][j] = 0.0;
		}
	}

	// R := A * B
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				R[i][j] = R[i][j] + A[i][k] * B[k][j];
			}
		}
	}

	// C := R
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			C[i][j] = R[i][j];
		}
	}

	// delete R
	for (int i = 0; i < size; i++) {
		delete[] R[i];
	}
	delete[] R;
}

void lg_power(long double** A, int size, long long exp) {
	// R := In (n = size)
	long double** R = new long double*[size];
	for (int i = 0; i < size; i++) {
		R[i] = new long double[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			R[i][j] = 0.0;
		}
	}
	for (int i = 0; i < size; i++) {
		R[i][i] = 1.0;
	}

	// R := A^exp
	while (exp > 0) {
		if (exp % 2 == 1) {
			multiply(R, A, R, size);
			exp--;
		}
		multiply(A, A, A, size);
		exp /= 2;
	}

	// A := R
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] = R[i][j];
		}
	}

	// delete R
	for (int i = 0; i < size; i++) {
		delete[] R[i];
	}
	delete[] R;
}

int main() {
	// input
	ifstream f("ecu.in");
	f >> N >> M;
	x = new long double[N];
	for (int i = 0; i < N; i++) {
		f >> x[i];
	}
	p = new long double[N];
	for (int i = 0; i < N; i++) {
		f >> p[i];
	}
	y = new long double[N];
	for (int i = 0; i < N; i++) {
		f >> y[i];
	}
	f.close();

	// init matrix
	matrix = new long double*[N + 1];
	for (int i = 0; i < N + 1; i++) {
		matrix[i] = new long double[N + 1];
	}
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 0.0;
		}
	}
	for (int i = 0; i < N; i++) {
		matrix[i][i] = p[i];
		matrix[i][(i + 1) % N] = 1.0 - p[(i + 1) % N];
		matrix[i][N] = y[i];
	}
	matrix[N][N] = 1.0;

	// compute matrix^M
	lg_power(matrix, N + 1, M);

	// output
	ofstream g("ecu.out");
	long double res;
	for (int i = 0; i < N; i++) {
		res = matrix[i][N];
		for (int j = 0; j < N; j++) {
			res += matrix[i][j] * x[j];
		}
		g << fixed << setprecision(3) << res << " ";
	}
	g << "\n";
	g.close();

	// free memory
	for (int i = 0; i < N + 1; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] x;
	delete[] p;
	delete[] y;

	return 0;
}

//#include <fstream>
//#include <iomanip>
//
//using namespace std;
//
//int main() {
//	int N;
//	double* x;
//	double* y;
//	double A;
//
//	// input
//	ifstream f("aria.in");
//	f >> N;
//	x = new double[N];
//	y = new double[N];
//	for (int i = 0; i < N; i++) {
//		f >> x[i] >> y[i];
//	}
//	f.close();
//
//	// compute
//	A = 0.0;
//	for (int i = 0; i < N; i++) {
//		A += static_cast<double>(x[i] * y[(i + 1) % N] - x[(i + 1) % N] * y[i]);
//	}
//	A /= 2.0;
//	
//	// output
//	ofstream g("aria.out");
//	g << fixed << setprecision(5) << A << "\n";
//	g.close();
//
//	// free memory
//	delete[] x;
//	delete[] y;
//
//	return 0;
//}

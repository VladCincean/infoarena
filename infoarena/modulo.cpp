//#include <fstream>
//
//using namespace std;
//
//long long modulo(long long A, long long B, long long C) {
//	long long res = 1;
//
//	while (B > 0) {
//		if (B % 2 == 1) {
//			res = (res * A) % C;
//			B--;
//		}
//		A = (A * A) % C;
//		B /= 2;
//	}
//
//	return res;
//}
//
//int main() {
//	long long A, B, C, res;
//
//	// input
//	ifstream f("modulo.in");
//	f >> A >> B >> C;
//	f.close();
//
//	// compute;
//	res = modulo(A, B, C);
//
//	// output
//	ofstream g("modulo.out");
//	g << res << "\n";
//	g.close();
//
//	return 0;
//}

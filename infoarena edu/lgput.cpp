//#include <fstream>
//
//using namespace std;
//
//#define MOD 1999999973
//
//long long lgput(long long N, long long P) {
//	long long res = 1;
//
//	while (P > 0) {
//		if (P % 2 == 1) {
//			res = (res * N) % MOD;
//			P--;
//		}
//		N = (N * N) % MOD;
//		P = P / 2;
//	}
//
//	return res;
//}
//
//int main() {
//	long long N, P, res;
//
//	// input
//	ifstream f("lgput.in");
//	f >> N >> P;
//	f.close();
//
//	// compute
//	res = lgput(N, P);
//
//	// output
//	ofstream g("lgput.out");
//	g << res << "\n";
//	g.close();
//
//	return 0;
//}

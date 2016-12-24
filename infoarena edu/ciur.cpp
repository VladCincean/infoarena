//#include <fstream>
//
//using namespace std;
//
//int main() {
//	int N, c = 0;
//	ifstream f("ciur.in");
//	f >> N;
//	f.close();
//	bool* A = new bool[N + 1];
//	for (int i = 2; i <= N; ++i) {
//		A[i] = true;
//	}
//	for (int i = 2; i <= N; ++i) {
//		if (A[i]) {
//			c++;
//			for (int j = i + i; j <= N; j += i) {
//				A[j] = false;
//			}
//		}
//	}
//	ofstream g("ciur.out");
//	g << c << "\n";
//	g.close();
//
//	return 0;
//}

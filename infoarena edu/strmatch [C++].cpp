//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	string A;
//	string B;
//	vector<int> match;
//	int a, b, N;
//	int s, i;
//
//	// input
//	ifstream f("strmatch.in");
//	f >> A >> B;
//	f.close();
//
//	// solve
//	a = A.size();
//	b = B.size();
//	for (s = 0; s < b - a + 1; ++s) {
//		for (i = 0; i < a; ++i) {
//			if (A[i] != B[s + i])
//				break;
//		}
//		if (i == a) {
//			match.push_back(s);
//		}
//	}
//	N = match.size();
//
//	// output
//	ofstream g("strmatch.out");
//	g << N << '\n';
//	for (i = 0; i < N && i < 1000; ++i) {
//		g << match[i] << ' ';
//	}
//	g << '\n';
//	g.close();
//
//	return 0;
//}
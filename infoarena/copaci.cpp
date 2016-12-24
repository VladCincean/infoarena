//#include <fstream>
//#include <vector>
//
//using namespace std;
//
///*  Area of a irregualar polygon P given by the coordinates of its vertices
//*       ---n-1
//*       \       x[i]*y[i+1] - y[i]*x[i+1]
//*  A =  /      ---------------------------
//*       ---i=0            2
//*/
//double area(vector<pair<long long, long long>> P) {
//	double area = 0.0;
//	int n = P.size();
//	for (int i = 0; i < n; i++) {
//		area += static_cast<double>(P[i].first * P[(i + 1) % n].second - P[i].second * P[(i + 1) % n].first);
//	}
//	area /= 2.0;
//	return area;
//}
//
//// Greatest common divisor of integers |a| and |b|
//int gcd(long long a, long long b) {
//	a = a < 0 ? -a : a;
//	b = b < 0 ? -b : b;
//	int c;
//	while (b) {
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	return a;
//}
//
///* Pick's Theorem: Let P be a lattice polygon. Let I(P) the number of lattice points in the
//*     interior of P and B(P) the number of lattice points on its boundary. The area of P is:
//*         A(P) = I(P) + B(P)/2 - 1
//*/
//long long solution(vector<pair<long long, long long>> P) {
//	// we are interested in I(P)
//	// I(P) = A(P) - B(P)/2 + 1
//	double I;
//	int B;
//
//	B = -P.size();
//	for (unsigned int i = 0; i < P.size(); i++) {
//		B += gcd(P[(i + 1) % P.size()].first - P[i].first, P[(i + 1) % P.size()].second - P[i].second) + 1;
//	}
//	I = area(P) - static_cast<double>(B) / 2.0 + 1.0;
//	return static_cast<long long>(I);
//}
//
//int main() {
//	// input
//	int N;
//	ifstream f("copaci.in");
//	f >> N;
//	vector<pair<long long, long long>> island(N);
//	for (int i = 0; i < N; i++) {
//		long long x, y;
//		f >> x >> y;
//		island[i] = make_pair(x, y);
//	}
//	f.close();
//
//	// output
//	ofstream g("copaci.out");
//	g << solution(island) << "\n";
//	g.close();
//
//	return 0;
//}

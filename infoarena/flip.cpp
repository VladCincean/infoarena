///*  Idea: Backtracking ---- O(2^m)
// *  - gererate all flip/no-flip states on columns
// *  - for the current configuration:
// *      - calculate the sum of the matrix as a sum of line's sums
// *      - note that if lineSum < 0, then we should flip that line to maximize the sum (which is -lineSum)
// *  - get the maximum sum among all possibilities
// */
//
//#include <fstream>
//#include <limits>
//
//using namespace std;
//
//short n, m;
//
//inline int sum(int** a, int b) {
//	int ret = 0;
//	for (int i = 0; i < n; i++) {
//		int lineSum = 0; // sum of current line
//		for (int j = 0; j < m; j++) {
//			lineSum += (b & (1 << j)) ? -a[i][j] : a[i][j]; // is there a flip of column j?
//		}
//		ret += lineSum > 0 ? lineSum : -lineSum; // if lineSum is negative, then a flip on it would maximize de sum
//	}
//	return ret;
//}
//
//int main() {
//	// input
//	ifstream f("flip.in");
//	f >> n >> m;
//	int** a = new int*[n];
//	for (int i = 0; i < n; i++) {
//		a[i] = new int[m];
//		for (int j = 0; j < m; j++) {
//			f >> a[i][j];
//		}
//	}
//	f.close();
//
//	// solve
//	int maxSum = numeric_limits<int>::min();
//	// generate all flip/no-flip states for columns
//	for (int b = 0; b < (1 << m); b++) {
//		int s = sum(a, b); // get sum of current configuration
//		if (s > maxSum) {
//			maxSum = s;
//		}
//	}
//
//	// output
//	ofstream g("flip.out");
//	g << maxSum << "\n";
//	g.close();
//
//	// deallocate
//	for (int i = 0; i < n; i++) {
//		delete[] a[i];
//	}
//	delete[] a;
//
//	return 0;
//}

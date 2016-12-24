//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int main() {
//	unsigned int N;
//
//	cin >> N;
//	long long* K = new long long[N];
//	for (unsigned int i = 0; i < N; i++) {
//		cin >> K[i];
//	}
//	for (unsigned int i = 0; i < N; i++) {
//		/*long long j = 0;
//		if (K[i] == 0) {
//			cout << "1 ";
//			continue;
//		}
//		while (1 + j*(j + 1) / 2 < K[i]) {
//			j++;
//		}
//		if (1 + j*(j + 1) / 2 == K[i]) {
//			cout << "1 ";
//		}
//		else {
//			cout << "0 ";
//		}*/
//
//		long long a = 8 * K[i] - 7;
//		if (static_cast<long long>(sqrt(a))*static_cast<long long>(sqrt(a)) == a) {
//			cout << "1 ";
//		}
//		else {
//			cout << "0 ";
//		}
//	}
//
//	delete[] K;
//
//	cout << "\n";
//
//	return 0;
//}

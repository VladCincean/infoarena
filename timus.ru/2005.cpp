//#include <iostream>
//
//using namespace std;
//
//int A[6][6];
//
//int main() {
//	// input
//	for (int i = 1; i < 6; i++) {
//		for (int j = 1; j < 6; j++) {
//			cin >> A[i][j];
//		}
//	}
//
//	/* paths:   1 2 3 4 5 (1)
//				1 3 2 4 5 (2)
//				1 3 4 2 5 (3)
//				1 4 3 2 5 (4)
//	*/
//
//	int optimalPath = 1;
//	int length = A[1][2] + A[2][3] + A[3][4] + A[4][5];
//
//	if (length > A[1][3] + A[3][2] + A[2][4] + A[4][5]) {
//		length = A[1][3] + A[3][2] + A[2][4] + A[4][5];
//		optimalPath = 2;
//	}
//
//	if (length > A[1][3] + A[3][4] + A[4][2] + A[2][5]) {
//		length = A[1][3] + A[3][4] + A[4][2] + A[2][5];
//		optimalPath = 3;
//	}
//
//	if (length > A[1][4] + A[4][3] + A[3][2] + A[2][5]) {
//		length = A[1][4] + A[4][3] + A[3][2] + A[2][5];
//		optimalPath = 4;
//	}
//
//	cout << length << "\n";
//	switch (optimalPath) {
//	case 1: {
//		cout << "1 2 3 4 5\n";
//		break;
//	}
//	case 2: {
//		cout << "1 3 2 4 5\n";
//		break;
//	}
//	case 3: {
//		cout << "1 3 4 2 5\n";
//		break;
//	}
//	case 4: {
//		cout << "1 4 3 2 5\n";
//		break;
//	}
//	}
//
//	return 0;
//}

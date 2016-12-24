//#include <fstream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//inline bool check(int a1[], int a2[]) {
//	for (int i = 0; i < 26; ++i)
//		if (a1[i] != a2[i])
//			return false;
//	return true;
//}
//
//int main() {
//	int T;
//	string sir1;
//	string sir2;
//	int a1[26];
//	int a2[26];
//
//	ifstream f("joben.in");
//	ofstream g("joben.out");
//
//	f >> T;
//	while (T--) {
//		f >> sir1;
//		f >> sir2;
//
//		for (int i = 0; i < 26; ++i) {
//			a1[i] = 0; a2[i] = 0;
//		}
//
//		for (int i = 0; i < sir1.size(); ++i) {
//			a1[sir1[i] - 'a']++;
//			a2[sir2[i] - 'a']++;
//		}
//
//		sort(a1, a1 + 26, [](int a, int b) {return a > b; });
//		sort(a2, a2 + 26, [](int a, int b) {return a > b; });
//		
//		if (check(a1, a2))
//			g << "DA\n";
//		else
//			g << "NU\n";
//	}
//
//	f.close();
//	g.close();
//
//	return 0;
//}

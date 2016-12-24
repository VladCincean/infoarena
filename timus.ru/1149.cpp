#include <iostream>
#include <string>

using namespace std;

string A(short n) {
	string s;
	short i;

	for (i = 1; i <= n; i++) {
		s += "sin(" + std::to_string(i);
		if (i != n) {
			if (i % 2 == 1) s += "-";
			else s += "+";
		}
	}
	while (--i) {
		s += ")";
	}
	
	return s;
}

string S(short n) {
	string s;

	while (s.size() < n - 1) {
		s += "(";
	}
	for (short i = 1; i <= n; i++) {
		s += A(i) + "+" + std::to_string(n - i + 1);
		if (i != n) s += ")";
	}
	return s;
}

int main() {
	short N;

	cin >> N;

	cout << S(N) << "\n";

	return 0;
}

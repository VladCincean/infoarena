#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	
	if (b == 0) {
		cout << -c << "\n";
	}
	else if (b == 1) {
		cout << a - b - c << "\n";
	}
	else {
		cout << a - b*c << "\n";
	}

	return 0;
}

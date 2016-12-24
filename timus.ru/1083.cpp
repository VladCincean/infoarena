#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	int k;
	char c[21];
	cin >> n;
	cin.getline(c, 20);
	k = strlen(c) - 1;
	long long r = 1;
	while (n >= n % k && n > 0) {
		r *= n;
		n -= k;
	}
	cout << r << "\n";

	return 0;
}

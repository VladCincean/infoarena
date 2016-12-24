#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	long long tmp;
	vector<int> v;

	cin >> n;
	while (n > 0) {
		tmp = n;
		v.push_back(tmp);
		while (tmp > 0) {
			n -= tmp % 10;
			tmp /= 10;
		}
	}

	cout << v.size() << '\n';
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	return 0;
}

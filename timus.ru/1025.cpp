#include <iostream>
#include <queue>		// std::priority_queue
#include <functional>	// std::greater

using namespace std;

int main() {
	int K;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	int n;
	n = 0;
	K = K / 2 + 1;
	while (K--) {
		n += q.top() / 2 + 1;
		q.pop();
	}
	cout << n << "\n";

	return 0;
}

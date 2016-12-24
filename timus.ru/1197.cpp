#include <iostream>
#include <vector>

using namespace std;

bool valid(char p[3]) {
	if (p[0] < 'a' || p[0] > 'h' || p[1] < '1' || p[1] > '8') {
		return false;
	}
	return true;
}

int main() {
	int N;
	char p[3];
	vector<short> res;

	cin >> N;
	for (int i = 0; i < N; i++) {
		short k = 0;

		cin >> p;
		
		p[0] += 2; p[1] += 1;
		if (valid(p)) k++;
		p[1] -= 2;
		if (valid(p)) k++;
		p[0] -= 4;
		if (valid(p)) k++;
		p[1] += 2;
		if (valid(p)) k++;
		p[0] += 3; p[1] += 1;
		if (valid(p)) k++;
		p[0] -= 2;
		if (valid(p)) k++;
		p[1] -= 4;
		if (valid(p)) k++;
		p[0] += 2;
		if (valid(p)) k++;

		res.push_back(k);
	}

	for (vector<short>::iterator it = res.begin(); it != res.end(); ++it) {
		cout << *it << "\n";
	}

	return 0;
}

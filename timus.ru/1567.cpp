#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main() {
	char a[1001];
	int pos;
	int k;

	// setup
	set<char> cost1{ 'a', 'd', 'g', 'j', 'm', 'p', 's', 'v', 'y', '.', ' ' };
	set<char> cost2{ 'b', 'e', 'h', 'k', 'n', 'q', 't', 'w', 'z', ',' };
	set<char> cost3{ 'c', 'f', 'i', 'l', 'o', 'r', 'u', 'x', '!' };

	// input
	memset(a, '\0', 1001);
	cin.getline(a, 1001);
	k = 0;
	pos = 0;
	while (a[pos] != '\0') {
		if (cost1.count(a[pos]) == 1)
			k += 1;
		else if (cost2.count(a[pos]) == 1)
			k += 2;
		else if (cost3.count(a[pos]) == 1)
			k += 3;
		pos++;
	}

	// output
	cout << k << '\n';

	return 0;
}

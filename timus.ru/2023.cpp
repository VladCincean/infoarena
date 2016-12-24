#include <iostream>
#include <set>
#include <string>

using namespace std;

short abs(short n) {
	return n < 0 ? -n : n;
}

int main() {
	set<string> c1{ "Alice", "Ariel", "Aurora", "Phil", "Peter", "Olaf", "Phoebus", "Ralph", "Robin" };
	set<string> c2{ "Bambi", "Belle", "Bolt", "Mulan", "Mowgli", "Mickey", "Silver", "Simba", "Stitch" };
	set<string> c3{ "Dumbo", "Genie", "Jiminy", "Kuzko", "Kida", "Kenai", "Tarzan", "Tiana", "Winnie" };
	short current = 1;
	short steps = 0;
	short n;
	string rec;

	cin >> n;
	for (short i = 0; i < n; i++) {
		cin >> rec;
		if (c1.count(rec) == 1) {
			steps += abs(current - 1);
			current = 1;
		}
		else if (c2.count(rec) == 1) {
			steps += abs(current - 2);
			current = 2;
		}
		else if (c3.count(rec) == 1) {
			steps += abs(current - 3);
			current = 3;
		}
	}
	cout << steps << "\n";
}

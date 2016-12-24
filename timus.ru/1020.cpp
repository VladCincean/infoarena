#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#define PI 3.14159

int main() {
	short N;
	double R;
	double res;
	double x0, y0, x1, x2, y1, y2;

	cin >> N >> R;
	res = 2 * PI * R;
	cin >> x0 >> y0;
	x1 = x0;
	y1 = y0;
	for (short i = 1; i < N; i++) {
		cin >> x2 >> y2;
		res += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		x1 = x2;
		y1 = y2;
	}
	res += sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));

	cout << fixed << setprecision(2) << res << "\n";

	return 0;
}

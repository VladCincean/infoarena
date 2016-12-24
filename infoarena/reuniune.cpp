#include <cstdio>
#include <cstdlib>

typedef struct {
	long long x1, y1, x2, y2;
} rectangle;

inline long long max(long long a, long long b) {
	return a > b ? a : b;
}

inline long long min(long long a, long long b) {
	return a < b ? a : b;
}

inline long long _abs(long long a) {
	return a > 0 ? a : -a;
}

inline long long area(rectangle r) {
	return _abs(r.x1 - r.x2) * _abs(r.y1 - r.y2);
}

inline long long perimeter(rectangle r) {
	return 2 * _abs(r.x1 - r.x2) + 2 * _abs(r.y1 - r.y2);
}

rectangle intersect(rectangle r1, rectangle r2) {
	rectangle ret;

	if (r1.x1 <= r2.x2 && r1.x2 >= r2.x1 && r1.y1 <= r2.y2 && r1.y2 >= r2.y1) {
		ret.x1 = max(r1.x1, r2.x1);
		ret.y1 = max(r1.y1, r2.y1);
		ret.x2 = min(r1.x2, r2.x2);
		ret.y2 = min(r1.y2, r2.y2);
	}
	else {
		ret.x1 = 0; ret.y1 = 0;
		ret.x2 = 0; ret.y2 = 0;
	}
	return ret;
}

rectangle intersect(rectangle r1, rectangle r2, rectangle r3) {
	return intersect(intersect(r1, r2), r3);
}

int main() {
	rectangle R[3];
	int i;
	long long A, P;

	freopen("reuniune.in", "r", stdin);
	freopen("reuniune.out", "w", stdout);

	// input
	for (i = 0; i < 3; ++i) {
		scanf("%lld %lld %lld %lld", &R[i].x1, &R[i].y1, &R[i].x2, &R[i].y2);
	}

	// solve
	A = area(R[0]) + area(R[1]) + area(R[2]);
	A -= area(intersect(R[0], R[1]));
	A -= area(intersect(R[0], R[2]));
	A -= area(intersect(R[1], R[2]));
	A += area(intersect(R[0], R[1], R[2]));

	P = perimeter(R[0]) + perimeter(R[1]) + perimeter(R[2]);
	P -= perimeter(intersect(R[0], R[1]));
	P -= perimeter(intersect(R[0], R[2]));
	P -= perimeter(intersect(R[1], R[2]));
	P += perimeter(intersect(R[0], R[1], R[2]));

	// output
	printf("%lld %lld", A, P);

	return 0;
}

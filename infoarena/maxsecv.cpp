#include <cstdio>

int main() {
	int N;
	int max, second_max, c_sum, c;

	freopen("maxsecv.in", "r", stdin);
	freopen("maxsecv.out", "w", stdout);

	scanf("%d", &N);
	c_sum = 0;
	max = 0;
	second_max = 0;
	while (N--) {
		scanf("%d", &c);
		if (c == 1) {
			++c_sum;
		}
		else if (c_sum > max) {
			second_max = max;
			max = c_sum;
			c_sum = 0;
		}
		else if (c_sum > second_max) {
			second_max = c_sum;
			c_sum = 0;
		}
		else {
			c_sum = 0;
		}
	}
	if (c_sum > 0) {
		if (c_sum > max) {
			second_max = max;
			max = c_sum;
			c_sum = 0;
		}
		else if (c_sum > second_max) {
			second_max = c_sum;
			c_sum = 0;
		}
	}

	printf("%d\n", max + second_max);

	return 0;
}

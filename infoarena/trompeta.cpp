#include <cstdio>
#include <cstdlib>
#include <cstring>

#define STACK_MAX 1000000

typedef struct stack {
	char _data[STACK_MAX];
	int _size;
};

inline void stack_init(stack* st) {
	st->_size = 0;
}

inline char stack_top(stack* st) {
	if (st->_size == 0) {
		fprintf(stderr, "Error: stack is empty\n");
		return -1;
	}
	return st->_data[st->_size - 1];
}

inline void stack_pop(stack* st) {
	if (st->_size == 0) {
		fprintf(stderr, "Error: stack is empty\n");
	}
	else {
		st->_size--;
	}
}

inline void stack_push(stack* st, char c) {
	if (st->_size < STACK_MAX) {
		st->_data[st->_size++] = c;
	}
	else {
		fprintf(stderr, "Error: stack is full\n");
	}
}

inline int stack_size(stack* st) {
	return st->_size;
}

int main() {
	int N, M;
	int i;
	char *c, *res;
	stack *st;

	freopen("trompeta.in", "r", stdin);
	freopen("trompeta.out", "w", stdout);

	// input
	scanf("%d %d", &N, &M);
	c = (char*)malloc((N + 1) * sizeof(char));
	scanf("%s", c);

	// solve
	st = (stack*)malloc(sizeof(stack));
	stack_init(st);
	stack_push(st, c[0]);
	for (i = 0; i < N; ++i) {
		while (stack_size(st) > 0 && stack_size(st) + N - i > M) {
			if (c[i] > stack_top(st)) {
				stack_pop(st);
			}
			else {
				break;
			}
		}
		if (stack_size(st) < M) {
			stack_push(st, c[i]);
		}
	}

	// free some memory
	free(c);

	// get result
	res = (char*)malloc((M + 1) * sizeof(char));
	res[M] = '\0';
	for (i = M - 1; i >= 0; --i) {
		res[i] = stack_top(st);
		stack_pop(st);
	}

	// output
	printf("%s\n", res);

	// free memory
	free(st);
	free(res);

	return 0;
}

#include <stdio.h>
#define MAXN 100001

long long	eval_expr_order_0(char **str);

long long	eval_expr_order_2(char **str) {
	long long	result;
	char		*s;

	result = 0;
	s = *str;
	if (*s == '(') {
		s++; // pass '('
		result += eval_expr_order_0(&s);
		s++; // pass ')'
	}
	else while ('0' <= *s && *s <= '9') {
		result = result * 10 + *s - '0';
		s++;
	}
	*str = s;
	return result;
}

long long	eval_expr_order_1(char **str) {
	long long	result;
	char		*s;

	s = *str;
	result = eval_expr_order_2(&s);
	while (*s == '*' || *s == '/' || *s == '%') {
		if (*s == '*') {
			s++;
			result *= eval_expr_order_2(&s);
		}
		else if (*s == '/') {
			s++;
			result /= eval_expr_order_2(&s);
		}
		else if (*s == '%') {
			s++;
			result %= eval_expr_order_2(&s);
		}
	}
	*str = s;
	return result;
}

long long	eval_expr_order_0(char **str) {
	long long	result;
	char		*s;

	s = *str;
	result = eval_expr_order_1(&s);
	while (*s == '+' || *s == '-') {
		if (*s == '+') {
			s++;
			result += eval_expr_order_1(&s);
		}
		else if (*s == '-') {
			s++;
			result -= eval_expr_order_1(&s);
		}
	}
	*str = s;
	return result;
}

long long	eval_expr(char *str) {
	long long result;

	result = eval_expr_order_0(&str);
	return result;
}

int			main(void) {
	char		str[MAXN];
	long long	result;
	FILE		*f_in = fopen("evaluare.in", "r");
	FILE		*f_out = fopen("evaluare.out", "w");

	fgets(str, MAXN, f_in);
	result = eval_expr(str);
	fprintf(f_out, "%lld\n", result);

	fclose(f_in);
	fclose(f_out);

	return 0;
}
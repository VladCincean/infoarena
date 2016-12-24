#include <stdio.h>
#include <string.h>
#define LEXPR 1001

// ... 

bool	vars[26];

bool	eval_expr_or(char **str);

bool	eval_expr_not(char **str) {
	bool	result;
	char	*s;
	bool	negate;

	s = *str;
	result = false;
	negate = false;
	if (*s == ' ')
		s++;
	if (strncmp(s, "NOT", 3) == 0) {
		negate = true;
		s += 4; // pass 'NOT' and a whitespace
	}
	if (*s == '(') {
		s++; // pass '('
		result = eval_expr_or(&s);
		s++; // pass ')'
	}
	else {
		if (strncmp(s, "TRUE", 4) == 0) {
			result = true;
			s += 4; // pass 'TRUE'
			if (*s == ' ')
				s++;
		}
		else if (strncmp(s, "FALSE", 5) == 0) {
			result = false;
			s += 5; // pass 'FALSE'
			if (*s == ' ')
				s++;
		}
		else {
			result = vars[*s++ - 'A'];
			if (*s == ' ')
				s++;
		}
	}
	*str = s;
	if (negate == true)
		return (!result);
	return (result);
}

bool	eval_expr_and(char **str) {
	bool	result;
	char	*s;

	s = *str;
	result = eval_expr_not(&s);
	if (*s == ' ')
		s++;
	while (strncmp(s, "AND", 3) == 0) {
		if (strncmp(s, "AND", 3) == 0) {
			s += 4; // pass 'AND' and a whitespace
			result = result && eval_expr_not(&s);
			if (*s == ' ')
				s++;
		}
	}
	*str = s;
	return result;
}

bool	eval_expr_or(char **str) {
	bool	result;
	char	*s;

	s = *str;
	result = eval_expr_and(&s);
	if (*s == ' ')
		s++;
	while (strncmp(s, "OR", 2) == 0) {
		if (strncmp(s, "OR", 2) == 0) {
			s += 3; // pass 'OR' and a whitespace
			result = result || eval_expr_and(&s);
			if (*s == ' ')
				s++;
		}
	}
	*str = s;
	return result;
}

bool	eval_expr(char *str) {
	bool	result;

	result = eval_expr_or(&str);
	return result;
}

int		main(void) {
	FILE	*f_in = fopen("bool.in", "r");
	FILE	*f_out = fopen("bool.out", "w");
	char	str[LEXPR];
	int		N;
	bool	result;
	char	c;

	fgets(str, LEXPR, f_in);
	fscanf(f_in, "%d", &N);
	c = fgetc(f_in); // newline
	c = fgetc(f_in); // first character
	while ('A' <= c && c <= 'Z') {
		vars[c - 'A'] = !vars[c - 'A'];
		result = eval_expr(str);
		fprintf(f_out, "%d", result);
		c = fgetc(f_in);
	}
	fprintf(f_out, "\n");

	fclose(f_in);
	fclose(f_out);
	return 0;
}
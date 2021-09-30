#include <stdbool.h>
#include <stdio.h>

bool	is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	is_space(char space)
{
	return (is_in_string(space, "\t\n\v\f\r "));
}	

bool	is_operator(char op)
{
	return (is_in_string(op, "+-"));
}

bool	is_number(char num)
{
	return (num >= '0' && num <= '9');
}

int	ft_atoi(char *str)
{
	int	res;
	int	min;

	res = 0;
	min = 1;
	while (is_space(*str))
		str++;
	while (is_operator(*str))
	{
		if (*str == '-')
			min *= -1;
		str++;
	}
	while (is_number(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * min);
}

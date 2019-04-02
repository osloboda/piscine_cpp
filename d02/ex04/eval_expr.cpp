#include "eval_expr.h"

void			creat(t_list2 **num, t_list1 **chars)
{
	t_list2		*numbers;
	t_list1		*characters;

	numbers = *num;
	characters = *chars;
	numbers->next->data = op(characters->data,
							 numbers->next->data, numbers->data);
	numbers = numbers->next;
	characters = characters->next;
	*num = numbers;
	*chars = characters;
}

void			creat1(t_list2 **num1, t_list1 **chars1, char **st1)
{
	t_list2		*numbers;
	t_list1		*characters;
	char		*str;

	numbers = *num1;
	characters = *chars1;
	str = *st1;
	while (characters->data != '(')
		creat(&numbers, &characters);
	characters = characters->next;
	str++;
	*st1 = str;
	*num1 = numbers;
	*chars1 = characters;
}

void			body(t_list2 **num, t_list1 **chars, char **st)
{
	t_list2		*numbers;
	t_list1		*characters;
	char		*str;

	numbers = *num;
	characters = *chars;
	str = *st;
	if (!characters)
		ft_list_push_front1(&characters, (str++)[0]);
	else if (str[0] == ')')
		creat1(&numbers, &characters, &str);
	else if (str[0] == '(')
		ft_list_push_front1(&characters, (str++)[0]);
	else if (cmp(characters->data) < cmp(str[0]) ||
			 (characters->data == '(' && str[0] != '('))
		ft_list_push_front1(&characters, (str++)[0]);
	else if (cmp(characters->data) >= cmp(str[0]))
		creat(&numbers, &characters);
	*num = numbers;
	*st = str;
	*chars = characters;
}

int				eval_expr(char *str)
{
	t_list2		*numbers;
	t_list1		*characters;

	str = spaces(str);
	numbers = NULL;
	characters = NULL;
	while (str[0])
	{
		if ((str[0] >= '0' && str[0] <= '9') || (str[0] == '-' && ((str[-1] < '0' || str[-1] > '9') && str[-1] != ')')))
		{
			ft_list_push_front2(&numbers, ft_atoi(str++));
			while (str[0] >= '0' && str[0] <= '9')
				str++;
		}
		else if (str[0] == ' ')
			while (str[0] == ' ')
				str++;
		else if (str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*' || str[0] == '%' || str[0] == '(' || str[0] == ')')
			body(&numbers, &characters, &str);
	}
	while (characters)
		creat(&numbers, &characters);
	return (numbers->data);
}
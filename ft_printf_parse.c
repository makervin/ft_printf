#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == '#')
		return (FFLAG_ALT);
	if (c == '0')
		return (FFLAG_ZERO);
	if (c == ' ')
		return (FFLAG_SPACE);
	if (c == '+')
		return (FFLAG_PLUS);
	if (c == '-')
		return (FFLAG_MINUS);
	return (0);
}

//	%[$][flags][width][.precision][length modifier]conversion
t_format	ft_parse_format(char **str, va_list *args)
{
	t_format	format;

	format.width = 0;
	format.flags = 0;
	format.precision = 0;

	while (is_flag(**str))
	{
		format.flags |= is_flag(**str);
		(*str)++;
	}
	if (**str >= '1' && **str <= '9')
	{
		format.width = **str - '0';
		(*str)++;
		while (ft_isdigit(**str))
		{
			format.width = format.width * 10 + **str - '0';
			(*str)++;
		}
	}
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			format.precision = va_arg(*args, int);
			(*str)++;
		}
		else
		{
			while (ft_isdigit(**str))
			{
				format.precision = format.precision * 10 + **str - '0';
				(*str)++;
			}
		}
	}
	format.specifier = **str;
	(*str)++;
	
	return (format);
}
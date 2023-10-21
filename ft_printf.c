#include "ft_printf.h"

static char	*parse_arg(char s, va_list *args)
{
	if (s == 'c')
		return (convert_char(va_arg(*args, int)));
	else if (s == 's')
		return (convert_str(va_arg(*args, char *)));
	else if (s == 'p')
		return (convert_ptr(va_arg(*args, void *)));
	else if (s == 'd' || s == 'i')
		return (convert_int(va_arg(*args, int)));
	else if (s == 'u')
		return (ft_utoa(va_arg(*args, unsigned int)));
	else if (s == 'x')
		return (ft_utoa_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (s == 'X')
		return (ft_utoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	char	*str;
	char	*procent;
	char	*arg;

	if (!format)
		return (-1);
	va_start(args, format);
	str = ft_strdup("");
	procent = ft_strchr(format, '%');
	while (procent != NULL)
	{
		str = ft_strjoin(str, ft_substr(format, 0, procent - format));
		
		arg = parse_arg(*(procent + 1), &args);
		if (arg)
			str = ft_strjoin(str, arg);

		format += procent - format + 2;
		procent = ft_strchr(format, '%');
	}
	str = ft_strjoin(str, format);
	len = write(1, str, ft_strlen(str));
	free(str);
	va_end(args);
	return (len);
}

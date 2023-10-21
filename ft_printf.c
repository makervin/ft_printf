#include "ft_printf.h"

// static int	parse_args(char s, va_list *args)
// {
// 	if (s == 'c')
// 		return (print_char(va_arg(*args, int)));
// 	else if (s == 's')
// 		return (print_str(va_arg(*args, char *)));
// 	else if (s == 'p')
// 		return (print_ptr(va_arg(*args, void *)));
// 	if (s == 'd' || s == 'i')
// 		return (print_int(va_arg(*args, int), "0123456789", 10));
// 	else if (s == 'u')
// 		return (print_uint(va_arg(*args, unsigned int), "0123456789", 10));
// 	else if (s == 'x')
// 		return (print_uint(
// 				va_arg(*args, unsigned int), "0123456789abcdef", 16));
// 	else if (s == 'X')
// 		return (print_uint(
// 				va_arg(*args, unsigned int), "0123456789ABCDEF", 16));
// 	return (print_char('%'));
// }

static char	*parse_arg(char s, va_list *args)
{
	if (s == 'c')
	{
		char	c[2] = { 0 };
		c[0] = va_arg(*args, int);
		return (ft_strdup(c));
	}
	else if (s == 's')
	{
		char *s = ft_strdup(va_arg(*args, char *));
		if (!s)
			return (ft_strdup("(null)"));
		return (s);
	}
	else if (s == 'p')
	{
		void	*ptr = va_arg(*args, void *);
		if (!ptr)
			return (ft_strdup("(nil)"));
		return (ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef")));
	}
	else if (s == 'd' || s == 'i')
		return (ft_itoa(va_arg(*args, int)));
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
	// while (*format)
	// {
	// 	if (*format == '%')
	// 		len += parse_args(*(++format), &args);
	// 	else
	// 		len += print_char(*format);
	// 	format++;
	// }
	len = write(1, str, ft_strlen(str));
	free(str);
	va_end(args);
	return (len);
}

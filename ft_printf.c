#include "ft_printf.h"

static char	*convert_format(t_format fmt, va_list *args)
{
	if (fmt.specifier == 'c')
		return (ft_convert_char(va_arg(*args, int)));
	else if (fmt.specifier == 's')
		return (ft_convert_str(va_arg(*args, char *)));
	else if (fmt.specifier == 'p')
		return (ft_convert_ptr(va_arg(*args, void *)));
	else if (fmt.specifier == 'd' || fmt.specifier == 'i')
		return (ft_convert_int(va_arg(*args, int)));
	else if (fmt.specifier == 'u')
		return (ft_utoa(va_arg(*args, unsigned int)));
	else if (fmt.specifier == 'x')
		return (ft_convert_hex(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == 'X')
		return (ft_utoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	char		*str;
	char		*procent;
	char		*arg;	
	t_format	fmt;

	if (!format)
		return (-1);
	va_start(args, format);
	str = ft_strdup("");
	procent = ft_strchr(format, '%');
	while (procent != NULL)
	{
		str = ft_strjoin(str, ft_substr(format, 0, procent - format));
		
		procent++;
		fmt = ft_parse_flags(&procent);	
		arg = convert_format(fmt, &args);
		if (arg)
			str = ft_strjoin(str, arg);

		format += procent - format;
		procent = ft_strchr(format, '%');
	}
	str = ft_strjoin(str, format);
	len = write(1, str, ft_strlen(str));
	free(str);
	va_end(args);
	return (len);
}

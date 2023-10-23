#include "ft_printf.h"

static char	*convert_arg(t_format fmt, va_list *args)
{
	if (fmt.specifier == 'c')
		return (ft_convert_char(va_arg(*args, int), fmt));
	else if (fmt.specifier == 's')
		return (ft_convert_str(va_arg(*args, char *), fmt));
	else if (fmt.specifier == 'p')
		return (ft_convert_ptr(va_arg(*args, void *), fmt));
	else if (fmt.specifier == 'd' || fmt.specifier == 'i')
		return (ft_convert_int(va_arg(*args, int), fmt));
	else if (fmt.specifier == 'u')
		return (ft_utoa(va_arg(*args, unsigned int)));
	else if (fmt.specifier == 'x')
		return (ft_convert_hex(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == 'X')
		return (ft_convert_uhex(va_arg(*args, unsigned int), fmt));
	return (NULL);
}

static int output_append(char *s1, char *s2)
{

}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	char		*str;
	char		*procent;
	char		*arg;
	char		*tmp;
	t_format	fmt;

	if (!format)
		return (-1);
	va_start(args, format);
	str = ft_strdup("");
	if (!str)
		return -1;
	procent = ft_strchr(format, '%');
	len = 0;
	while (procent != NULL)
	{
		tmp = ft_substr(format, 0, procent - format);
		if (!tmp)
			return (free(str), -1);
		str = ft_strnjoin_free(str, tmp, len, ft_strlen(tmp));
		len += procent - format;
		
		procent++;
		fmt = ft_parse_format(&procent, &args);	
		arg = convert_arg(fmt, &args);
		if (arg)
		{
			if (fmt.specifier == 'c')
			{
				str = ft_strnjoin(str, arg, len, 1);
				len += 1;
			}
			else
			{
				str = ft_strnjoin(str, arg, len, ft_strlen(arg));
				len += ft_strlen(arg);
			}
		}

		format += procent - format;
		procent = ft_strchr(format, '%');
	}
	str = ft_strnjoin(str, format, len, ft_strlen(format));
	len += ft_strlen(format);
	len = write(1, str, len);
	free(str);
	va_end(args);
	return (len);
}

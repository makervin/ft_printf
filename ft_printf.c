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
	else if (fmt.specifier == '%')
		return (ft_convert_char('%', fmt));
	return (NULL);
}

static int print_append_format(char **dst, const char *s2, size_t s1_len, size_t s2_len)
{
	char	*ret;

	ret = ft_strnjoin(*dst, s2, s1_len, s2_len);
	free(*dst);
	if (!ret)
		return (-1);
	*dst = ret;
	return (s2_len);
}

static int print_append_arg(char **dst, t_format fmt, char *arg, size_t s1_len)
{
	char	*ret;
	int		len;

	if (fmt.specifier == 'c')
	{
		if (fmt.width > 1)
			len = fmt.width;
		else
			len = 1;
	}
	else
		len = ft_strlen(arg);
	ret = ft_strnjoin(*dst, arg, s1_len, len);
	free(*dst);
	free(arg);
	if (!ret)
		return (-1);
	*dst = ret;
	return (len);
}

int	ft_vprintf(const char *format, va_list *ap)
{
	char	*output;
	char	*procent;
	int		len;

	t_format	fmt;
	output = ft_strdup("");
	if (!output)
		return -1;
	procent = ft_strchr(format, '%');
	len = 0;
	while (procent != NULL)
	{
		len += print_append_format(&output, format, len, procent - format);
		if (len < 0)
			return (-1);
		
		procent++;
		fmt = ft_parse_format(&procent, ap);	
		len += print_append_arg(&output, fmt, convert_arg(fmt, ap), len);

		format += procent - format;
		procent = ft_strchr(format, '%');
	}
	len += print_append_format(&output, format, len, ft_strlen(format));
	len = write(1, output, len);
	free(output);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = ft_vprintf(format, &ap);
	va_end(ap);
	return (len);
}

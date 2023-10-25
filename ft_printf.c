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
		return (ft_convert_uint(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == 'x')
		return (ft_convert_hex(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == 'X')
		return (ft_convert_uhex(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	*output_append_format(char *output, const char **format, size_t *len, size_t format_len)
{
	char	*ret;

	ret = ft_strnjoin(output, *format, *len, format_len);
	free(output);
	*format += format_len;
	*len += format_len;
	return (ret);
}

static char	*output_append_arg(char *output, char *arg, size_t *s1_len, t_format format)
{
	char	*ret;
	size_t	len;

	if (format.specifier == 'c')
	{
		if (format.width > 1)
			len = format.width;
		else
			len = 1;
	}
	else
		len = ft_strlen(arg);
	ret = ft_strnjoin(output, arg, *s1_len, len);
	free(output);
	free(arg);
	*s1_len += len;
	return (ret);
}

int	ft_vprintf(const char *format, va_list *ap)
{
	char		*output;
	char		*percent;
	char		*arg;
	t_format	arg_format;
	size_t		len;

	if (format == NULL)
		return (-1);
	output = ft_strdup("");
	if (output == NULL)
		return (-1);
	percent = ft_strchr(format, '%');
	len = 0;
	while (percent != NULL)
	{
		output = output_append_format(output, &format, &len, percent - format);
		if (output == NULL)
			return (-1);
		arg_format = ft_parse_format(&percent, ap);
		arg = convert_arg(arg_format, ap);
		if (arg == NULL)
		{
			free(output);
			return (-1);
		}
		output = output_append_arg(output, arg, &len, arg_format);
		format += percent - format;
		percent = ft_strchr(format, '%');
	}
	output = output_append_format(output, &format, &len, ft_strlen(format));
	if (output == NULL)
		return (-1);
	len = write(STDOUT_FILENO, output, len);
	free(output);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = ft_vprintf(format, &ap);
	va_end(ap);
	return (len);
}

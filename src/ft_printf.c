/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 11:17:42 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/26 11:17:42 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_output(char *output, size_t len)
{
	int	ret_len;

	if (output == NULL)
		return (-1);
	ret_len = write(STDOUT_FILENO, output, len);
	free(output);
	return (ret_len);
}

static char	*output_append_format(char *output, const char **format,
									size_t *len, size_t format_len)
{
	char	*ret;

	ret = ft_strnjoin(output, *format, *len, format_len);
	free(output);
	*format += format_len;
	*len += format_len;
	return (ret);
}

static char	*output_append_arg(char *output, char *arg,
								size_t *s1_len, t_format format)
{
	char	*ret;
	size_t	len;

	if (arg == NULL)
	{
		if (output)
			print_output(output, *s1_len);
		free(arg);
		return (NULL);
	}
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

int	ft_vprintf(const char *format, va_list ap)
{
	char		*output;
	char		*percent;
	char		*arg;
	t_format	arg_format;
	size_t		len;

	if (format == NULL)
		return (-1);
	output = ft_strdup("");
	percent = ft_strchr(format, '%');
	len = 0;
	while (percent != NULL)
	{
		output = output_append_format(output, &format, &len, percent - format);
		arg_format = ft_parse_format(&percent, ap);
		arg = ft_convert_arg(arg_format, ap);
		output = output_append_arg(output, arg, &len, arg_format);
		if (output == NULL)
			return (-1);
		format += percent - format;
		percent = ft_strchr(format, '%');
	}
	output = output_append_format(output, &format, &len, ft_strlen(format));
	return (print_output(output, len));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

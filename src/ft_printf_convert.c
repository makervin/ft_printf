#include "ft_printf.h"

char	*ft_convert_arg(t_format fmt, va_list *args)
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
		return (ft_convert_upperhex(va_arg(*args, unsigned int), fmt));
	else if (fmt.specifier == '%')
		return (ft_strdup("%"));
	return (NULL);
}

#include "ft_printf.h"

char	*convert_char(char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}

char	*convert_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*convert_ptr(void *ptr)
{
	if (!ptr)
		return (ft_strdup("(nil)"));
	return (ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef")));
}

char	*convert_int(int i)
{
	return (ft_itoa(i));
}
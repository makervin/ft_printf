#include "ft_printf.h"

char	*ft_convert_char(char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_strdup(str));
}

char	*ft_convert_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*ft_convert_ptr(void *ptr)
{
	if (!ptr)
		return (ft_strdup("(nil)"));
	return (ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef")));
}

char	*ft_convert_int(int i)
{
	return (ft_itoa(i));
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	if (fmt.flags )
	return (ft_utoa_base(i, "0123456789abcdef"));
}
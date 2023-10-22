#include "ft_printf.h"

char	*ft_convert_char(char c, t_format fmt)
{
	char	*ret;

	ret = ft_strdup(" ");
	ret[0] = c;
	ret = ft_create_paddding(ret, fmt, ' ');
	return (ret);
}

char	*ft_convert_str(char *str, t_format fmt)
{
	char	*ret;
	char	*padding;
	size_t	len;

	if (!str)
		return (ft_strdup("(null)"));
	ret = ft_create_paddding(str, fmt, ' ');
	return (ret);
}

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*ret;
	char	*padding;
	size_t	len;

	if (!ptr)
		ret = ft_strdup("(nil)");
	else
		ret = ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef"));
	ret = ft_create_paddding(ret, fmt, ' ');
	return (ret);
}

char	*ft_convert_int(int i, t_format fmt)
{
	char	*ret;
	char	*padding;
	size_t	len;

	ret = ft_itoa(i);
	if (fmt.flags & FFLAG_ZERO)
		ret = ft_create_paddding(ret, fmt, '0');
	else 
		ret = ft_create_paddding(ret, fmt, ' ');
	return (ret);
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	char	*ret;
	char	*padding;
	char	padding_char;
	size_t	len;

	if (fmt.specifier == 'X')
		ret = ft_utoa_base(i, "0123456789ABCDEF");
	else
		ret = ft_utoa_base(i, "0123456789abcdef");
	if (fmt.flags & FFLAG_ALT)
	{
		if (fmt.specifier == 'X')
			ret = ft_strjoin("0X", ret);
		else
			ret = ft_strjoin("0x", ret);
	}
	if (fmt.flags & FFLAG_ZERO)
		ret = ft_create_paddding(ret, fmt, '0');
	else 
		ret = ft_create_paddding(ret, fmt, ' ');
	return (ret);
}
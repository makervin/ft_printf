#include "ft_printf.h"

char	*ft_convert_char(char c, t_format fmt)
{
	char	*str;

	if (fmt.width <= 0)
		fmt.width = 1;
	str = (char *)ft_calloc(fmt.width + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (fmt.flags & FFLAG_MINUS)
	{
		str[0] = c;
		while (fmt.width-- > 1)
			str[fmt.width] = ' ';
	}
	else
	{
		str[--fmt.width] = c;
		while (--fmt.width >= 0)
			str[fmt.width] = ' ';
	}
	return (str);
}

char	*ft_convert_str(char *str, t_format fmt)
{
	size_t	len;
	char	*padding;
	char	*ret;

	if (!str)
		return (ft_strdup("(null)"));

	ret = ft_strdup(str);
	len = ft_strlen(ret);
	if (fmt.width > len)
	{
		len = fmt.width - len;
		padding = (char *)ft_calloc(len + 1, sizeof(char));	
		while (len--)
			padding[len] = ' ';
		if (fmt.flags & FFLAG_MINUS)
			ret = ft_strjoin(ret, padding);
		else
			ret = ft_strjoin(padding, ret);
	}
	return (ret);
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
	char	*str;

	str = ft_utoa_base(i, "0123456789abcdef");
	if (fmt.flags & FFLAG_ALT)
		return (ft_strjoin("0x", str));
	return (str);
}
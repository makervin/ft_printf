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
	char	*ret;
	char	*padding;
	size_t	len;

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

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*ret;
	char	*padding;
	size_t	len;

	if (!ptr)
		ret = ft_strdup("(nil)");
	else
		ret = ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef"));
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

char	*ft_convert_int(int i, t_format fmt)
{
	char	*ret;
	char	*padding;
	char	padding_char;
	size_t	len;

	ret = ft_itoa(i);
	len = ft_strlen(ret);
	if (fmt.width > len)
	{
		if (fmt.flags & FFLAG_ZERO)
			padding_char = '0';
		else
			padding_char = ' ';
		len = fmt.width - len;
		padding = (char *)ft_calloc(len + 1, sizeof(char));	
		while (len--)
			padding[len] = padding_char;
		if (fmt.flags & FFLAG_MINUS)
			ret = ft_strjoin(ret, padding);
		else
			ret = ft_strjoin(padding, ret);
	}
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
	len = ft_strlen(ret);
	if (fmt.width > len)
	{
		if (fmt.flags & FFLAG_ZERO)
			padding_char = '0';
		else
			padding_char = ' ';
		len = fmt.width - len;
		padding = (char *)ft_calloc(len + 1, sizeof(char));	
		while (len--)
			padding[len] = padding_char;
		if (fmt.flags & FFLAG_MINUS)
			ret = ft_strjoin(ret, padding);
		else
			ret = ft_strjoin(padding, ret);
	}
	return (ret);
}
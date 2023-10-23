#include "ft_printf.h"

char	*ft_apply_padding(char *str, t_format fmt)
{
	char	*padding;
	int		len;

	len = fmt.width - ft_strlen(str);
	if (len > 0)
	{
		padding = (char *)ft_calloc(len + 1, sizeof(char));
		while (len--)
			padding[len] = ' ';
		if (fmt.flags & FFLAG_MINUS)
			str = ft_strjoin(str, padding);
		else
			str = ft_strjoin(padding, str);
	}
	return (str);
}

char	*ft_apply_zero_padding(char *str, t_format fmt)
{
	char	*padding;
	int		len;

	len = fmt.width - ft_strlen(str);
	if (fmt.flags & FFLAG_SPACE || fmt.flags & FFLAG_PLUS)
		len--;
	if (len > 0)
	{
		padding = (char *)ft_calloc(len + 1, sizeof(char));
		while (len--)
			padding[len] = '0';
		str = ft_strjoin(padding, str);
	}
	return (str);
}

char	*ft_apply_sign(char *str, int negative, t_format fmt)
{
	char	*ret;

	if (negative)
	{
		ret = ft_strjoin("-", str);
		free(str);
	}
	else 
	{
		ret = str;
		if (fmt.flags & FFLAG_PLUS)
			ret = ft_strjoin("+", str);
		else if (fmt.flags & FFLAG_SPACE)
			ret = ft_strjoin(" ", str);
	}
	return (ret);
}

char	*ft_apply_precision(char *str, t_format fmt)
{
	char	*padding;
	int		len;

	len = fmt.precision - ft_strlen(str);
	if (fmt.flags & FFLAG_SPACE || fmt.flags & FFLAG_PLUS)
		len--;
	if (len > 0)
	{
		padding = (char *)ft_calloc(len + 1, sizeof(char));
		while (len--)
			padding[len] = '0';
		str = ft_strjoin(padding, str);
	}
	return (str);
}
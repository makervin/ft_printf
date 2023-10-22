#include "ft_printf.h"

char	*ft_create_paddding(char *str, t_format fmt)
{
	char	*padding;
	size_t	len;
	char	*ret;
	char	c;

	len = ft_strlen(str);
	ret = str;
	if (fmt.width <= len)
		return (ret);
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
		c = '0';
	else
		c = ' ';
	len = fmt.width - len;
	padding = (char *)ft_calloc(len + 1, sizeof(char));	
	if (!padding)
		return (NULL);
	while (len--)
		padding[len] = c;
	if (fmt.flags & FFLAG_MINUS)
		ret = ft_strjoin(str, padding);
	else
		ret = ft_strjoin(padding, str);
	return (ret);
}

char	*ft_add_precision(char *str, t_format fmt)
{
	char	*padding;
	size_t	len;
	char	*ret;
	char	c;

	len = ft_strlen(str);
	ret = str;
	if (fmt.width > len)
	{
		len = fmt.width - len;
		padding = (char *)ft_calloc(len + 1, sizeof(char));	
		if (!padding)
			return (NULL);
		while (len--)
			padding[len] = '0';
		ret = ft_strjoin(padding, str);
	}
	return (ret);
}
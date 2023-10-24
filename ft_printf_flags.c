#include "ft_printf.h"

char	*ft_apply_padding(char *str, int width, int minus)
{
	char	*padding;
	char	*ret;
	int		len;

	len = width - ft_strlen(str);
	if (len <= 0)
		return (str);
	padding = (char *)ft_calloc(len + 1, sizeof(char));
	if (!padding)
		return (NULL);
	while (len--)
		padding[len] = ' ';
	if (minus)
		ret = ft_strjoin(str, padding);
	else
		ret = ft_strjoin(padding, str);
	free(str);
	free(padding);
	return (ret);
}

char	*ft_apply_zero_padding(char *str, int width, int flags)
{
	char	*ret;
	char	*padding;
	int		len;

	len = width - ft_strlen(str);
	if (flags & FFLAG_SPACE || flags & FFLAG_PLUS)
		len--;
	if (len <= 0)
		return (str);
	padding = (char *)ft_calloc(len + 1, sizeof(char));
	while (len--)
		padding[len] = '0';
	ret = ft_strjoin(padding, str);
	free(str);
	free(padding);
	return (ret);
}

char	*ft_apply_sign(char *str, int negative, t_format fmt)
{
	char	*ret;

	if (negative)
	{
		ret = ft_strjoin("-", str);
		free(str);
		return (ret);
	}
	if (fmt.flags & FFLAG_PLUS)
		ret = ft_strjoin("+", str);
	else if (fmt.flags & FFLAG_SPACE)
		ret = ft_strjoin(" ", str);
	else
		return (str);
	free(str);
	return (ret);
}

char	*ft_apply_precision(char *str, t_format fmt)
{
	char	*padding;
	char	*ret;
	int		len;

	len = fmt.precision - ft_strlen(str);
	if (fmt.flags & FFLAG_SPACE || fmt.flags & FFLAG_PLUS)
		len--;
	if (len <= 0)
		return (str);
	padding = (char *)ft_calloc(len + 1, sizeof(char));
	while (len--)
		padding[len] = '0';
	ret = ft_strjoin(padding, str);
	free(str);
	free(padding);
	return (ret);
}
#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == '#')
		return (FFLAG_ALT);
	if (c == '0')
		return (FFLAG_ZERO);
	if (c == ' ')
		return (FFLAG_SPACE);
	if (c == '+')
		return (FFLAG_PLUS);
	if (c == '-')
		return (FFLAG_MINUS);
	return (0);
}

t_format	ft_parse_flags(char **str)
{
	t_format	format;

	format.width = 0;
	format.flags = 0;

	while (is_flag(**str))
	{
		format.flags |= is_flag(**str);
		(*str)++;
	}
	if (**str >= '1' && **str <= '9')
	{
		format.width = **str - '0';
		(*str)++;
		while (ft_isdigit(**str))
		{
			format.width = format.width * 10 + **str - '0';
			(*str)++;
		}
	}
	format.specifier = **str;
	(*str)++;
	
	return (format);
}

char	*ft_create_paddding(char *str, t_format fmt, char c)
{
	char	*padding;
	size_t	len;
	char	*ret;

	len = ft_strlen(str);
	ret = str;
	if (fmt.width > len)
	{
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
	}
	return (ret);
}
#include "ft_printf.h"

char	*ft_convert_char(char c, t_format fmt)
{
	char	*ret;

	ret = ft_strdup(" ");
	ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	if (fmt.flags & FFLAG_MINUS)
		ret[0] = c;
	else
		ret[ft_strlen(ret) - 1] = c;
	return (ret);
}
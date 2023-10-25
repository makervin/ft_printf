#include "ft_printf.h"

char	*ft_convert_str(char *str, t_format fmt)
{
	if (str == NULL)
	{
		if (fmt.precision > -1 && fmt.precision < 6)
		{
			str = ft_strdup("");
			str = ft_apply_padding(str, fmt.width, fmt.flags & FFLAG_MINUS);
			return (str);
		}
		str = ft_strdup("(null)");
	}
	else
		str = (ft_strdup(str));
	str = ft_apply_str_precision(str, fmt);
	str = ft_apply_padding(str, fmt.width, fmt.flags & FFLAG_MINUS);
	return (str);
}
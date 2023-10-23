#include "ft_printf.h"

char	*ft_convert_char(char c, t_format fmt)
{
	char	*ret;

	ret = ft_strdup(" ");
	ret[0] = c;
	ret = ft_apply_padding(ret, fmt);
	return (ret);
}

char	*ft_convert_str(char *str, t_format fmt)
{
	char	*ret;

	ret = str;
	if (!ret)
		ret = (ft_strdup("(null)"));
	ret = ft_apply_padding(ret, fmt);
	return (ret);
}

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*ret;

	if (!ptr)
		ret = ft_strdup("(nil)");
	else
		ret = ft_strjoin("0x", ft_ultoa_base((unsigned long)ptr, "0123456789abcdef"));
	ret = ft_apply_padding(ret, fmt);
	return (ret);
}

char	*ft_convert_int(int i, t_format fmt)
{
	char	*ret;

	ret = ft_utoa(ft_abs(i));
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
	{
		if (i < 0)
			fmt.width -= 1;
		ret = ft_apply_zero_padding(ret, fmt);
		ret = ft_apply_sign(ret, i < 0, fmt);
	}
	else 
	{
		ret = ft_apply_sign(ret, i < 0, fmt);
		ret = ft_apply_padding(ret, fmt);
	}
	return (ret);
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	char	*ret;

	if (fmt.specifier == 'X')
		ret = ft_utoa_base(i, "0123456789ABCDEF");
	else
		ret = ft_utoa_base(i, "0123456789abcdef");
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
	{
		if (fmt.flags & FFLAG_ALT)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt);
		if (fmt.flags & FFLAG_ALT)
			ret = ft_strjoin("0x", ret);
	}
	else 
	{
		if (fmt.flags & FFLAG_ALT)
			ret = ft_strjoin("0x", ret);
		ret = ft_apply_padding(ret, fmt);
	}
	return (ret);
}
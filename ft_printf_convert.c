#include "ft_printf.h"

char	*ft_convert_char(char c, t_format fmt)
{
	char	*ret;
	int		padding_len;

	ret = ft_strdup(" ");
	padding_len = fmt.width - 1;
	if (padding_len > 0)
		ret = ft_apply_padding(ret, padding_len, fmt.flags & FFLAG_MINUS);
	if (fmt.flags & FFLAG_MINUS)
		ret[0] = c;
	else
		ret[padding_len] = c;
		
	return (ret);
}

char	*ft_convert_str(char *str, t_format fmt)
{
	int	padding_len;

	if (str == NULL)
		str = (ft_strdup("(null)"));
	else
		str = (ft_strdup(str));
	padding_len = fmt.width - ft_strlen(str);
	if (padding_len > 0)
		str = ft_apply_padding(str, padding_len, fmt.flags & FFLAG_MINUS);
	return (str);
}

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*tmp;
	int		padding_len;

	if (ptr == NULL)
		ptr = ft_strdup("(nil)");
	else
	{
		tmp = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef");
		ptr = ft_strjoin("0x", tmp);
		free(tmp);
	}
	padding_len = fmt.width - ft_strlen(ptr);
	if (padding_len > 0)
		ptr = ft_apply_padding(ptr, padding_len, fmt.flags & FFLAG_MINUS);
	return (ptr);
}

char	*ft_convert_int(int i, t_format fmt)
{
	char	*ret;

	ret = ft_utoa(ft_abs(i));
	ret = ft_apply_precision(ret, fmt);
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS && fmt.precision == 0)
	{
		if (i < 0)
			fmt.width -= 1;
		ret = ft_apply_zero_padding(ret, fmt);
		ret = ft_apply_sign(ret, i < 0, fmt);
	}
	else 
	{
		ret = ft_apply_sign(ret, i < 0, fmt);
		// ret = ft_apply_padding(ret, fmt);
	}
	return (ret);
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	char	*ret;

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
		// ret = ft_apply_padding(ret, fmt);
	}
	return (ret);
}

char	*ft_convert_uhex(unsigned int i, t_format fmt)
{
	char	*ret;

	ret = ft_utoa_base(i, "0123456789ABCDEF");
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
	{
		if (fmt.flags & FFLAG_ALT)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt);
		if (fmt.flags & FFLAG_ALT)
			ret = ft_strjoin("0X", ret);
	}
	else 
	{
		if (fmt.flags & FFLAG_ALT)
			ret = ft_strjoin("0X", ret);
		// ret = ft_apply_padding(ret, fmt);
	}
	return (ret);
}
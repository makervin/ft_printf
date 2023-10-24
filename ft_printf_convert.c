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

char	*ft_convert_str(char *str, t_format fmt)
{
	if (str == NULL)
		str = (ft_strdup("(null)"));
	else
		str = (ft_strdup(str));
	str = ft_apply_padding(str, fmt.width, fmt.flags & FFLAG_MINUS);
	return (str);
}

char	*ft_convert_ptr(void *ptr, t_format fmt)
{
	char	*tmp;

	if (ptr == NULL)
		ptr = ft_strdup("(nil)");
	else
	{
		tmp = ft_ultoa_base((unsigned long)ptr, "0123456789abcdef");
		ptr = ft_strjoin("0x", tmp);
		free(tmp);
	}
	ptr = ft_apply_padding(ptr, fmt.width, fmt.flags & FFLAG_MINUS);
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
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
		ret = ft_apply_sign(ret, i < 0, fmt);
	}
	else 
	{
		ret = ft_apply_sign(ret, i < 0, fmt);
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	}
	return (ret);
}

char	*ft_convert_uint(unsigned int i, t_format fmt)
{
	char	*ret;

	ret = ft_utoa(i);
	ret = ft_apply_precision(ret, fmt);
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS && fmt.precision == 0)
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
	else
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	return (ret);
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	char	*ret;
	char	*tmp;

	ret = ft_utoa_base(i, "0123456789abcdef");
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
		if (fmt.flags & FFLAG_ALT && i > 0)
		{
			tmp = ret;
			ret = ft_strjoin("0x", ret);
			free(tmp);
		}
	}
	else 
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
		{
			tmp = ret;
			ret = ft_strjoin("0x", ret);
			free(tmp);
		}
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	}
	return (ret);
}

char	*ft_convert_uhex(unsigned int i, t_format fmt)
{
	char	*ret;
	char	*tmp;

	ret = ft_utoa_base(i, "0123456789ABCDEF");
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS)
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
		if (fmt.flags & FFLAG_ALT && i > 0)
		{
			tmp = ret;
			ret = ft_strjoin("0X", ret);
			free(tmp);
		}
	}
	else 
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
		{
			tmp = ret;
			ret = ft_strjoin("0X", ret);
			free(tmp);
		}
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	}
	return (ret);
}
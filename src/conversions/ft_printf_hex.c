/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/26 11:18:05 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/26 11:18:05 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *apply_alt(char *str, int uppercase)
{
	char	*ret;

	if (uppercase)
		ret = ft_strjoin("0X", str);
	else 
		ret = ft_strjoin("0x", str);
	free(str);
	return (ret);	
}

char	*ft_convert_hex(unsigned int i, t_format fmt)
{
	char	*ret;

	if (i == 0 && fmt.precision == 0)
	{
		ret = ft_strdup("");
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
		return (ret);
	}
	ret = ft_utoa_base(i, "0123456789abcdef");
	ret = ft_apply_precision(ret, fmt);
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS && fmt.precision == -1)
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
		if (fmt.flags & FFLAG_ALT && i > 0)
			ret = apply_alt(ret, 0);
	}
	else
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
			ret = (apply_alt(ret,  0));
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	}
	return (ret);
}

char	*ft_convert_upperhex(unsigned int i, t_format fmt)
{
	char	*ret;

	if (i == 0 && fmt.precision == 0)
	{
		ret = ft_strdup("");
		ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
		return (ret);
	}
	ret = ft_utoa_base(i, "0123456789ABCDEF");
	ret = ft_apply_precision(ret, fmt);
	if (fmt.flags & FFLAG_ZERO && ~fmt.flags & FFLAG_MINUS && fmt.precision == -1)
	{
		if (fmt.flags & FFLAG_ALT && i > 0)
			fmt.width -= 2;
		ret = ft_apply_zero_padding(ret, fmt.width, fmt.flags);
		if (fmt.flags & FFLAG_ALT && i > 0)
			ret = apply_alt(ret, 1); 
		return (ret);
	}
	if (fmt.flags & FFLAG_ALT && i > 0)
		ret = apply_alt(ret, 1);
	ret = ft_apply_padding(ret, fmt.width, fmt.flags & FFLAG_MINUS);
	return (ret);
}

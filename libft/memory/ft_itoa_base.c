/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int num, char *base)
{
	char	*tmp;
	char	*ret;

	if (num < 0)
	{
		tmp = ft_utoa_base(-num, base);
		ret = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
		ret = ft_utoa_base(num, base);
	return (ret);
}

// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n%x\n\n", ft_itoa_base(0, "0123456789abcdef"), 0);
// 	printf("%s\n%x\n\n", ft_itoa_base(5, "0123456789abcdef"), 5);
// 	printf("%s\n%x\n\n", ft_itoa_base(25, "0123456789abcdef"), 25);
// 	printf("%s\n%x\n\n", ft_itoa_base(234, "0123456789abcdef"), 234);
// 	printf("%s\n%x\n\n", ft_itoa_base(62321, "0123456789abcdef"), 62321);
// 	printf("%s\n%x\n\n", ft_itoa_base(INT_MAX, "0123456789abcdef"), INT_MAX);

// 	printf("%s\n%x\n\n", ft_itoa_base(-0, "0123456789abcdef"), -0);
// 	printf("%s\n%x\n\n", ft_itoa_base(-5, "0123456789abcdef"), -5);
// 	printf("%s\n%x\n\n", ft_itoa_base(-25, "0123456789abcdef"), -25);
// 	printf("%s\n%x\n\n", ft_itoa_base(-234, "0123456789abcdef"), -234);
// 	printf("%s\n%x\n\n", ft_itoa_base(INT_MIN, "0123456789abcdef"), INT_MIN);
// }
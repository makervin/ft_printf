/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int num, char *base)
{
	return (ft_ultoa_base(num, base));
}

// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n%x\n\n", ft_utoa_base(0, "0123456789abcdef"), 0);
// 	printf("%s\n%x\n\n", ft_utoa_base(5, "0123456789abcdef"), 5);
// 	printf("%s\n%x\n\n", ft_utoa_base(25, "0123456789abcdef"), 25);
// 	printf("%s\n%x\n\n", ft_utoa_base(234, "0123456789abcdef"), 234);
// 	printf("%s\n%x\n\n", ft_utoa_base(62321, "0123456789abcdef"), 62321);
// 	printf("%s\n%x\n\n", ft_utoa_base(UINT_MAX, "0123456789abcdef"), UINT_MAX);
// 	printf("%s\n", ft_utoa_base(254, "01"));
// }
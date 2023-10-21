/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:01 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 15:39:24 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char	*tmp;
	char	*ret;

	if (num < 0)
	{
		tmp = ft_utoa(-num);
		ret = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
		ret = ft_utoa(num);
	return (ret);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(5));
// 	printf("%s\n", ft_itoa(25));
// 	printf("%s\n", ft_itoa(234));
// 	printf("%s\n\n", ft_itoa(INT_MAX));

// 	printf("%s\n", ft_itoa(-0));
// 	printf("%s\n", ft_itoa(-5));
// 	printf("%s\n", ft_itoa(-25));
// 	printf("%s\n", ft_itoa(-234));
// 	printf("%s\n", ft_itoa(INT_MIN));
// }
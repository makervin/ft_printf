/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:48 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:20:59 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		return (ft_putchar_fd('-', fd) + ft_putunbr_fd((unsigned int)-n, fd));
	}
	return (ft_putunbr_fd((unsigned int)n, fd));
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	i;

// 	i = ft_putnbr_fd(4, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(25, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(358, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(1242564, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(INT_MAX, 1);
// 	printf(": %d\n\n", i);
// 	i = ft_putnbr_fd(-4, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(-25, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(-358, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(-1242564, 1);
// 	printf(": %d\n", i);
// 	i = ft_putnbr_fd(INT_MIN, 1);
// 	printf(": %d\n", i);
// 	return (0);
// }
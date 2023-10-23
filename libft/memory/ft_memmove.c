/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 17:37:49 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:32:32 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	int				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d && d - s < (int)n)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(d, src, n);
	return (dest);
}

// #include <string.h>

// int main()
// {
// 	char str[] = "hello, world!";
// 	char str_1[] = "test";
// 	ft_memmove(str, str+2, 6);
// 	printf("%s\n", str);

// 	char str2[] = "hello, world!";
// 	char str_2[] = "test";
// 	memmove(str2, str2+2, 6);
// 	printf("%s\n", str2);
// 	return 0;
// }
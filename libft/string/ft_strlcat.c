/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:43:11 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 16:32:45 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	int			d_len;
	int			n;

	d = dst;
	s = src;
	n = size;
	while (n-- && *d)
		d++;
	d_len = d - dst;
	n = size - d_len;
	if (n == 0)
		return (d_len + ft_strlen(src));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}

// #include <stdio.h>
// #include <bsd/string.h>

// int main()
// {
// 	char dst[10] = "a";
// 	printf("%lu\n", ft_strlcat(dst, "lorem ipsum dolor sit amet", 0));
// 	char dst2[10] = "a";
// 	printf("%lu\n", strlcat(dst2, "lorem ipsum dolor sit amet", 1));

// 	return 0;
// }
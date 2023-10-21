/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 14:45:29 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/03 14:52:33 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;

	if (size && (nmemb * size) / size != nmemb)
		return (NULL);
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	ft_bzero(new, nmemb * size);
	return (new);
}

// #include <stdio.h>

// int main()
// {
// 	void *ft_res = ft_calloc(-5, -5);
// 	void *std_res = calloc(-5, -5);
// 	printf("%p\n", ft_res);
// 	printf("%p\n", std_res);
// 	return 0;
// }
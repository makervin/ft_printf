/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 16:03:43 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/23 16:03:43 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnjoin_free(char *s1, char *s2, size_t s1_n, size_t s2_n)
{
	char	*res;

	res = ft_strnjoin(s1, s2, s1_n, s2_n);
	free(s1);
	free(s2);
	return (res);
}
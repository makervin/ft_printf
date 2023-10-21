/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_ctype.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vockers <vockers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 18:59:29 by vockers       #+#    #+#                 */
/*   Updated: 2023/10/19 18:59:29 by vockers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

enum
{
	LIBFT_IS_ALNUM	= 8,
	LIBFT_IS_ALPHA	= 1024,
	LIBFT_IS_DIGIT	= 2048,
	LIBFT_IS_PRINT	= 16384
};

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

#include "libft/libft.h"

typedef enum	e_fflags
{
	FFLAG_ALT	= 1 << 0,
	FFLAG_ZERO	= 1 << 1,
	FFLAG_SPACE	= 1 << 2,
	FFLAG_PLUS	= 1 << 3,
	FFLAG_MINUS	= 1 << 4,
}				t_fflags;

typedef struct	s_format
{
	char		specifier;
	int			width;
	t_fflags	flags;
}				t_format;

int			ft_printf(const char *format, ...);

t_format	ft_parse_flags(char **str);

char		*ft_convert_char(char c, t_format fmt);
char		*ft_convert_str(char *str, t_format fmt);
char		*ft_convert_ptr(void *ptr);
char		*ft_convert_int(int i);
char		*ft_convert_hex(unsigned int i, t_format fmt);

#endif
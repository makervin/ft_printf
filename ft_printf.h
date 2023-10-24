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
	int			precision;
	t_fflags	flags;
}				t_format;

int			ft_printf(const char *format, ...);

char		*ft_strnjoin_free(char *s1, char *s2, size_t s1_n, size_t s2_n);

t_format	ft_parse_format(char **str, va_list *args);

char		*ft_apply_padding(char *str, int width, int minus);
char		*ft_apply_zero_padding(char *str, int width, int flags);
char		*ft_apply_sign(char *str, int negative, t_format fmt);
char		*ft_apply_precision(char *str, t_format fmt);
char		*ft_apply_str_precision(char *str, t_format fmt);


char		*ft_convert_char(char c, t_format fmt);
char		*ft_convert_str(char *str, t_format fmt);
char		*ft_convert_ptr(void *ptr, t_format fmt);
char		*ft_convert_int(int i, t_format fmt);
char		*ft_convert_uint(unsigned int i, t_format fmt);
char		*ft_convert_hex(unsigned int i, t_format fmt);
char		*ft_convert_uhex(unsigned int i, t_format fmt);

#endif
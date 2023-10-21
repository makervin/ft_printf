#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

#include "libft/libft.h"

int	ft_printf(const char *format, ...);

char	*convert_char(char c);
char	*convert_str(char *str);
char	*convert_ptr(void *ptr);
char	*convert_int(int i);

#endif
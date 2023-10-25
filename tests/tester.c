#include <stdarg.h>
#include <stdio.h>

#include "tester.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void	test_printf(const char *format, ...)
{
	va_list		ap;
	int			ft_len;
	int			std_len;

	puts(format);

	va_start(ap, format);
	ft_printf("42  :");
	ft_len = ft_vprintf(format, &ap);
	va_end(ap);

	printf("\n");

	va_start(ap, format);
	printf("std :");
	std_len = vprintf(format, ap);
	va_end(ap);
	
	if (ft_len != std_len)
		printf("\n" ANSI_COLOR_RED "KO" ANSI_COLOR_RESET ": ft_len: %d | std_len: %d", ft_len, std_len);
	printf("\n\n");
}
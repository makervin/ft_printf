#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	// ft_printf("test % hello %c | %s world %d | %u\n", 't', "arg_s", INT_MAX, UINT_MAX);
	char	*ptr = "hello, world";
	ft_printf	("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	printf		("\n\n");
	printf		("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	// printf("test % hello % world\n");
}
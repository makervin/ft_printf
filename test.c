#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	// ft_printf	("test % hello %c | %s world %d | %u\n", 't', "arg_s", INT_MAX, UINT_MAX);
	// printf		("test % hello %c | %s world %d | %u\n", 't', "arg_s", INT_MAX, UINT_MAX);
	
	// char	*ptr = "hello, world";
	// ft_printf	("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	// printf		("\n\n");
	// printf		("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	
	// ft_printf	("%x\n%#x\n", 255, 255);
	// printf		("%x\n%#x\n", 255, 255);
	
	ft_printf	("lft\t:%c\n", 'a');
	printf		("std\t:%c\n", 'a');
	printf		("\n");
	ft_printf	("lft\t:%-c\n", 'a');
	printf		("std\t:%-c\n", 'a');
	printf		("\n");
	ft_printf	("lft\t:%5c\n", 'a');
	printf		("std\t:%5c\n", 'a');
	printf		("\n");
	ft_printf	("lft\t:%-5cH\n", 'a');
	printf		("std\t:%-5cH\n", 'a');

	// printf		("\n\n");
	
	// ft_printf	("lft\t:%s\n", "hello");
	// printf		("std\t:%s\n", "hello");
	// printf		("\n");
	// ft_printf	("lft\t:%5s\n", "hello");
	// printf		("std\t:%5s\n", "hello");
	// printf		("\n");
	// ft_printf	("lft\t:%10s\n", "hello");
	// printf		("std\t:%10s\n", "hello");
	// printf		("\n");
	// ft_printf	("lft\t:%-10sH\n", "hello");
	// printf		("std\t:%-10sH\n", "hello");
}
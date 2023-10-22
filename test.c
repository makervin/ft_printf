#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	char	*ptr	= "hello, world";
	int 	i 		= 42;
	// ft_printf	("test % hello %c | %s world %d | %u\n", 't', "arg_s", INT_MAX, UINT_MAX);
	// printf		("test % hello %c | %s world %d | %u\n", 't', "arg_s", INT_MAX, UINT_MAX);
	
	// ft_printf	("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	// printf		("\n\n");
	// printf		("c:\t%c\ns:\t%s\ns2:\t%s\np:\t%p\np2:\t%p\nd:\t%d\ni:\t%i\nu:\t%u\nx:\t%x\nX:\t%X\n", 't', ptr, NULL, ptr, NULL, INT_MAX, INT_MIN, UINT_MAX, 255, 255);
	
	// ft_printf	("%x\n%#x\n", 255, 255);
	// printf		("%x\n%#x\n", 255, 255);
	
	// ft_printf	("lft\t:%c\n", 'a');
	// printf		("std\t:%c\n", 'a');
	// printf		("\n");
	// ft_printf	("lft\t:%-c\n", 'a');
	// printf		("std\t:%-c\n", 'a');
	// printf		("\n");
	// ft_printf	("lft\t:%5c\n", 'a');
	// printf		("std\t:%5c\n", 'a');
	// printf		("\n");
	// ft_printf	("lft\t:%-5cH\n", 'a');
	// printf		("std\t:%-5cH\n", 'a');

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
	
	// printf		("\n\n");
	
	// ft_printf	("lft\t:%d\n", i);
	// printf		("std\t:%d\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%2d\n", i);
	// printf		("std\t:%2d\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%5d\n", i);
	// printf		("std\t:%5d\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%05d\n", i);
	// printf		("std\t:%05d\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%-10dH\n", i);
	// printf		("std\t:%-10dH\n", i);
	
	// printf		("\n\n");
	
	// ft_printf	("lft\t:%p\n", ptr);
	// printf		("std\t:%p\n", ptr);
	// printf		("\n");
	// ft_printf	("lft\t:%5p\n", ptr);
	// printf		("std\t:%5p\n", ptr);
	// printf		("\n");
	// ft_printf	("lft\t:%20p\n", ptr);
	// printf		("std\t:%20p\n", ptr);
	// printf		("\n");
	// ft_printf	("lft\t:%-20pH\n", ptr);
	// printf		("std\t:%-20pH\n", ptr);
	// printf		("\n");
	// ft_printf	("lft\t:%20p\n", NULL);
	// printf		("std\t:%20p\n", NULL);

	// printf		("\n\n");
	
	ft_printf	("lft\t:%#x\n", 255);
	printf		("std\t:%#x\n", 255);
	printf		("\n");
	ft_printf	("lft\t:%x\n", i);
	printf		("std\t:%x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%2x\n", i);
	printf		("std\t:%2x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%5x\n", i);
	printf		("std\t:%5x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%05x\n", i);
	printf		("std\t:%05x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%#5x\n", i);
	printf		("std\t:%#5x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%#010x\n", i);
	printf		("std\t:%#010x\n", i);
	printf		("\n");
	ft_printf	("lft\t:%-10xH\n", i);
	printf		("std\t:%-10xH\n", i);

	// printf		("\n\n");
	
	// ft_printf	("lft\t:%#X\n", 255);
	// printf		("std\t:%#X\n", 255);
	// printf		("\n");
	// ft_printf	("lft\t:%X\n", i);
	// printf		("std\t:%X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%2X\n", i);
	// printf		("std\t:%2X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%5X\n", i);
	// printf		("std\t:%5X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%05X\n", i);
	// printf		("std\t:%05X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%#5X\n", i);
	// printf		("std\t:%#5X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%#010X\n", i);
	// printf		("std\t:%#010X\n", i);
	// printf		("\n");
	// ft_printf	("lft\t:%-10XH\n", i);
	// printf		("std\t:%-10XH\n", i);
}
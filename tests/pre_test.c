#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	int i;
	i = ft_printf	("lft\t:%.1s", "hello");
	printf(" | %d\n", i);
	i = printf		("std\t:%.1s", "hello");
	printf(" | %d\n", i);
	printf("\n");
	i = ft_printf	("lft\t:%.1d", 255);
	printf(" | %d\n", i);
	i = printf		("std\t:%.1d", 255);
	printf(" | %d\n", i);
	printf("\n");
	i = ft_printf	("lft\t:%010.5d", 255);
	printf(" | %d\n", i);
	i = printf		("std\t:%010.5d", 255);
	printf(" | %d\n", i);
	printf("\n");
	i = ft_printf	("lft\t:%010.5x", 255);
	printf(" | %d\n", i);
	i = printf		("std\t:%010.5x", 255);
	printf(" | %d\n", i);
	printf("\n");
	i = ft_printf	("lft\t:%010.x", 255);
	printf(" | %d\n", i);
	i = printf		("std\t:%010.x", 255);
	printf(" | %d\n", i);
	printf("\n");
}
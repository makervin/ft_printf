#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	int i;

	i = ft_printf	("lft\t:%c hello", 'a');
	printf			(" | %d\n", i);
	i = printf		("std\t:%c hello", 'a');
	printf			(" | %d\n", i);
	printf		("\n");
	i = ft_printf	("lft\t:%c", 0);
	printf			(" | %d\n", i);
	i = printf		("std\t:%c", 0);
	printf			(" | %d\n", i);
	printf		("\n");
	ft_printf	("lft\t:%-c\n", 'a');
	printf		("std\t:%-c\n", 'a');
	printf		("\n");
	ft_printf	("lft\t:%5c\n", 'a');
	printf		("std\t:%5c\n", 'a');
	printf		("\n");
	ft_printf	("lft\t:%-5cH\n", 'a');
	printf		("std\t:%-5cH\n", 'a');
}
#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
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
}
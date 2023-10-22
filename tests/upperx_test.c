#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	int	i = 42;

	ft_printf	("lft\t:%#X\n", 255);
	printf		("std\t:%#X\n", 255);
	printf		("\n");
	ft_printf	("lft\t:%X\n", i);
	printf		("std\t:%X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%2X\n", i);
	printf		("std\t:%2X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%5X\n", i);
	printf		("std\t:%5X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%05X\n", i);
	printf		("std\t:%05X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%#5X\n", i);
	printf		("std\t:%#5X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%#010X\n", i);
	printf		("std\t:%#010X\n", i);
	printf		("\n");
	ft_printf	("lft\t:%-10XH\n", i);
	printf		("std\t:%-10XH\n", i);
}
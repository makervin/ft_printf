#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	int	i = 42;

	ft_printf	("lft\t:%#x\n", 1);
	printf		("std\t:%#x\n", 1);
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
}
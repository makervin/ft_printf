#include <stdio.h>
#include <limits.h>

#include "ft_printf.h"

int main()
{
	int	i = 42;

	ft_printf	("lft\t:%d\n", i);
	printf		("std\t:%d\n", i);
	printf		("\n");
	ft_printf	("lft\t:%2d\n", -i);
	printf		("std\t:%2d\n", -i);
	printf		("\n");
	ft_printf	("lft\t:%5d\n", i);
	printf		("std\t:%5d\n", i);
	printf		("\n");
	ft_printf	("lft\t:%05d\n", i);
	printf		("std\t:%05d\n", i);
	printf		("\n");
	ft_printf	("lft\t:%05d\n", -i);
	printf		("std\t:%05d\n", -i);
	printf		("\n");
	ft_printf	("lft\t:%-05dH\n", i);
	printf		("std\t:%-05dH\n", i);
	printf		("\n");
	ft_printf	("lft\t:%-10dH\n", i);
	printf		("std\t:%-10dH\n", i);
	printf		("\n");
	ft_printf	("lft\t:%+ 5d\n", i);
	printf		("std\t:%+ 5d\n", i);
	printf		("\n");
	ft_printf	("lft\t:% d\n", i);
	printf		("std\t:% d\n", i);
	printf		("\n");
	ft_printf	("lft: '+ d'\t:%+ d\n", i);
	printf		("std: '+ d'\t:%+ d\n", i);
	printf		("\n");
	ft_printf	("lft: ' 05d'\t:% 05d\n", i);
	printf		("std: ' 05d'\t:% 05d\n", i);
	printf		("\n");
	ft_printf	("lft: '5d'\t:%5d\n", -i);
	printf		("std: '5d'\t:%5d\n", -i);
	printf		("\n");
	ft_printf	("lft: '.5d'\t:%.5d\n", -i);
	printf		("std: '.5d'\t:%.5d\n", -i);
	printf		("\n");
	ft_printf	("lft: '10.5d'\t:%10.5d\n", -i);
	printf		("std: '10.5d'\t:%10.5d\n", -i);
}	